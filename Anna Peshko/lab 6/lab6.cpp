//Task 5.2 Variant 12

/*Задана очередь, указывающая порядок обработки одного из n
бинарных деревьев поиска. Элементы очереди содержат: номер
обрабатываемого дерева i ( i £ n ); признак выполняемого действия:
‘А’ – элемент из очереди добавляется в i-е дерево, ‘D’ – из i-го
дерева удаляется заданный элемент; данные (целое число d).
Обработать деревья в соответствии с заданной очередью.*/

#include <stdio.h>
#include <malloc.h>

struct node {
    int key;
    struct node* l, * r;
};

struct node* New(int value) {
    struct node* v;
    v = malloc(sizeof(struct node) * 1);
    v->key = value;
    v->l = NULL;
    v->r = NULL;
    return v;
}
struct node* Add(struct node* v, int value) {
    if (v == NULL) return New(value);
    if (value < v->key) {
        v->l = Add(v->l, value);
    }
    if (value > v->key) {
        v->r = Add(v->r, value);
    }
    return v;
}
struct node* Ers(struct node* v, int value) {
    if (v == NULL) return v;
    if (value < v->key) {
        v->l = Ers(v->l, value);
    }
    else
        if (value > v->key) {
            v->r = Ers(v->r, value);
        }
        else {
            if (v->l == NULL && v->r == NULL) {
                free(v);
                v = NULL;
            }
            else if (v->l == NULL) {
                struct node* temp = v;
                v = v->r;
                free(temp);
            }
            else {
                struct node* temp = v->r;
                while (temp->l != NULL) temp = temp->l;
                v->key = temp->key;
                v->r = Ers(v->r, temp->key);
            }
        }
    return v;
}
void Out(struct node* v) {
    if (v == NULL) return;
    Out(v->l);
    Out(v->r);
    printf("%d%c", v->key, ' ');
}
int main() {

    const int n = 1;
    struct node* root[n];
    for (int i = 0; i < n; i++) root[i] = NULL;
    int Q;
    scanf_s("%i", &Q);
    while (Q--) {
        char type, c;
        int pos, x;
        scanf_s("\n%c%c%i%c%i", &type, &c, &pos, &c, &x);
        if (type == 'A') {
            root[pos] = Add(root[pos], x);
        }
        if (type == 'D') {
            root[pos] = Ers(root[pos], x);
        }
    }
    for (int i = 0; i < n; i++) {
        Out(root[i]);
        printf("%c", '\n');
    }
    return 0;
}

//A i d
//D i d