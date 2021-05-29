#include <stdio.h>
#include <math.h>
#include <string.h>
#include <malloc.h>

#define MaxStringSize 100
#define MaxArraySize 100

struct Car {
    char status[MaxStringSize];
    char brand[MaxStringSize];
    int year;

    double engineVolume;
    double enginePower;

    int seatCount;
    int cost;
    int costFromDealer;
};
typedef struct Car Car;

int getCostForSell(const Car *car) {
    int cost = car->cost;

    double koef = 0;
    if (car->year <= 3) {
        koef = 0.35;
    } else if (car->year <= 10) {
        if (car->engineVolume < 2.5) {
            koef = 0.35;
        } else {
            koef = 0.6;
        }
    } else if (car->year < 14) {
        koef = 0.6;
    } else {
        koef = 2.;
    }

    double costByEngineVolume = car->engineVolume * koef;

    double fullCost = cost + costByEngineVolume;

    // add 15%
    fullCost += fullCost * 15. / 100.;

    return ceil(fullCost);
}

Car *createCar(char *status, char *brand, int year, double engineVolume, double enginePower, int seatCount, int cost) {
    Car *car = malloc(sizeof(Car));

    strcpy(car->status, status);
    strcpy(car->brand, brand);

    car->year = year;

    car->engineVolume = engineVolume;
    car->enginePower = enginePower;

    car->seatCount = seatCount;
    car->cost = cost;
    car->costFromDealer = getCostForSell(car);

    return car;
}

void printCar(Car *car) {
    printf("Car information:\n");
    printf("Status: %s\n", car->status);
    printf("Brand: %s\n", car->brand);
    printf("Age: %d\n", car->year);
    printf("Engine volume: %f\n", car->engineVolume);
    printf("Engine power: %f\n", car->enginePower);
    printf("Seat count: %d\n", car->seatCount);
    printf("Basic cost: %d\n", car->cost);
    printf("Cost by dealer: %d\n", getCostForSell(car));
}

void printCarToFile(Car *car, FILE *file) {
    fprintf(file,"%s\n", car->status);
    fprintf(file,"%s\n", car->brand);
    fprintf(file,"%d\n", car->year);
    fprintf(file,"%f\n", car->engineVolume);
    fprintf(file,"%f\n", car->enginePower);
    fprintf(file,"%d\n", car->seatCount);
    fprintf(file,"%d\n", car->cost);
}

struct UserQuery {
    char name[MaxStringSize];
    char phone[MaxStringSize];

    char desiredStatus[MaxStringSize];
    char desiredBrand[MaxStringSize];

    int maxCost;
};

typedef struct UserQuery UserQuery;

UserQuery *createUserQuery(char *name, char *phone, char *desiredStatus, char *desiredBrand, int maxCost) {
    UserQuery *userQuery = malloc(sizeof(UserQuery));

    strcpy(userQuery->name, name);
    strcpy(userQuery->phone, phone);
    strcpy(userQuery->desiredStatus, desiredStatus);
    strcpy(userQuery->desiredBrand, desiredBrand);

    userQuery->maxCost = maxCost;

    return userQuery;
}

void printUserQuery(UserQuery *userQuery) {
    printf("\n");
    printf("User query information:\n");
    printf("Name: %s\n", userQuery->name);
    printf("Phone: %s\n", userQuery->phone);
    printf("Desired status: %s\n", userQuery->desiredStatus);
    printf("Desired brand: %s\n", userQuery->desiredBrand);
    printf("Max cost: %d\n", userQuery->maxCost);
    printf("\n");
}

void printUserQueryToFile(UserQuery *userQuery, FILE *file) {
    fprintf(file,"%s\n", userQuery->name);
    fprintf(file,"%s\n", userQuery->phone);
    fprintf(file,"%s\n", userQuery->desiredStatus);
    fprintf(file,"%s\n", userQuery->desiredBrand);
    fprintf(file,"%d\n", userQuery->maxCost);
}



struct OrderList {
    int size;

    Car *carArray[MaxArraySize];
    UserQuery *userQueryArray[MaxArraySize];
};
typedef struct OrderList OrderList;

OrderList *createOrderList() {
    OrderList *orderList = malloc(sizeof(OrderList));

    orderList->size = 0;

    return orderList;
}

void addOrderList(OrderList* orderList, Car *car, UserQuery *userQuery) {
    orderList->carArray[orderList->size] = car;
    orderList->userQueryArray[orderList->size] = userQuery;

    orderList->size += 1;
}

void printOrderList(OrderList *orderList) {
    printf("//// Order list: ////\n");

    for(int i = 0; i < orderList->size; i++) {
        printf("----Index: %d ----\n", i);

        printCar(orderList->carArray[i]);
        printUserQuery(orderList->userQueryArray[i]);

        printf("---- end ----\n");
    }

    printf("//// end ////\n");
}

