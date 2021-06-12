//Задача 6.2(11) 
#include <stdio.h>
#include <malloc.h>
#include <string.h>
typedef struct restPlace
{
    int added;
    char name[100];
    char address[100];
    char activity[100];
    char time[100];
    char comment[1000];
} RestPlace;

typedef struct nodeRP
{
    RestPlace data;
    struct nodeRP* next;
    struct nodeRP* prev;
} NodeRP;

typedef struct restPlaces
{
    NodeRP* head;
    NodeRP* tail;
    int size;
} RestPlaces;

typedef struct monument
{
    int added;
    char name[100];
    char address[100];
    char description[1000];
    char comment[1000];
} Monument;

typedef struct nodeM
{
    Monument data;
    struct nodeM* next;
    struct nodeM* prev;
} NodeM;

typedef struct monuments
{
    NodeM* head;
    NodeM* tail;
    int size;
} Monuments;

typedef struct city
{
    int added;
    char name[100];
    RestPlaces restPlaces;
    Monuments monuments;
} City;

typedef struct nodeC
{
    City data;
    struct nodeC* next;
    struct nodeC* prev;
} NodeC;

typedef struct cities
{
    NodeC* head;
    NodeC* tail;
    int size;
} Cities;

RestPlaces RestPlacesCreate();
void RestPlacesAdd(RestPlaces* list, RestPlace data);
Monuments MonumentsCreate();
void MonumentsAdd(Monuments* list, Monument data);
Cities CitiesCreate();
void CitiesAdd(Cities* list, City data);
int ListCities(Cities cities, int check);
int CityPrint(Cities cities, char* name, int check, int hotel);
NodeC* FindCity(Cities cities, char* name);
int FindPlace(Cities cities, char* name);
void AddToBook(Cities* cities, char* name, char* comment);

