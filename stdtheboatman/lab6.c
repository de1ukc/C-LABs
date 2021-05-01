#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left, *right;
};

struct Node *buildTree(int l, int r, int* a) {
    if (l > r) {
        return NULL;
    }

    if (l == r) {
        struct Node *node = malloc(sizeof(struct Node));

        node->key = a[l];
        node->left = node->right = NULL;

        return node;
    }

    struct Node *node = malloc(sizeof(struct Node));
    int mid = l + r >> 1;

    node->key = a[mid];

    node->left = buildTree(l, mid - 1, a);
    node->right = buildTree(mid + 1, r, a);
}

void printTree(struct Node *root, struct Node *prevRoot) {
    if (root == NULL) {
        return;
    }

    if (prevRoot != NULL) {
        printf("%d -> %d\n", prevRoot->key, root->key);
    }

    printTree(root->left, root);
    printTree(root->right, root);
}

int cmp(const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

void getUniqArray(int n, int *a, int *newN, int *newA) {
    newA = (int*) realloc(newA, sizeof(newA) * n);

    newA[0] = a[0];
    int yk = 1;
    for(int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
            newA[yk++] = a[i];
        }
    }

    *newN = yk;
    newA = (int*) realloc(newA, sizeof(int) * (*newN));
}

int main() {
    int n;
    scanf("%d", &n);

    int a[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    qsort(a, n, sizeof(int), cmp);

    int *b = (int*) malloc(sizeof(int));
    int sizeB;
    getUniqArray(n, a, &sizeB, b);

    printf("%d\n", sizeB);
    for(int i = 0; i < sizeB; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");

    struct Node *root = buildTree(0, sizeB - 1, b);

    printf("start print tree\n");
    printTree(root, NULL);

    return 0;
}