void printOrderListToFile(OrderList *orderList, FILE *file) {

    for(int i = 0; i < orderList->size; i++) {
        printCarToFile(orderList->carArray[i], file);
        printUserQueryToFile(orderList->userQueryArray[i], file);

        fprintf(file, "\n");
    }
}

void saveOrderList(OrderList *orderList) {
    FILE *file = fopen("../db/orderList.txt", "w+");

    fprintf(file, "%d\n", orderList->size);
    printOrderListToFile(orderList, file);

    fclose(file);
}





struct CarShop {
    int size;
    Car *carArray[MaxArraySize];
};
typedef struct CarShop CarShop;

CarShop *createCarShop() {
    CarShop *carShop = malloc(sizeof(CarShop));

    carShop->size = 0;

    return carShop;
}

void addCar(CarShop *carShop, Car *car) {
    carShop->carArray[carShop->size] = car;
    carShop->size += 1;
}

void deleteCar(CarShop *carShop, int index) {
    for(int i = index; i < carShop->size - 1; i++) {
        carShop->carArray[i] = carShop->carArray[i + 1];
    }

    carShop->size -= 1;
}

void sortCarByCost(CarShop *carShop) {
    for(int i = 0; i < carShop->size; i++) {
        for(int j = 0; j < carShop->size - 1 - i; j++) {
            if (carShop->carArray[j]->costFromDealer > carShop->carArray[j + 1]->costFromDealer) {
                Car *temp = carShop->carArray[j];

                carShop->carArray[j] = carShop->carArray[j + 1];
                carShop->carArray[j + 1] = temp;
            }
        }
    }
}

void findCarByUserStatus(CarShop *carShop, UserQuery *userQuery) {
    printf("||||Result:||||\n");
    for(int i = 0; i < carShop->size; i++) {
        if (strcmp(carShop->carArray[i]->status, userQuery->desiredStatus) == 0) {
            printf("####Index: %d ####\n", i);
            printCar(carShop->carArray[i]);
            printf("####   end ####");
        }
    }
    printf("|||| end ||||");
}

void findCarByUserBrand(CarShop *carShop, UserQuery *userQuery) {
    printf("||||Result:||||\n");
    for(int i = 0; i < carShop->size; i++) {
        if (strcmp(carShop->carArray[i]->brand, userQuery->desiredBrand) == 0) {
            printf("####Index: %d ####\n", i);
            printCar(carShop->carArray[i]);
            printf("####   end ####");
        }
    }
    printf("|||| end ||||");
}

void findCarByUserCost(CarShop *carShop, UserQuery *userQuery) {
    printf("||||Result:||||\n");
    for(int i = 0; i < carShop->size; i++) {
        if (carShop->carArray[i]->costFromDealer <= userQuery->maxCost) {
            printf("####Index: %d ####\n", i);
            printCar(carShop->carArray[i]);
            printf("####   end ####");
        }
    }
    printf("|||| end ||||");
}

void printCarShop(CarShop *carShop) {
    printf("----Car shop:----\n");
    for(int i = 0; i < carShop->size; i++) {
        printf("&&&& Index: %d &&&&\n", i);
        printCar(carShop->carArray[i]);
        printf("&&&& end &&&&\n");
    }
    printf("----    End    ----\n");
}

void printCarShopToFile(CarShop *carShop, FILE *file) {
    for(int i = 0; i < carShop->size; i++) {
        printCarToFile(carShop->carArray[i], file);
        fprintf(file, "\n");
    }
}

void saveCarShop(CarShop *carShop) {
    FILE *file = fopen("../db/carShop.txt", "w+");

    fprintf(file, "%d\n", carShop->size);

    printCarShopToFile(carShop, file);

    fclose(file);
}


struct UserRequests {
    int size;
    UserQuery *userArray[MaxArraySize];
};
typedef struct UserRequests UserRequests;

UserRequests *createUserRequests() {
    UserRequests *userRequests = malloc(sizeof(UserRequests));

    userRequests->size = 0;

    return userRequests;
}

void addRequest(UserRequests *userRequests, UserQuery *userQuery) {
    userRequests->userArray[userRequests->size] = userQuery;
    userRequests->size += 1;
}

void deleteRequest(UserRequests *userRequests, int index) {
    for(int i = index; i < userRequests->size - 1; i++) {
        userRequests->userArray[i] = userRequests->userArray[i + 1];
    }

    userRequests->size -= 1;
}

void printUserRequests(UserRequests *userRequests) {
    printf("++++User requests: ++++\n");
    for(int i = 0; i < userRequests->size; i++) {
        printf("===== Index: %d ====\n", i);
        printUserQuery(userRequests->userArray[i]);
        printf("==== end ====\n");
    }
    printf("++++ end ++++");
}

