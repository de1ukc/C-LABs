//Task 4.2, Variant 25.
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int performLength(char inputArr[]){
    int index = 0;
    while(inputArr[index] != '\0'){ // \n because fgets put \n on the end of stream.
        index++;
    }
    return index;
}

float countCommentedBytes(char inputArr[] ,int length){
    float counterOfCommentedTextBytes = 0;
    for(int index = 0; index < length; index++){
        if(inputArr[index - 1]!='"' && inputArr[index] == '/' && inputArr[index + 1] =='/'){
            //index += 2;
            while(inputArr[index] != '\n'){
                counterOfCommentedTextBytes++;
                index++;
            }
        }
        else if(inputArr[index - 1]!='"' && inputArr[index] == '/' && inputArr[index + 1] =='*'){
            index += 2;
            counterOfCommentedTextBytes += 2;
            while(inputArr[index] != '*' && inputArr[index + 1] != '/'){
                if(inputArr[index] == '\0'){
                    break;
                }
                counterOfCommentedTextBytes++;
                index++;
            }
            if(inputArr[index] == '*' && inputArr[index + 1] == '/'){
                counterOfCommentedTextBytes += 2;
            }
        }
    }
    return counterOfCommentedTextBytes;
}

int main () {
    FILE *myFile;
    
    char oneChar;
    char * array;
    
    myFile = fopen("file.txt","r");
    
    fseek(myFile, 0, SEEK_END); // seek to end of file
    long size = ftell(myFile); // get current file pointer
    fseek(myFile, 0, SEEK_SET); // seek back to beginning of file
    
    array = (char*) calloc(size, sizeof(char));
    
    int indexForFile = 0;
    while(true) { //open & read from file to array
        if(feof(myFile)){
            array[indexForFile - 1] = '\0';
            break;
        }
        oneChar = fgetc(myFile);
        array[indexForFile] = oneChar;
        indexForFile++;
    }
    fclose(myFile);
    
    printf("Code From .txt:\n\n");
    for(int j = 0; j < performLength(array); j++){
        printf("%c",array[j]);
    }
    printf("\n\n");
    
    printf("Size Of File: %ld Bytes.\n", size);
    printf("Amount Of Commented Code: %.f Bytes\n", countCommentedBytes(array, performLength(array)));
    printf("How Much Percent Of Code Are Commented: %.3f%%\n\n", (countCommentedBytes(array, performLength(array)) * 100)/size);
    
    free(array);
    return 0;
}