int main()
{
    FILE* f;
    Cities cities;
    City city;
    RestPlace restPlace;
    Monument monument;
    char temp[1000];
    char str[100];
    char comment[1000];
    int i;
    int filling;
    int select;
    NodeC* node;
    NodeRP* node1;
    NodeM* node2;

    cities = CitiesCreate();
    city.restPlaces = RestPlacesCreate();
    city.monuments = MonumentsCreate();
    i = 0;
    filling = 0;
    select = 0;

    do
    {
        f = fopen("DataBase.txt", "r");

        if (f == NULL)
        {
            printf("Failed to open file!");
        }
    } while (f == NULL);

    while (1)
    {
        if (fgets(temp, 100, f) == NULL)
        {
            if (!feof(f))
            {
                printf("Error reading from file");
                fclose(f);
                return 0;
            }
            else
            {
                fclose(f);
                break;
            }
        }
        else
        {
            temp[strlen(temp) - 1] = '\0';

            if (strcmp(temp, "><") == 0)
            {
                select = 1;
            }
            else if (strcmp(temp, "<>") == 0)
            {
                filling = 0;
                select = 0;
                CitiesAdd(&cities, city);
                city.restPlaces = RestPlacesCreate();
                city.monuments = MonumentsCreate();
            }
            else
            {

                if (filling)
                {
                    if (select == 0)
                    {
                        i++;

                        if (i == 1)
                        {
                            restPlace.added = atoi(temp);
                        }
                        else if (i == 2)
                        {
                            strcpy(restPlace.name, temp);
                        }
                        else if (i == 3)
                        {
                            strcpy(restPlace.address, temp);
                        }
                        else if (i == 4)
                        {
                            strcpy(restPlace.activity, temp);
                        }
                        else if (i == 5)
                        {
                            strcpy(restPlace.time, temp);
                        }
                        else if (i == 6)
                        {
                            strcpy(restPlace.comment, temp);
                            i = 0;
                            RestPlacesAdd(&city.restPlaces, restPlace);
                        }
                    }
                    else
                    {
                        i++;

                        if (i == 1)
                        {
                            monument.added = atoi(temp);
                        }
                        else if (i == 2)
                        {
                            strcpy(monument.name, temp);
                        }
                        else if (i == 3)
                        {
                            strcpy(monument.address, temp);
                        }
                        else if (i == 4)
                        {
                            strcpy(monument.description, temp);
                        }
                        else if (i == 5)
                        {
                            strcpy(monument.comment, temp);
                            i = 0;
                            MonumentsAdd(&city.monuments, monument);
                        }
                    }
                }
                else
                {
                    i++;

                    if (i == 1)
                    {
                        city.added = atoi(temp);
                    }
                    else if (i == 2)
                    {
                        strcpy(city.name, temp);
                        i = 0;
                        filling = 1;
                    }
                }
            }
        }
    }

    system("cls");

    while (1)
    {
        printf("1 - Select a city\n2 - Find a hotel\n3 - Book\n0 - Exit\n");
        gets(temp);

        if (strcmp(temp, "1") == 0)
        {
            system("cls");

            while (1)
            {
                ListCities(cities, 0);
                printf("0 - Back\nEnter a city: ");
                gets(temp);
                system("cls");

                if (strcmp(temp, "0") == 0)
                {
                    break;
                }
                else
                {
                    if (FindCity(cities, temp) != NULL)
                    {
                        strcpy(str, temp);
                        system("cls");

                        while (1)
                        {
                            CityPrint(cities, str, 0, 0);
                            printf("0 - Back\nAdd to the book: ");
                            gets(temp);
                            system("cls");

                            if (strcmp(temp, "0") == 0)
                            {
                                break;
                            }
                            else
                            {
                                if (FindPlace(cities, temp))
                                {
                                    printf("Enter a comment: ");
                                    gets(comment);
                                    AddToBook(&cities, temp, comment);
                                    system("cls");
                                    printf("Added\n\n");
                                }
                                else
                                {
                                    printf("Place is not founded\n\n");
                                }
                            }
                        }
                    }
                    else
                    {
                        printf("City is not founded\n\n");
                    }
                }
            }
        }
        else if (strcmp(temp, "2") == 0)
        {
            system("cls");
            printf("Enter a city: ");
            gets(temp);
            system("cls");
            if (CityPrint(cities, temp, 0, 1) == 1)
            {
                printf("Hotel is not founded\n\n");
            }
        }
        else if (strcmp(temp, "3") == 0)
        {
            system("cls");

            while (1)
            {
                if (ListCities(cities, 1) == 1)
                {
                    printf("Book is empty\n\n");
                }

                printf("0 - Back\nEnter a city: ");
                gets(temp);
                system("cls");

                if (strcmp(temp, "0") == 0)
                {
                    break;
                }
                else
                {
                    CityPrint(cities, temp, 1, 0);
                }
            }
        }
        else if (strcmp(temp, "0") == 0)
        {
            f = fopen("DataBase.txt", "w");

            if (f == NULL)
            {
                printf("Failed to open!");
                return 0;
            }

            node = cities.head;

            while (node)
            {
                fprintf(f, "%d\n", node->data.added);
                fprintf(f, "%s\n", node->data.name);
                node1 = node->data.restPlaces.head;

                while (node1)
                {
                    fprintf(f, "%d\n", node1->data.added);
                    fprintf(f, "%s\n", node1->data.name);
                    fprintf(f, "%s\n", node1->data.address);
                    fprintf(f, "%s\n", node1->data.activity);
                    fprintf(f, "%s\n", node1->data.time);
                    fprintf(f, "%s\n", node1->data.comment);
                    node1 = node1->next;
                }

                fprintf(f, "><\n");
                node2 = node->data.monuments.head;

                while (node2)
                {
                    fprintf(f, "%d\n", node2->data.added);
                    fprintf(f, "%s\n", node2->data.name);
                    fprintf(f, "%s\n", node2->data.address);
                    fprintf(f, "%s\n", node2->data.description);
                    fprintf(f, "%s\n", node2->data.comment);
                    node2 = node2->next;
                }

                fprintf(f, "<>\n");
                node = node->next;
            }

            fclose(f);
            break;
        }
        else
        {
            system("cls");
        }
    }

    return 0;
}

RestPlaces RestPlacesCreate()
{
    RestPlaces list = { NULL, NULL, 0 };
    return list;
}

void RestPlacesAdd(RestPlaces* list, RestPlace data)
{
    NodeRP* node;

    node = (NodeRP*)malloc(sizeof(NodeRP));

    if (node == NULL)
    {
        printf("Not enough memory!");
        exit(0);
    }

    node->data = data;
    node->next = node->prev = NULL;

    if (list->head == NULL)
    {
        list->head = list->tail = node;
    }
    else
    {
        list->tail->next = node;
        node->prev = list->tail;
        list->tail = node;
    }

    list->size++;
}

Monuments MonumentsCreate()
{
    Monuments list = { NULL, NULL, 0 };
    return list;
}

void MonumentsAdd(Monuments* list, Monument data)
{
    NodeM* node;

    node = (NodeM*)malloc(sizeof(NodeM));

    if (node == NULL)
    {
        printf("Not enough memory!");
        exit(0);
    }

    node->data = data;
    node->next = node->prev = NULL;

    if (list->head == NULL)
    {
        list->head = list->tail = node;
    }
    else
    {
        list->tail->next = node;
        node->prev = list->tail;
        list->tail = node;
    }

    list->size++;
}