void printUserRequestsToFile(UserRequests *userRequests, FILE *file) {
    for(int i = 0; i < userRequests->size; i++) {
        printUserQueryToFile(userRequests->userArray[i], file);
        fprintf(file, "\n");
    }
}

void saveUserRequests(UserRequests *userRequests) {
    FILE *file = fopen("../db/userRequests.txt", "w+");

    fprintf(file, "%d\n", userRequests->size);
    printUserRequestsToFile(userRequests, file);

    fclose(file);
}

void makeDeal(CarShop *carShop, UserRequests *userRequests, OrderList *orderList, int indexCar, int indexUser) {
    addOrderList(orderList, carShop->carArray[indexCar], userRequests->userArray[indexUser]);

    deleteCar(carShop, indexCar);
    deleteRequest(userRequests, indexUser);
}


UserQuery *readUser() {
    char name[100];
    printf("Enter name:\n");
    scanf("%s", name);

    char phone[100];
    printf("Enter phone:\n");
    scanf("%s", phone);

    char desiredStatus[100];
    printf("Enter desired status:\n");
    scanf("%s", desiredStatus);

    char desiredBrand[100];
    printf("Enter desired brand:\n");
    scanf("%s", desiredBrand);

    int cost;
    printf("Enter max cost:\n");
    scanf("%d", &cost);

    return createUserQuery(name, phone, desiredStatus, desiredBrand, cost);
}

UserQuery *readUserFromFile(FILE *file) {
    char name[100];
    fscanf(file,"%s", name);

    char phone[100];
    fscanf(file,"%s", phone);

    char desiredStatus[100];
    fscanf(file,"%s", desiredStatus);

    char desiredBrand[100];
    fscanf(file,"%s", desiredBrand);

    int cost;
    fscanf(file,"%d", &cost);

    return createUserQuery(name, phone, desiredStatus, desiredBrand, cost);
}

Car *readCar() {
    char status[100];
    printf("Enter status:\n");
    scanf("%s", status);

    char brand[100];
    printf("Enter brand:\n");
    scanf("%s", brand);

    int year;
    printf("Enter year:\n");
    scanf("%d", &year);

    double engineVolume;
    printf("Enter engine volume:\n");
    scanf("%lf", &engineVolume);

    double enginePower;
    printf("Enter engine power:\n");
    scanf("%lf", &enginePower);

    int seatCount;
    printf("Enter seat count:\n");
    scanf("%d", &seatCount);

    int cost;
    printf("Enter cost:\n");
    scanf("%d", &cost);

    return createCar(status, brand, year, engineVolume, enginePower, seatCount, cost);
}

Car *readCarFromFile(FILE *file) {
    char status[100];
    fscanf(file,"%s", status);

    char brand[100];
    fscanf(file,"%s", brand);

    int year;
    fscanf(file,"%d", &year);

    double engineVolume;
    fscanf(file,"%lf", &engineVolume);

    double enginePower;
    fscanf(file,"%lf", &enginePower);

    int seatCount;
    fscanf(file,"%d", &seatCount);

    int cost;
    fscanf(file,"%d", &cost);

    return createCar(status, brand, year, engineVolume, enginePower, seatCount, cost);
}

void readFromFileCarShop(CarShop *carShop) {
    FILE *file = fopen("../db/carShop.txt", "r");

    int n;
    fscanf(file, "%d", &n);

    for(int i = 0; i < n; i++) {
        Car *car = readCarFromFile(file);

        addCar(carShop, car);
    }

    fclose(file);
}

void readFromFileUserRequests(UserRequests *userRequests) {
    FILE *file = fopen("../db/userRequests.txt", "r");

    int n;
    fscanf(file, "%d", &n);

    for(int i = 0; i < n; i++) {
        addRequest(userRequests, readUserFromFile(file));
    }

    fclose(file);
}

void readFromFileOrderList(OrderList *orderList) {
    FILE *file = fopen("../db/orderList.txt", "r");

    int n;
    fscanf(file, "%d", &n);

    printf("orderList n: %d\n", n);

    for(int i = 0; i < n; i++) {
        Car *car = readCarFromFile(file);
        UserQuery *userQuery = readUserFromFile(file);

        printUserQuery(userQuery);

        addOrderList(orderList, car, userQuery);
    }

    fclose(file);
}

void readFromFile(CarShop *carShop, UserRequests *userRequests, OrderList *orderList) {
    free(carShop);
    free(userRequests);
    free(orderList);

    carShop = createCarShop();
    userRequests = createUserRequests();
    orderList = createOrderList();

    readFromFileCarShop(carShop);
    readFromFileUserRequests(userRequests);
    readFromFileOrderList(orderList);
}

