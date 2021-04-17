//Task 4.1, Variant 25.
/* TEXT EXAMPLE
 The Maintenance phase is the last and the longest SDLC phase and it lasts until the system is retired. It involves day-to-day operation of the system, making modifications to improve performance, and correcting problems. Three key concepts ensure good quality of maintenance service: reliability, availability, and serviceability. The term quality of service (QOS) refers to the level of performance a computer system provides. Typical maintenance phase activities ensure that the system functions as well as possible. During the maintenance phase, an information system is likely to undergo many changes to meet an organization’s needs. Changes can include: operating system, application software and security upgrades, user interface revisions to make the system easier to use, application software revisions to fix bugs and add features, hardware replacements necessary to retire defective equipment or enhance performance, hardware, software, or network adjustments to maintain and enhance quality of service.
 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void removeExtraSpace(char inputString[], char outputArray[]){
    
    int readIndex = 0;
    int writeIndex = 0;
    
    while(inputString[readIndex] == ' '){ // skip spaces before first char
        readIndex++;
    }
    
    for(writeIndex = 0; inputString[readIndex] != '\0'; readIndex++){
        if(inputString[readIndex] == ' ' && inputString[readIndex + 1] == ' '){
            continue;
        }
        else if(inputString[readIndex] == ' ' && inputString[readIndex + 1] == '\n'){
            continue;
        }
        outputArray[writeIndex] = inputString[readIndex];
        writeIndex++;
    }
    outputArray[writeIndex] = '\0';
}

int performLength(char inputStr[]){
    int index = 0;
    while(inputStr[index] != '\n'){ // \n because fgets put \n on the end of stream.
        index++;
    }
    return index;
}

int countWords(char inputStr[])
{
    int numberOfWords = 0;
    for(int index = 0; index < performLength(inputStr); index ++){
        if (inputStr[index] == ' '){
            numberOfWords++;
        }
    }
    return numberOfWords + 1;
}

int countSentences(char inputStr[])
{
    int numberOfSentences = 0;
    for(int index = 0; index < performLength(inputStr); index++){
        if (inputStr[index] == '.'){
            while(inputStr[index] == '.'){
                index++;
            }
            numberOfSentences++;
        }
        else if (inputStr[index] == '!'){
            while(inputStr[index] == '!'){
                index++;
            }
            numberOfSentences++;
        }
        else if(inputStr[index] == '?'){
            while(inputStr[index] == '?'){
                index++;
            }
            numberOfSentences++;
        }
    }
    return numberOfSentences;
}

void printLongestWordInText(char inputStr[])
{
    int maxLength = 0;
    int startPos = 0;
    int length = 0;
    
    for(int index = 0; inputStr[index] != '\n' ; index++){
        if(length == maxLength){
            startPos = index - maxLength;
        }
        
        if(inputStr[index] == ' '){
            length = 0;
        }
        else{
            length++;
        }
        
        if(length > maxLength){
            maxLength = length;
        }
    }
    printf("Longest Word Length: %d Symbols\n",maxLength);
    printf("Longest Word: ");
    for(int index = 1 ; index <= maxLength; index++){
        printf("%c",inputStr[startPos]);
        startPos++;
    }
    printf("\n\n");
}

void printLongestSentenceInText(char inputStr[]){
    int maxLength = 0;
    int startPos = 0;
    int length = 0;
    
    for(int index = 0; inputStr[index]!= '\n' ; index++){
        if(length == maxLength){
            startPos = index - maxLength;
        }
        
        if(inputStr[index] == '.'){
            length = 0;
        }
        else{
            length++;
        }
        
        if(length > maxLength){
            maxLength = length;
        }
    }
    printf("Longest Sentence Length: %d Symbols\n",maxLength);
    printf("Longest Sentence: ");
    for(int index = 1 ; index <= maxLength; index++){
        printf("%c",inputStr[startPos]);
        startPos++;
    }
    printf("\n\n");
    
}

int main()
{
    char inputString[100501], formattedString[100501];
    
    printf("Enter a Text(100500 chars allowed): ");
    fgets(inputString, sizeof(inputString),stdin);
    
    removeExtraSpace(inputString, formattedString);
    
    printf("\nText Without Extra Spaces: %s\n", formattedString);
    printf("Number Of Symbols: %d\n",performLength(formattedString));
    printf("Number Of Words: %d\n",countWords(formattedString));
    printf("Number Of Sentences: %d\n\n",countSentences(formattedString));
    printLongestWordInText(formattedString);
    printLongestSentenceInText(formattedString);
    
    return 0;
}
