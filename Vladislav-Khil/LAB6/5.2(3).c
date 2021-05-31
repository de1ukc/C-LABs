//Задание 5.2 Вариант 3
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define STACK_OVERFLOW  -100
#define STACK_UNDERFLOW -101
#define OUT_OF_MEMORY   -102


typedef struct node{
int key;
int symbol;
struct node* right_child;
struct node* left_child;
}node;


struct node* new_node(int x, int value) {
    struct node* root;
    root = malloc(sizeof(struct node));
    root->key = x;
    root->symbol = value;
    root->left_child = NULL;
    root->right_child = NULL;
    return root;
}


struct node* insert(struct node* root, int x, int value) {
    if (root == NULL) {
        return new_node(x, value);
    }
    else if (x > root->key) {
        root->right_child = insert(root->right_child, x, value);
    }
    else {
        root->left_child = insert(root->left_child, x, value);
    }
    return root;
}


int sum = 0;


void printInorder(struct node* root) {

    if (root == NULL) {
        return;
    }

    if (root->left_child) {
        printInorder(root->left_child);
    }

    printf("%d ", root->symbol);

    sum += root->symbol;

    if (root->right_child) {
        printInorder(root->right_child);
    }
}


int Sum() {
    int temp = sum;
    sum = 0;
    return temp;
}


/////////////////////////////////////////////////////////////////////////////////////////

typedef struct Node_tag {
    struct node* root;
    struct Node_tag* next;
    int value;
} Node_t;


void push(Node_t** head, node* root1) {
    Node_t* tmp = malloc(sizeof(Node_t));
    if (tmp == NULL) {
        exit(STACK_OVERFLOW);
    }
    
    tmp->next = *head;
    tmp->root = root1; 

    *head = tmp;
}


pop2(Node_t** head) {
    Node_t* out;
    node* root1;
    if (*head == NULL) {
        exit(STACK_UNDERFLOW);
    }
    out = *head;
    *head = (*head)->next;
    root1 = out->root;
    free(out);
    
    printf("\nNext element:\n");

    Sum();

    printInorder(root1);

    printf("\nSUM:%d\n", Sum());
   
}


size_t getSize(const Node_t* head) {
    size_t size = 0;
    while (head) {
        size++;
        head = head->next;
    }
    return size;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
    srand(time(NULL));

    char exit;

    while (true)
    {
        system("cls");
        int count = 0;
        printf("Enter count tree:");
        scanf_s("%d", &count);
        struct node** roots = (struct node**)calloc(count, sizeof(struct node*));
        int symbol;
        int key;

        for (int i = 0; i < count; i++)
        {
            roots[i] = new_node(3, 3);
        }

        int numberOfNodes = 0;
        printf("Enter number of nodes:");
        scanf_s("%d", &numberOfNodes);

        for (int i = 0; i < count; i++)
        {
            for (int index = 1; index < numberOfNodes; index++)
            {
                insert(roots[i], index, symbol = rand() % 8 + 1);
            }
        }

        _getch();
        system("cls");

        for (int i = 0; i < count; i++)
        {
            printf("\nRoot[%d]:\n", i + 1);
            printInorder(roots[i]);
        }

        Node_t* head = NULL;

        for (int i = 0; i < count; i++)
        {
            push(&head, roots[i]);
        }
        
        _getch();
        system("cls");

        printf("\nsize = %d\n", getSize(head));

        while (head) {
            pop2(&head);
        }
        printf("\n\nsize = %d\n", getSize(head));

        _getch();
        system("cls");
       
        printf("If you want continue - enter 'y' into console.\nYour Choise: ");
        while ((getchar()) != '\n');
        exit = getchar();
        if (exit == 'y')
        {
            continue;
        }
        else
        {
            return 0;
        }

    }
    return 0;
}