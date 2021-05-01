//Task 5.1 Variant 5
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_ELEMENTS_IN_QUEUE 6
#define MAX_QUEUES_IN_STACK 6
#define MAX_INT_VALUE 100

typedef struct queue{
    int someData[MAX_ELEMENTS_IN_QUEUE];
    int firstElement;
    int lastElement;
} Queue;

typedef struct firstStack{
    Queue *queue;
    struct firstStack *nextElement;
} Stack1;

typedef struct secondStack{
    int anyNumber;
    struct secondStack *nextElement;
} Stack2;

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//QUEUE//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//
void createQueue(struct queue *queue){
    queue->firstElement = -1;
    queue->lastElement = -1;
}

int isQueueEmpty(Queue *queue){
    return (queue -> lastElement < queue -> firstElement) ? 1 : 0;
}

void putElementIntoQueue(Queue *queue, int element){
    if(queue -> lastElement == MAX_ELEMENTS_IN_QUEUE - 1){
    }
    else {
        if(queue -> firstElement == -1){
            queue -> firstElement = 0;
        }
        queue -> lastElement++;
        queue -> someData[queue -> lastElement] = element;
    }
}

void fillQueue(Queue *queue){
    for(int i = 0; i < MAX_ELEMENTS_IN_QUEUE - 1; i++){
        int randomElement = rand() % MAX_INT_VALUE;
        putElementIntoQueue(queue, randomElement);
    }
}

void printQueue(Queue *queue){
    if(isQueueEmpty(queue)){
        printf("Empty\n");
        return;
    }
    for(int i = queue -> firstElement; i <= queue -> lastElement; i++){
        printf("%d ",queue->someData[i]);
    }
    return;
}
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//QUEUE//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//STACK//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//
void pushQueueIntoStack(Stack1 **headElement, Queue **queue){
    Stack1 *temp = malloc(sizeof(Stack1));
    if (temp != NULL){
        temp->nextElement = *headElement;
        temp->queue = *queue;
        *headElement = temp;
    }
}

void findMaxValueInStack(const Stack1* headElement){
    const Stack1 *temp = headElement;
    int maxValueInt = 0;
    int maxValueIntIndex = 0;
    int counter = 0;
    int counterForQueues = 0;
    
    while (temp) {
        while (counter != MAX_ELEMENTS_IN_QUEUE - 1){
            if(temp -> queue -> someData[counter] > maxValueInt){
                maxValueInt = temp -> queue -> someData[counter];
                maxValueIntIndex = counterForQueues;
                
            }
            counter++;
        }
        temp = temp -> nextElement;
        counterForQueues++;
        counter = 0;
    }
    temp = headElement;
    counter = 0;
    printf("Max Element In This Stack: %d\n", maxValueInt);
    while(temp){
        if(counter == maxValueIntIndex){
            printf("This Queue Has Max Element: " );
            printQueue(temp -> queue);
            printf("\n\n");
            return;
        }
        temp = temp -> nextElement;
        counter++;
    }
    
}

void findMaxSumInStack(const Stack1* headElement){
    const Stack1 *temp = headElement;
    int maxSum = 0;
    int maxSumIndex = 0;
    int counterForMaxSum = 0;
    int tempSum = 0;
    int counter = 0;
    while(temp){
        while (counter != MAX_ELEMENTS_IN_QUEUE - 1){
            tempSum += temp -> queue -> someData[counter];
            counter++;
        }
        if(tempSum > maxSum){
            maxSum = tempSum;
            maxSumIndex = counterForMaxSum;
        }
        tempSum = 0;
        temp = temp -> nextElement;
        counter = 0;
        counterForMaxSum++;
    }
    
    
    temp = headElement;
    counter = 0;
    printf("Max Sum Is : %d\n", maxSum);
    while(temp){
        if(counter == maxSumIndex){
            printf("This Queue Has Max Sum: " );
            printQueue(temp -> queue);
            printf("\n\n");
            return;
        }
        temp = temp -> nextElement;
        counter++;
    }
    
}

void pushIntElementsToStack(Stack2 **headElement, int element){
    Stack2 *temp = malloc(sizeof(Stack2));
    if (temp != NULL){
        temp -> nextElement = *headElement;
        temp -> anyNumber = element;
        *headElement = temp;
    }
}

int popInt(Stack2 **headElement){
    if(*headElement == NULL){
        printf("Stack Empty.");
        return 0;
    }
    int outNumber = (*headElement) -> anyNumber;
    *headElement = (*headElement) -> nextElement;
    return outNumber;
}
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//STACK//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//

int main(){
    srand(time(NULL));
    Stack1 *FirstStackHead = NULL;
    Stack2 *SecondStackHead = NULL;
    int howManyQueues = 0;
    while(true){
        printf("How Many Queues U Want To Put In Stack (1 - %d)?\n\n", MAX_QUEUES_IN_STACK - 1);
        printf("Your Choise: ");
        scanf("%d", &howManyQueues);
        printf("\n");
        if(howManyQueues <= 0 || howManyQueues >= MAX_QUEUES_IN_STACK){
            howManyQueues = 0;
            continue;
        }
        else{
            break;
        }
    }
    
    Queue **queue = (Queue**)malloc(howManyQueues * sizeof (Queue*));
    
    for(int index = 0; index < howManyQueues; index++){
        queue[index] = (Queue*)malloc(MAX_ELEMENTS_IN_QUEUE * sizeof (Queue));
        createQueue(queue[index]);
        fillQueue(queue[index]);
        printf("%d Queue : ", index + 1);
        printQueue(queue[index]);
        printf("\n");
    }
    printf("\n");
    
    for (int index = 0; index < howManyQueues; index++){
        pushQueueIntoStack(&FirstStackHead, &queue[index]);
    }
    
    findMaxValueInStack(FirstStackHead);
    findMaxSumInStack(FirstStackHead);
    
    while (FirstStackHead){
        for(int index = 0; index < MAX_ELEMENTS_IN_QUEUE - 1; index++){
            pushIntElementsToStack(&SecondStackHead, FirstStackHead -> queue -> someData[index]);
        }
        FirstStackHead = FirstStackHead -> nextElement;
    }
    
    Stack1* temp;
    while(FirstStackHead){
        temp = FirstStackHead;
        FirstStackHead = FirstStackHead -> nextElement;
        free(temp);
    }
    
    printf("Second Stack Wich Includes All Elements From Queues: ");
    while(SecondStackHead){
        printf("%d ", popInt(&SecondStackHead));
    }
    printf("\n\n");
    
    for(int index = 0; index < howManyQueues; index++){
        free(queue[index]);
    }
    free(queue);
    
    return 0;
}
