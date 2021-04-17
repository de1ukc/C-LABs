#include<bits.h>

struct node {
    char* key;
    struct node *l ,*r;
};
 struct node* New(){
    struct node *v;
    v = malloc(sizeof(struct node) * 1);
    v -> key = malloc(sizeof(char) * 100);
    v -> l = NULL;
    v -> r = NULL;
    return v;
}
void upd(struct node *v, char* value ){
    if(v == NULL) return;
    if(strcmp(v -> key, value) > 0) {
        if(v -> l == NULL) {
            v -> l = New();
            strcpy(v -> l -> key, value);
        } else upd(v -> l, value);
    }
    if(strcmp(v -> key, value) < 0) {
        if(v -> r == NULL) {
            v -> r = New();
            strcpy(v -> r -> key, value);
        } else upd(v -> r, value);
    }
}
char *stak[10000];
int uk = 0;
void Out(struct node *v) {
//    puts(v -> key);
    if(v -> l != NULL) Out(v -> l);
    if(v -> r != NULL) Out(v -> r);
    if(v -> l == NULL && v -> r == NULL) {
        int cur = 0;
        for(int i = 0; i < strlen(v -> key); i++){
            cur += (v -> key)[i];
        }
        if(cur % 2 == 0) {
            stak[uk] = malloc(sizeof(char) * strlen(v -> key));
            strcpy(stak[uk], (v -> key));
            uk++;
        }
    }
}
int main()
{
    struct node *root  = New();
    char *str = malloc(sizeof(char) * 100);
    gets(str);

    strcpy(root -> key, str);
    while(gets(str)) {
        upd(root, str);
    }
    Out(root);
    for(int i = 0; i < uk; i++) {
        puts(stak[i]);
        free(stak[i]);
    }
}
