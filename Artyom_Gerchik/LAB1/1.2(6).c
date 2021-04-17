//Task 1.2, Variant 6.
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void getIndexForStartCounting(char* userNum, int* indexForStart){
    for(int index = 0; index < strlen(userNum); index++){
        if(userNum[index] == '.' || userNum[index] == ','){
            *indexForStart = index;
            break;
        }
    }
    
    for (int index = 0; index < *indexForStart; index++) {
        if(userNum[index] <= 47 || userNum[index] >= 58){
            *indexForStart = 0;
            break;
        }
    }
    
    for (int index = *indexForStart + 1; index<strlen(userNum); index++) {
        if(userNum[index] <= 47 || userNum[index] >= 58){
            *indexForStart = 0;
            break;
        }
    }
}

void startCountFromIndex(char* userNum, int indexForStart, int* sum){
    if(indexForStart != 0){
        for(int index = indexForStart + 1; index < indexForStart + 4; index++){
            if(userNum[index] <= 47 || userNum[index] >= 58){
                break;
            }
            else{
                *sum += userNum[index]-'0';
            }
        }
        if(*sum != 0){
            printf("Sum Of First Three Numbers Of Fractional Part: %d \n\n",*sum);
        }
        else{
            printf("Wrong Input. Non-Float Value, Or Value == 0.\n\n");
        }
    }
    else{
        printf("Wrong Input. Non-Float Value, Or Value == 0.\n\n");
    }
    
}

int main(){
    char userNum[100500];
    int sum = 0;
    int indexForStart = 0;
    
    while(true){
        printf("Insert Float Number(0 - Exit): ");
        scanf("%s",userNum);
        if(userNum[0] == '0' && strlen(userNum) == 1){
            break;
        }
        
        getIndexForStartCounting(userNum, &indexForStart);
        startCountFromIndex(userNum, indexForStart, &sum);
        sum = 0;
        indexForStart = 0;
    }
    
    return 0;
}
