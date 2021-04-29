#include <bits.h>
int size = 0;
struct node {
    struct node *next, *prev;
    int x;
};

struct node* New(){
    size++;
    struct node *v;
    v = malloc(sizeof(struct node) * 1);
    v -> x = malloc(sizeof(char) * 100);
    v -> next = NULL;
    v -> prev = NULL;
    return v;
}

struct node *head,*tail;
void push_l(int x) {
    if(size == 0)
    {
        head = tail = New();
        tail -> x = x;
        head -> x = x;
        return;
    }
    struct node *p = head;
    head -> next = New();
    head = head -> next;
    head -> prev = p;
    head -> x = x;
}

void push_r(int x) {
    if(size == 0)
    {
        head = tail = New();
        tail -> x = x;
        head -> x = x;
        return;
    }
    struct node *p = tail;
    tail -> prev = New();
    tail = tail -> prev;
    tail -> next = p;
    tail -> x = x;

}

void pop_l() {
    struct node *p = head;
    size--;
    head = head -> prev;
    free(p);
}

void pop_r() {
    size--;
    struct node *p = tail;
    tail = tail -> next;
    free(p);
}

struct node* get(int index)
{
    struct node * cur = head;
    while(index--) {
        cur = cur -> prev;
    }
    return cur;
}

int check(int x) {
    int cur = 0;
    for(int i = 0; i < size; i++)
    {
        cur = cur * 10 + get(i) -> x;
        cur %= x;
    }
    return cur;
}

void divide(int x) {
    int  F =  1;
    struct node* cur = head;
    while(cur != NULL){
        if(cur -> prev != NULL) (cur -> prev) -> x += (cur -> x % x) * 10;
        cur -> x /= x;
        int value = cur -> x;
        cur = cur -> prev;
        if(F == 1 && value == 0)
        {
            pop_l();
        }
        else F = 0;
    }
}

int main() {
    char *str = malloc(sizeof(char) * 100);
    int stak[200];
    int uk = 0;
    gets(str);
    for(int i = 0; i < strlen(str); i++) {
        push_r(str[i] - '0');
    }
    int num = 2;
    while(1) {
        if(size == 1 && get(0) -> x == 1) break;
        while(check(num) == 0) {
//            printf("%d%c", num, ' ');
            stak[uk++] = num;
            divide(num);
        }
        num++;
    }

    while(head != NULL)
    {
        pop_l();
    }

    free(str);
    str = malloc(sizeof(char) * 100);
    gets(str);

    for(int i = 0; i < strlen(str); i++)
    {
        push_r(str[i] - '0');
    }
    num = 2;
    int cur = 0;
    while(1)
    {
        if(size == 1 && get(0) -> x == 1) break;
        while(check(num) == 0)
        {
            while(num > stak[cur])
            {
                if(stak[cur] == 0) return 0;
                cur++;
            }
            if(num == stak[cur])
            {
                printf("%d%c", num, ' ');
                cur++;
            }
            divide(num);
        }
        num++;
    }

}
