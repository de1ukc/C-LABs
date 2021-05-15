//Task 5.2 Variant 28
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define VOWEL_CHAR_ARRAY_LENGTH 12
#define CONSONANT_CHAR_ARRAY_LENGTH 40

char vowelChars[] = "AaEeIiOoUuYy";
char consonantChars[] = "BbCcDdFfGgHhJjKkLlMmNnPpQqRrSsTtVvWwXxZz";
int VowelCharsCounterForTraversal = 0;
int ConsonantCharsCounterForTraversal = 0;


//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\BINARY SEARCH TREE//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\

struct node{
    int key;
    char symbol;
    struct node *right_child;
    struct node *left_child;
};

struct node* search(struct node *root, int x){
    if(root==NULL || root->key==x){
        return root;
    }
    else if(x>root->key){
        return search(root->right_child, x);
    }
    else {
        return search(root->left_child,x);
    }
}

struct node* find_minimum(struct node *root){
    if(root == NULL){
        return NULL;
    }
    else if(root->left_child != NULL){
        return find_minimum(root->left_child);
    }
    return root;
}


struct node* new_node(int x, char oneChar){
    struct node *root;
    root = malloc(sizeof(struct node));
    root->key = x;
    root->symbol = oneChar;
    root->left_child = NULL;
    root->right_child = NULL;
    return root;
}

struct node* insert(struct node *root, int x,char oneChar){
    if(root==NULL){
        return new_node(x, oneChar);
    }
    else if(x>root->key){
        root->right_child = insert(root->right_child, x, oneChar);
    }
    else {
        root->left_child = insert(root->left_child, x, oneChar);
    }
    return root;
}


struct node* delete(struct node *root, int x){
    
    if(root==NULL){
        return NULL;
    }
    if (x>root->key){
        root->right_child = delete(root->right_child, x);
    }
    else if(x<root->key){
        root->left_child = delete(root->left_child, x);
    }
    else{
        //No Children
        if(root->left_child==NULL && root->right_child==NULL){
            free(root);
            return NULL;
        }
        //One Child
        else if(root->left_child==NULL || root->right_child==NULL){
            struct node *temp;
            if(root->left_child==NULL){
                temp = root->right_child;
            }
            else{
                temp = root->left_child;
            }
            free(root);
            return temp;
        }
        //Two Children
        else{
            struct node *temp = find_minimum(root->right_child);
            root->key = temp->key;
            root->right_child = delete(root->right_child, temp->key);
        }
    }
    return root;
}

void printInorder(struct node* root){
    
    if (root == NULL){
        return;
    }
    
    if(root->left_child){
        printInorder(root->left_child);
    }
    
    printf("%d ", root->key);
    
    if(root->right_child){
        printInorder(root->right_child);
    }
}

bool containsVowel(char charToAnalyze);
bool containsConsonant(char charToAnalyze);
void whichOneIsMore(int vowels, int consonants);

void InOrderForTask(struct node* root){
    
    if (root == NULL){
        return;
    }
    
    if(root->left_child){
        InOrderForTask(root->left_child);
    }
    
    if(containsVowel(root->symbol)){
        VowelCharsCounterForTraversal++;
    }
    
    if(containsConsonant(root->symbol)){
        ConsonantCharsCounterForTraversal++;
    }
        
    if(root->right_child){
        InOrderForTask(root->right_child);
    }
}

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\BINARY SEARCH TREE//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\SOME METHODS//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//


bool containsVowel(char charToAnalyze){
    for(int index = 0; index < VOWEL_CHAR_ARRAY_LENGTH; index++){
        if(charToAnalyze == vowelChars[index]){
            return true;
        }
    }
    return false;
}

bool containsConsonant(char charToAnalyze){
    for(int index = 0; index < CONSONANT_CHAR_ARRAY_LENGTH; index++){
        if(charToAnalyze == consonantChars[index]){
            return true;
        }
    }
    return false;
}

int myStringLength(char* inputStr){
    int counter = 0;
    while(inputStr[counter] != '\0'){
        counter++;
    }
    return counter - 1;
}

void whichOneIsMore(int vowels, int consonants){
    if(vowels > consonants){
        printf("There are more vowels: %d > %d.",vowels, consonants);
    }
    else if(consonants > vowels){
        printf("There are more consonants: %d > %d.",consonants, vowels);
    }
    else if(consonants == vowels){
        printf("There are as many vowels as consonants: %d == %d.",vowels, consonants);
    }
}

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\SOME METHODS//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//

int main(){
    
    char inputString[32];
    int vowelCounter = 0;
    int consonantCounter = 0;
    
    printf("Enter string(30 symbols allowed): ");
    fgets(inputString, sizeof(inputString), stdin);
    printf("\n");
    
    for(int index = 0; index < myStringLength(inputString); index++){
        if(containsVowel(inputString[index])){
            vowelCounter++;
        }
        if(containsConsonant(inputString[index])){
            consonantCounter++;
        }
    }
    
    struct node *root = new_node(inputString[0],inputString[0]);
    for(int index = 1; index < myStringLength(inputString); index++){
        insert(root, inputString[index], inputString[index]);
    }
    
    printf("InOrder Traversal: ");
    printInorder(root);
    printf("\n\n");
    
    whichOneIsMore(vowelCounter, consonantCounter);
    printf("\n\n");
    
    printf("InOrder Traversal, But For Counting:\n");
    InOrderForTask(root);
    whichOneIsMore(VowelCharsCounterForTraversal, ConsonantCharsCounterForTraversal);
    printf("\n\n");
    
    
    return 0;
}
