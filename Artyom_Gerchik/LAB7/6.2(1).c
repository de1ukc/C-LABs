//Task 6.2 Variant 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

double cashFromSelling = 0;
double cashWastedForBuyingBooks = 0;
double cashForWorkers = 10000;
double cashForPlacement = 20000;
double TAX = 300;
long howMuchBooksSelled = 0;
long howMuchOrders = 0;
long howMuchBooksSelledForAllTime = 0;
double howMuchCashForAllTime = 0;
char logs[100500];
int booksHere = 0;

typedef enum statement{
    initial,
    bookAreHere
}Statement;

typedef struct book{
    char type[100];
    int lot;
    int howMuchCurrent;
    char name[100];
    char author[100];
    float buyPrice;
    float sellPrice;
}Book;

struct node {
    Book book;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;
struct node *last = NULL;

bool isEmpty() {
    return last == NULL;
}

void howMuchBooksInWarehouseRightNow() {
    int numberOfElements = 0;
    struct node *current;
    
    for(current = head; current != NULL; current = current -> next){
        numberOfElements++;
    }
    printf("Books Right Now In Warehouse: %d\n", numberOfElements);
}

void howMuchBooksInWarehouseCosts(){
    float cash = 0;
    struct node* temp = head;
    while (temp) {
        cash += temp->book.sellPrice;
        temp = temp -> next;
    }
    printf("Price Of All Books In Warehouse: %f\n", cash);
}

void getInfoAboutBooksForUser() {
    struct node *tempPointer = NULL;
    tempPointer = head;
    printf("\n-----------------------------WAREHOUSE-----------------------------\n");
    while(tempPointer) {
        printf("\nType: %s",tempPointer->book.type);
        printf("\nLot: %d",tempPointer->book.lot);
        printf("\nHowMuchCurrent: %d",tempPointer->book.howMuchCurrent);
        printf("\nName: %s",tempPointer->book.name);
        printf("\nAuthor: %s",tempPointer->book.author);
        //printf("\nBuyPrice: %f",tempPointer->book.buyPrice);
        printf("\nSellPrice: %f\n",tempPointer->book.sellPrice);
        tempPointer = tempPointer->next;
    }
    printf("\n-----------------------------WAREHOUSE-----------------------------\n");
}

void warehouse() {
    struct node *tempPointer = NULL;
    tempPointer = head;
    printf("\n-----------------------------WAREHOUSE-----------------------------\n");
    while(tempPointer) {
        printf("\nType: %s",tempPointer->book.type);
        printf("\nLot: %d",tempPointer->book.lot);
        printf("\nHowMuchCurrent: %d",tempPointer->book.howMuchCurrent);
        printf("\nName: %s",tempPointer->book.name);
        printf("\nAuthor: %s",tempPointer->book.author);
        printf("\nBuyPrice: %f",tempPointer->book.buyPrice);
        printf("\nSellPrice: %f\n",tempPointer->book.sellPrice);
        tempPointer = tempPointer->next;
    }
    printf("\n");
    howMuchBooksInWarehouseRightNow();
    howMuchBooksInWarehouseCosts();
    printf("\n-----------------------------WAREHOUSE-----------------------------\n");
}



double cleanProfit = 0;
long tempCountOfBooks = 0;
double tempCash = 0;
bool wasFirstTimeHere = false;
int books = 0;

//void silentCashBox(){ // to save info about cash and number of books, but not to show it to user.
//    getBookkeping();
//    if(!wasFirstTimeHere){
//       books = booksHere;
//    }
//
//    double dirtyProfit = (cashFromSelling - cashWastedForBuyingBooks);
//    cleanProfit = (dirtyProfit - cashForWorkers - cashForPlacement);
//
//    if(!wasFirstTimeHere){
//        tempCountOfBooks = howMuchBooksSelled;
//        tempCash = cleanProfit;
//        howMuchCashForAllTime += cleanProfit;
//        howMuchBooksSelledForAllTime += howMuchBooksSelled;
//        wasFirstTimeHere = true;
//        saveBookkepping();
//        return;
//    }
//    if((howMuchBooksSelled - tempCountOfBooks) == 0){
//        tempCountOfBooks = howMuchBooksSelled;
//        tempCash = cleanProfit;
//        //howMuchCashForAllTime += cleanProfit;
//        // howMuchBooksSelledForAllTime += howMuchBooksSelled;
//    }
//    else if((howMuchBooksSelled - tempCountOfBooks) > 0 ){
//        howMuchBooksSelledForAllTime += (howMuchBooksSelled - tempCountOfBooks);
//        tempCountOfBooks = howMuchBooksSelled;
//        if(tempCash < 0 && cleanProfit < 0){
//            double res = fabs(tempCash) - fabs(cleanProfit);
//            howMuchCashForAllTime += res;
//        }
//        else if(cleanProfit > 0 && tempCash < 0){
//            float temp = cleanProfit -  fabs(tempCash);
//            howMuchCashForAllTime = temp;
//        }
//        else if(tempCash > 0 && cleanProfit > 0){
//            double res = (cleanProfit - tempCash);
//            howMuchCashForAllTime += res;
//        }
//
//    }
//    saveBookkepping();
//}

void getBookkeping(void);

void cashBox(){
    getBookkeping();
    double dirtyProfit = (cashFromSelling - cashWastedForBuyingBooks);
    cleanProfit = (dirtyProfit - cashForWorkers - cashForPlacement);
    
    printf("\n------------------------------CASHBOX------------------------------\n");
    printf("How Much Orders: %ld\n", howMuchOrders);
    printf("How Much Books Selled: %ld\n\n", howMuchBooksSelled);
    printf("Cash Wasted For Buying Books: %f\n", cashWastedForBuyingBooks);
    printf("Cash Obtained From Selling Books: %f\n",cashFromSelling);
    printf("Tax: %f\n\n",TAX);
    printf("Cash For Workers: %f\n",cashForWorkers);
    printf("Cash For Placement: %f\n\n", cashForPlacement);
    printf("Dirty Profit: %f\n", dirtyProfit);
    printf("Clean Profit: %f\n\n", cleanProfit);
    if(!wasFirstTimeHere){
        tempCountOfBooks = howMuchBooksSelled;
        tempCash = cleanProfit;
        //howMuchCashForAllTime += cleanProfit;
        //howMuchBooksSelledForAllTime += howMuchBooksSelled;
        wasFirstTimeHere = true;
        printf("How Much Cash For All Time: %f\n", howMuchCashForAllTime);
        printf("How Much Books Selled For All Time: %ld\n\n", howMuchBooksSelledForAllTime);
        if(cleanProfit > 0){
            printf("Clean Profit > 0, Ha Ha, EZ Cash.\n");
        }
        else{
            printf("Clean Profit < 0, It Is A Time Wasting, Not A Business.\n");
        }
        printf("------------------------------CASHBOX------------------------------\n");
        //saveBookkepping();
        return;
    }
    if((howMuchBooksSelled - tempCountOfBooks) == 0){
        
//        float difference = fabs(cleanProfit) - fabs(tempCash);
//        if(cleanProfit < 0){
//            -difference;
//        }
        tempCountOfBooks = howMuchBooksSelled;
        tempCash = cleanProfit;
        
        //howMuchCashForAllTime += cleanProfit;
        // howMuchBooksSelledForAllTime += howMuchBooksSelled;
    }
    else if((howMuchBooksSelled - tempCountOfBooks) > 0){
        howMuchBooksSelledForAllTime += (howMuchBooksSelled - tempCountOfBooks);
        tempCountOfBooks = howMuchBooksSelled;
        if(tempCash < 0 && cleanProfit < 0){
            //double res = fabs(tempCash) - fabs(cleanProfit);
            //howMuchCashForAllTime += res;
        }
        else if(tempCash > 0 && cleanProfit > 0){
            //double res = (cleanProfit - tempCash);
            //howMuchCashForAllTime += res;
        }
    }
    printf("How Much Cash For All Time: %f\n", howMuchCashForAllTime);
    printf("How Much Books Selled For All Time: %ld\n\n", howMuchBooksSelledForAllTime);
    if(cleanProfit > 0){
        printf("Clean Profit > 0, Ha Ha, EZ Cash.\n");
    }
    else{
        printf("Clean Profit < 0, It Is A Time Wasting, Not A Business.\n");
    }
    printf("------------------------------CASHBOX------------------------------\n");
    //saveBookkepping();
}

void insertElementLast(Book bookToInsert, bool areYouFromMannualAdd) {
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    
    strcpy(newNode->book.type, bookToInsert.type);
    newNode->book.lot = bookToInsert.lot;
    if(areYouFromMannualAdd){
        newNode->book.howMuchCurrent = bookToInsert.howMuchCurrent;
    }
    else{
        newNode->book.howMuchCurrent = bookToInsert.lot;
    }
    strcpy(newNode->book.name, bookToInsert.name);
    strcpy(newNode->book.author, bookToInsert.author);
    newNode->book.buyPrice = bookToInsert.buyPrice;
    newNode->book.sellPrice = bookToInsert.sellPrice;
    
    if(isEmpty()) {
        last = newNode;
        head = last;
    }
    else {
        last->next = newNode;
        newNode->prev = last;
    }
    last = newNode;
    last->next = NULL;
    cashWastedForBuyingBooks += newNode->book.buyPrice + TAX;
}

void fixNumberOfBooks(char nameOfBook[]){
    struct node* temp = head;
    
    while (temp){
        if(strcmp(temp->book.name, nameOfBook) == 0){
            temp->book.howMuchCurrent--;
            temp = temp -> next;
        }
        else{
            temp = temp -> next;
        }
    }
}


void deleteBookByName(char nameOfBook[]){
    struct node* tempNode = head;
    bool deleted = false;
    
    while(tempNode){
        if(strcmp(tempNode->book.name, nameOfBook) == 0){
            cashFromSelling += tempNode->book.sellPrice;
            if(tempNode == head){
                if(head == last){
                    head = last = NULL;
                    deleted = true;
                    break;
                }
                head = tempNode->next;
                tempNode->next->prev = NULL;
                deleted = true;
                break;
            }
            if(tempNode == last){
                last = tempNode->prev;
                tempNode->prev->next = NULL;
                deleted = true;
                break;
            }
            if(tempNode != head && tempNode != last){
                tempNode->next->prev = tempNode->prev;
                tempNode -> prev -> next = tempNode -> next;
                deleted = true;
                break;
            }
            
        }
        else{
            if(tempNode -> next == NULL){
                tempNode=NULL;
            }
            else{
                tempNode = tempNode -> next;
            }
        }
    }
    if(deleted){
        printf("\nBook %s, Sold!\n",nameOfBook);
        char book[100500] =("\nBook ");
        char bookName[100500];
        strcpy(bookName, nameOfBook);
        char sold[100500] = (" Sold!");
        char price[100500] = (" Price: ");
        char priceCPY[100500];
        sprintf(priceCPY, "%f", tempNode->book.sellPrice);
        
        strcat(book, bookName);
        strcat(book, sold);
        strcat(book, price);
        strcat(book, priceCPY);
        strcat(book, "\n");
        strcat(logs, book);
    }
    free(tempNode);
    fixNumberOfBooks(nameOfBook);
    return;
}

bool check(char nameOfBook[], int lot){
    bool bookAreStillHere = false;
    struct node* temp = head;
    while (temp) {
        if(strcmp(temp->book.name, nameOfBook) == 0){
            if(temp->book.howMuchCurrent < lot){
                break;
            }
            bookAreStillHere = true;
            temp = temp -> next;
        }
        else{
            temp = temp -> next;
        }
    }
    return bookAreStillHere;
}

void saveToFile(){
    FILE* filePointer;
    filePointer = fopen("booksFile.txt", "w");
    
    struct node *tempPointer = NULL;
    tempPointer = head;
    while(tempPointer) {
        
        char lotToSave[100];
        char howMuchCurrentToSave[100];
        char buyPriceToSave[100];
        char sellPriceToSave[100];
        
        sprintf(lotToSave, "%d", tempPointer->book.lot);
        sprintf(howMuchCurrentToSave, "%d", tempPointer->book.howMuchCurrent);
        sprintf(buyPriceToSave, "%f", tempPointer->book.buyPrice);
        sprintf(sellPriceToSave, "%f", tempPointer->book.sellPrice);
        
        fputs(tempPointer->book.type, filePointer);
        fputs("\n", filePointer);
        fputs(lotToSave, filePointer);
        fputs("\n", filePointer);
        fputs(howMuchCurrentToSave, filePointer);
        fputs("\n", filePointer);
        fputs(tempPointer->book.name, filePointer);
        fputs("\n", filePointer);
        fputs(tempPointer->book.author, filePointer);
        fputs("\n", filePointer);
        fputs(buyPriceToSave, filePointer);
        fputs("\n", filePointer);
        fputs(sellPriceToSave, filePointer);
        fputs("\n", filePointer);
        tempPointer = tempPointer -> next;
    }
    fclose(filePointer);
}

void sellBook(){
    howMuchOrders++;
    char nameOfBookForSell[100];
    int lot = 0;
    bool notOrdered = true;
    getInfoAboutBooksForUser();
    while (notOrdered) {
        printf("\nEnter Name Of Book, Which U Wanna Buy: ");
        scanf("%s", nameOfBookForSell);
        printf("Enter How Much Of This Books U Wanna Buy: ");
        scanf("%d", &lot);
        if(check(nameOfBookForSell, lot)){
            for(int counter = 0; counter < lot; counter++){
                deleteBookByName(nameOfBookForSell);
                howMuchBooksSelled++;
            }
            notOrdered = false;
            saveToFile();
        }
        else{
            printf("Check Input. Maybe U Entered Weird Name, Or Weird Number Of Books.\n");
            fflush(stdin);
        }
    }
}

bool readFromFile(){
    
    FILE* filePointer;
    FILE* emptyCheck;
    
    char laterName [100] = "test";
    bool wasHereLater = false;
    filePointer = fopen("booksFile.txt", "r");
    
    emptyCheck = fopen("booksFile.txt", "r");
    fseek (emptyCheck, 0, SEEK_END);
    long size = ftell(emptyCheck);
    if (0 == size) {
        return false;
    }
    
    while (!feof(filePointer)) {
        
        Book bookToInsert;
        
        char typeToRead[100];
        char lotToRead[100];
        char howMuchCurrentToRead[100];
        char nameToRead[100];
        char authorToRead[100];
        char buyPriceToRead[100];
        char sellPriceToRead[100];
        
        fgets(typeToRead, 100, filePointer);
        typeToRead[strcspn(typeToRead, "\n")] = 0;
        fgets(lotToRead, 100, filePointer);
        fgets(howMuchCurrentToRead, 100, filePointer);
        fgets(nameToRead, 100, filePointer);
        nameToRead[strcspn(nameToRead, "\n")] = 0;
        
        if(strcmp(laterName, nameToRead) == 0){
            wasHereLater = true;
        }
        else{
            wasHereLater = false;
            strcpy(laterName, nameToRead);
        }
        fgets(authorToRead, 100, filePointer);
        authorToRead[strcspn(authorToRead, "\n")] = 0;
        fgets(buyPriceToRead, 100, filePointer);
        fgets(sellPriceToRead, 100, filePointer);
        
        int lot = atoi(lotToRead);
        int howMuchCurrent = atoi(howMuchCurrentToRead);
        float buyPrice = (float)strtod(buyPriceToRead, NULL);
        float sellPrice = (float)strtod(sellPriceToRead, NULL);
        
        strcpy(bookToInsert.type, typeToRead);
        bookToInsert.lot = lot;
        bookToInsert.howMuchCurrent = howMuchCurrent;
        strcpy(bookToInsert.name, nameToRead);
        strcpy(bookToInsert.author, authorToRead);
        bookToInsert.buyPrice = buyPrice;
        bookToInsert.sellPrice = sellPrice;
        
        if(!wasHereLater){
            for(int counter = 0; counter < bookToInsert.howMuchCurrent; counter++){
                insertElementLast(bookToInsert, true);
            }
        }
    }
    fclose(filePointer);
    return true;
}

int getCurrentLot(char name[]){
    struct node* tempNode = head;
    while(tempNode){
        if(strcmp(tempNode->book.name, name) == 0){
            return tempNode->book.lot;
        }
        tempNode = tempNode->next;
    }
    return 0;
}

int getCurrentHowMuch(char name[]){
    struct node* tempNode = head;
    while(tempNode){
        if(strcmp(tempNode->book.name, name) == 0){
            return tempNode->book.howMuchCurrent;
        }
        tempNode = tempNode->next;
    }
    return 0;
}

void fixExistingBooks(char name[], int lot, int howMuch, float buyPrice, float sellPrice){
    struct node* tempNode = head;
    while(tempNode){
        if(strcmp(tempNode->book.name, name) == 0 && tempNode->book.buyPrice == buyPrice && tempNode->book.sellPrice == sellPrice){
            tempNode->book.howMuchCurrent += howMuch;
        }
        tempNode = tempNode->next;
    }
}

void addBookMannually(){
    
    Book bookToInsert;
    bool somethingWrong = true;
    char type[100];
    int lot = 0;
    char name[100];
    char author[100];
    float buyPrice = 0.0;
    float sellPrice = 0.0;
    
    while(somethingWrong){
        printf("Enter Type Of Book: ");
        scanf("%s", type);
        printf("Enter Lot Of Book: ");
        scanf("%d", &lot);
        
        if(lot <= 0){
            printf("Lot Cannot Be <= 0.\n");
            somethingWrong = true;
            continue;
        }
        else{
            somethingWrong = false;
        }
        printf("Enter Name Of Book: ");
        scanf("%s", name);
        printf("Enter Author Of Book: ");
        scanf("%s", author);
        printf("Enter Buy Price Of Book: ");
        scanf("%f", &buyPrice);
        if(buyPrice <= 0){
            printf("Buy Price Cannot Be <= 0.\n");
            somethingWrong = true;
            continue;
        }
        else{
            somethingWrong = false;
        }
        printf("Enter Sell Price Of Book: ");
        scanf("%f", &sellPrice);
        if(sellPrice <= 0){
            printf("Sell Price Cannot Be <= 0.\n");
            somethingWrong = true;
            continue;
        }
        else{
            somethingWrong = false;
        }
    }
    
    fixExistingBooks(name, lot, lot, buyPrice, sellPrice);
    
    int howMuchCurrent = getCurrentHowMuch(name);
    if(howMuchCurrent == 0){
        howMuchCurrent = lot;
    }
    strcpy(bookToInsert.type, type);
    bookToInsert.lot = lot;
    bookToInsert.howMuchCurrent = howMuchCurrent;
    strcpy(bookToInsert.name, name);
    strcpy(bookToInsert.author, author);
    bookToInsert.buyPrice = buyPrice;
    bookToInsert.sellPrice = sellPrice;
    
    for(int counter = 0; counter < bookToInsert.lot; counter++){
        insertElementLast(bookToInsert, true);
        booksHere++;
    }
    saveToFile();
}

void getBookkeping(){
    FILE* filePointer;
    filePointer = fopen("bookkepping.txt", "r");
    
    char cash[100500];
    char booksSold[100500];
    fgets(cash, 100500, filePointer);
    fgets(booksSold, 100500, filePointer);
    
    howMuchCashForAllTime = strtod(cash, NULL);
    howMuchBooksSelledForAllTime = atol(booksSold);

    fclose(filePointer);
}

void saveBookkepping(){
    FILE* filePointer;
    filePointer = fopen("bookkepping.txt", "w");
    
    char cash[100500];
    char bookSold[100500];
    
    sprintf(cash, "%f", howMuchCashForAllTime += cleanProfit);
    sprintf(bookSold, "%ld", howMuchBooksSelledForAllTime += howMuchBooksSelled);
    
    fputs(cash, filePointer);
    fputs("\n", filePointer);
    fputs(bookSold, filePointer);
    
    fclose(filePointer);
}

int main() {
    
    Statement state = initial;
    char userInput = '\0';
    char password[100];
    
    while (true) {
        switch (state) {
            case initial:
                printf("Welcome To Book Shop.\n");
                printf("0 - Exit\n");
                printf("1 - Add Book Manually\n");
                printf("2 - Load From File\n");
                printf("Your Choice: ");
                fflush(stdin);
                scanf("%c", &userInput);
                printf("\n");
                
                switch (userInput) {
                    case '0':
                        getBookkeping();
                        saveBookkepping();
                        //warehouse();
                        return 0;
                        break;
                    case '1':
                        addBookMannually();
                        state = bookAreHere;
                        break;
                    case '2':
                        if(readFromFile()){
                            state = bookAreHere;
                        }
                        else{
                            printf("File Are Empty.\n\n");
                        }
                        break;
                    default:
                        printf("Incorrect Input.\n\n");
                        break;
                }
                break;
                
            case bookAreHere:
                printf("\n0 - Exit.\n");
                printf("1 - Add Book Manually\n");
                printf("2 - Sell Books\n");
                printf("3 - Info About Available Books\n");
                printf("4 - WAREHOUSE ADMINS-ONLY\n");
                printf("5 - CASHBOX ADMINS-ONLY\n");
                printf("6 - Logs\n");
                printf("Your Choice: ");
                fflush(stdin);
                scanf("%c", &userInput);
                printf("\n");
                
                switch (userInput) {
                    case '0':
                        printf("BookKepping Saved!\n");
                        //howMuchCashForAllTime += cleanProfit;
                        //howMuchBooksSelledForAllTime += howMuchBooksSelled;
                        //silentCashBox();
                        saveBookkepping();
                        return 0;
                        break;
                        
                    case '1':
                        addBookMannually();
                        //silentCashBox();
                        break;
                        
                    case '2':
                        sellBook();
                        //silentCashBox();
                        break;
                        
                    case '3':
                        getInfoAboutBooksForUser();
                        break;
                        
                    case '4':
                        printf("Admins-Only Zone. Enter Password: ");
                        scanf("%s", password);
                        if(strcmp(password, "password") == 0){
                            printf("Correct.\n");
                            warehouse();
                        }
                        else{
                            printf("Incorrect Input.\n\n");
                        }
                        break;
                        
                    case '5':
                        printf("Admins-Only Zone. Enter Password: ");
                        scanf("%s", password);
                        if(strcmp(password, "password") == 0){
                            printf("Correct.\n");
                            cashBox();
                        }
                        else{
                            printf("Incorrect Input.\n");
                        }
                        break;
                        
                    case '6':
                        printf("%s", logs);
                        break;
                    default:
                        printf("Incorrect Input");
                        break;
                }
                break;
            default:
                break;
        }
    }
    return 0;
}
