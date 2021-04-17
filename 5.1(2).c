#include <bits.h>
int size = 0;
struct node {
    struct node *l, *r;
    int x;
};
struct node* New(){
    size++;
    struct node *v;
    v = malloc(sizeof(struct node) * 1);
    v -> x = malloc(sizeof(char) * 100);
    v -> l = NULL;
    v -> r = NULL;
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
    head -> l = New();
    head = head -> l;
    head -> r = p;
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
    tail -> r = New();
    tail = tail -> r;
    tail -> l = p;
    tail -> x = x;

}
void pop_l() {
    struct node *p = head;
    size--;
    head = head -> r;
    free(p);
}
void pop_r() {
    size--;
    struct node *p = tail;
    tail = tail -> l;
    free(p);
}
struct node* get(int index) {
    struct node * cur = head;
    while(index--) {
        cur = cur -> r;
    }
    return cur;
}
int check(int x) {
    int cur = 0;
    for(int i = 0; i < size; i++) {
        cur = cur * 10 + get(i) -> x;
        cur %= x;
    }
    return cur;
}
void divide(int x) {
    int  F =  1;
    struct node* cur = head;
    while(cur != NULL){
        if(cur -> r != NULL) (cur -> r) -> x += (cur -> x % x) * 10;
        cur -> x /= x;
        int value = cur -> x;
        cur = cur -> r;
        if(F == 1 && value == 0) {
            pop_l();
        } else F = 0;
    }
}
int main() {
    char *str = malloc(sizeof(char) * 100);
    gets(str);
    for(int i = 0; i < strlen(str); i++) {
        push_r(str[i] - '0');
    }
    int num = 2;
    while(1) {
        if(size == 1 && get(0) -> x == 1) break;
        while(check(num) == 0) {
            printf("%d%c", num, ' ');
            divide(num);
        }
        num++;

    }
}
