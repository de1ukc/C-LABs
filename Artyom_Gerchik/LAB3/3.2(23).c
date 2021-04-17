//Task 3.2, Variant 23.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

enum Statement{
    FirstReady,
    SecondReady,
    FirstReverseReady,
    SecondReverseReady
};

enum Statement realTimeStatement;

int ** allocateArray(int matrixRows, int matrixColums){
    int **array = (int **)calloc(matrixRows,sizeof(int *));
    for(int i = 0; i < matrixRows; i++) {
        array[i] = (int *)calloc(matrixColums,sizeof(int));
    }
    return array;
}

void printArray(int** array, int matrixRows, int matrixColums){
    
    int increment1_3 = 1;
    int increment2_4 = 2;
    int increment3_1 = 3;
    int increment4_2 = 4;
    
    realTimeStatement = SecondReverseReady;
    
    for(int i = 0; i < matrixRows; i++) {
        for(int j = 0; j < matrixColums; j++) {
            
            switch (realTimeStatement) {
                case SecondReverseReady:
                    array[i][j] = increment1_3;
                    if(increment1_3 == 1){
                        increment1_3 += 2;
                    }
                    else{
                        increment1_3 -= 2;
                    }
                    if(j == matrixColums - 1){
                        realTimeStatement = FirstReady;
                    }
                    break;
                    
                case FirstReady:
                    array[i][j] = increment2_4;
                    if(increment2_4 == 2){
                        increment2_4 += 2;
                    }
                    else{
                        increment2_4 -= 2;
                    }
                    if(j == matrixColums - 1){
                        realTimeStatement = SecondReady;
                    }
                    break;
                    
                case SecondReady:
                    array[i][j] = increment3_1;
                    if(increment3_1 == 3){
                        increment3_1 -= 2;
                    }
                    else{
                        increment3_1 += 2;
                    }
                    if(j == matrixColums - 1){
                        realTimeStatement = FirstReverseReady;
                    }
                    break;
                    
                case FirstReverseReady:
                    array[i][j] = increment4_2;
                    if(increment4_2 == 4){
                        increment4_2 -= 2;
                    }
                    else{
                        increment4_2 += 2;
                    }
                    if(j == matrixColums - 1){
                        realTimeStatement = SecondReverseReady;
                    }
                    break;
                    
                    
                default:
                    break;
            }
            
        }
    }
    
    for(int i = 0; i < matrixRows; i++) {
        for(int j = 0; j < matrixColums; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void cleanUpMemory(int ** array, int matrixRows){
    for(int i = 0; i < matrixRows; i++) {
        free(array[i]);
    }
    free(array);
}

int main() {
    int matrixRows = 0;
    int matrixColums = 0;
    
    while (true){
        printf("Enter number of rows: ");
        scanf("%d",&matrixRows);
        printf("Enter number of colums: ");
        scanf("%d",&matrixColums);
        
        int** myOwnArray = allocateArray(matrixRows, matrixColums);
        printArray(myOwnArray, matrixRows, matrixColums);
        cleanUpMemory(myOwnArray,matrixRows);
        
        fflush(stdin); // buffer clear because getchar gets '\n' from last scanf.
        
        printf("If you want continue - enter 'y' into console, otherwise enter any char to exit program.\nYour Choise: ");
        char isUserWantToContinue = getchar();
        
        if(isUserWantToContinue == 'y'){
            continue;
        }
        else{
            return 0;
        }
    }
    return 0;
}