Cities CitiesCreate()
{
    Cities list = { NULL, NULL, 0 };
    return list;
}

void CitiesAdd(Cities* list, City data)
{
    NodeC* node;

    node = (NodeC*)malloc(sizeof(NodeC));

    if (node == NULL)
    {
        printf("Not enough memory!");
        exit(0);
    }

    node->data = data;
    node->next = node->prev = NULL;

    if (list->head == NULL)
    {
        list->head = list->tail = node;
    }
    else
    {
        list->tail->next = node;
        node->prev = list->tail;
        list->tail = node;
    }

    list->size++;
}

int ListCities(Cities cities, int check)
{
    NodeC* node;
    int ret;
    node = cities.head;
    ret = 0;

    if (check == 1)
    {
        ret = 1;
    }

    while (node)
    {
        if (node->data.added == 1 || node->data.added == check)
        {
            printf("%s\n", node->data.name);
            ret = 0;
        }

        node = node->next;
    }

    printf("\n");
    return ret;
}

NodeC* FindCity(Cities cities, char* name)
{
    NodeC* node;
    int finded;
    node = cities.head;
    finded = 0;

    while (node)
    {
        if (strcmp(node->data.name, name) == 0)
        {
            finded = 1;
            break;
        }

        node = node->next;
    }

    if (finded)
    {
        return node;
    }
    else
    {
        return NULL;
    }
}

int FindPlace(Cities cities, char* name)
{
    NodeC* node;
    NodeRP* node1;
    NodeM* node2;
    int finded;
    node = cities.head;
    finded = 0;

    while (node)
    {
        node1 = node->data.restPlaces.head;

        while (node1)
        {
            if (strcmp(node1->data.name, name) == 0)
            {
                finded = 1;
            }

            node1 = node1->next;
        }

        node2 = node->data.monuments.head;

        while (node2)
        {
            if (strcmp(node2->data.name, name) == 0)
            {
                finded = 1;
            }

            node2 = node2->next;
        }

        node = node->next;
    }

    return finded;
}

void AddToBook(Cities* cities, char* name, char* comment)
{
    NodeC* node;
    NodeRP* node1;
    NodeM* node2;
    node = cities->head;

    while (node)
    {
        node1 = node->data.restPlaces.head;

        while (node1)
        {
            if (strcmp(node1->data.name, name) == 0)
            {
                node->data.added = 1;
                node1->data.added = 1;
                strcpy(node1->data.comment, comment);
            }

            node1 = node1->next;
        }

        node2 = node->data.monuments.head;

        while (node2)
        {
            if (strcmp(node2->data.name, name) == 0)
            {
                node->data.added = 1;
                node2->data.added = 1;
                strcpy(node2->data.comment, comment);
            }

            node2 = node2->next;
        }

        node = node->next;
    }
}

int CityPrint(Cities cities, char* name, int check, int hotel)
{
    NodeC* node;
    NodeRP* node1;
    NodeM* node2;
    int ret;
    node = FindCity(cities, name);
    ret = 0;

    if (check == 0 && hotel == 1)
    {
        ret = 1;
    }

    if (node != NULL && (node->data.added == 1 || node->data.added == check))
    {
        printf("%s\n", node->data.name);
        node1 = node->data.restPlaces.head;

        while (node1)
        {
            if (strcmp(node1->data.activity, "Hotel") == 0 || hotel == 0)
            {
                if (node1->data.added == 1 || node1->data.added == check)
                {
                    printf("\tName: %s\n", node1->data.name);
                    printf("\tAddress: %s\n", node1->data.address);
                    printf("\tActivity: %s\n", node1->data.activity);
                    printf("\tWorking hours: %s\n", node1->data.time);

                    if (check)
                    {
                        printf("\tComment: %s\n", node1->data.comment);
                    }

                    printf("\n");
                    ret = 0;
                }
            }

            node1 = node1->next;
        }

        node2 = node->data.monuments.head;

        if (hotel == 0)
        {
            while (node2)
            {
                if (node2->data.added == 1 || node2->data.added == check)
                {
                    printf("\tName: %s\n", node2->data.name);
                    printf("\tAddress: %s\n", node2->data.address);
                    printf("\tDescription: %s\n", node2->data.description);

                    if (check)
                    {
                        printf("\tComment: %s\n", node2->data.comment);
                    }

                    printf("\n");
                    ret = 0;
                }

                node2 = node2->next;
            }
        }
    }

    return ret;
}