int main() {
    int isMainMenu = 1;
    int isCarMenu = 0;
    int isUserMenu = 0;
    int isOrderMenu = 0;

    CarShop *carShop = createCarShop();
    UserRequests *userRequests = createUserRequests();
    OrderList  *orderList = createOrderList();

    FILE *file = fopen("../db/carShop.txt", "r");

    if (file == NULL) {
        saveCarShop(carShop);
        saveUserRequests(userRequests);
        saveOrderList(orderList);
    }

    fclose(file);

    while(1) {

        if (isMainMenu) {
            printf("Enter 1 for move to car menu\n");
            printf("Enter 2 for move to user query menu\n");
            printf("Enter 3 for move to order list menu\n");
            printf("Enter 4 to load from files\n");
            printf("Enter 5 to exit\n");

            int type;
            scanf("%d", &type);

            isMainMenu = 0;

            switch (type) {
                case 1:
                    isCarMenu = 1;
                    break;
                case 2:
                    isUserMenu = 1;
                    break;
                case 3:
                    isOrderMenu = 1;
                    break;
                case 4:
                    isMainMenu = 1;

                    readFromFile(carShop, userRequests, orderList);
                    break;
                default:
                    break;
            }

            if (type == 5) {
                break;
            }

            printf("\n\n");
        }

        if (isCarMenu) {
            printf("Type 1 for move to main menu\n");
            printf("Type 2 for add car\n");
            printf("Type 3 for sort cars by cost\n");
            printf("Type 4 for print cars\n");
            printf("Type 5 for delete car\n");

            int type;
            scanf("%d", &type);

            int index;
            switch (type) {
                case 1:
                    isMainMenu = 1;
                    isCarMenu = 0;
                    break;
                case 2:
                    addCar(carShop, readCar());
                    break;
                case 3:
                    sortCarByCost(carShop);
                    break;
                case 4:
                    printCarShop(carShop);
                    break;
                case 5:
                    printf("Enter index:\n");
                    scanf("%d", &index);

                    deleteCar(carShop, index);
                    break;
                default:
                    break;
            }

            printf("\n\n");

        }

        if (isUserMenu) {
            printf("Type 1 for move to main menu\n");
            printf("Type 2 for add user query\n");
            printf("Type 3 find car by brand for user\n");
            printf("Type 4 find car by status for user\n");
            printf("Type 5 find car by cost for user\n");
            printf("Type 6 for print users\n");
            printf("Type 7 for delete user\n");
            printf("Type 8 for make deal\n");

            int type;
            scanf("%d", &type);

            int index;
            int indexCar;
            switch (type) {
                case 1:
                    isMainMenu = 1;
                    isUserMenu = 0;
                    break;
                case 2:
                    addRequest(userRequests, readUser());
                    break;
                case 3:
                    printf("Enter user index:\n");
                    scanf("%d", &index);

                    printf("@@@@Selected user@@@@\n");
                    printUserQuery(userRequests->userArray[index]);
                    printf("@@@@ end @@@@\n\n\n");

                    findCarByUserBrand(carShop, userRequests->userArray[index]);
                    break;
                case 4:
                    printf("Enter index:\n");
                    scanf("%d", &index);

                    printf("@@@@Selected user@@@@\n");
                    printUserQuery(userRequests->userArray[index]);
                    printf("@@@@ end @@@@\n\n\n");

                    findCarByUserStatus(carShop, userRequests->userArray[index]);
                    break;
                case 5:
                    printf("Enter index:\n");
                    scanf("%d", &index);

                    printf("@@@@Selected user@@@@\n");
                    printUserQuery(userRequests->userArray[index]);
                    printf("@@@@ end @@@@\n\n\n");

                    findCarByUserCost(carShop, userRequests->userArray[index]);
                    break;
                case 6:
                    printUserRequests(userRequests);
                    break;
                case 7:
                    printf("Enter index:\n");
                    scanf("%d", &index);

                    deleteRequest(userRequests, index);
                    break;
                case 8:
                    printf("Enter index User:\n");
                    scanf("%d", &index);

                    printf("Enter index Car:\n");
                    scanf("%d", &indexCar);

                    makeDeal(carShop, userRequests, orderList, indexCar, index);
                default:
                    break;
            }

            printf("\n\n");
        }

        if (isOrderMenu) {
            printf("Type 1 for move to main menu\n");
            printf("Type 2 for print order list\n");

            int type;
            scanf("%d", &type);

            switch (type) {
                case 1:
                    isMainMenu = 1;
                    isOrderMenu = 0;
                    break;
                case 2:
                    printOrderList(orderList);

            }
        }

        saveCarShop(carShop);
        saveUserRequests(userRequests);
        saveOrderList(orderList);
    }

    return 0;
}
