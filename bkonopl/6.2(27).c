#include <malloc.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int M = 20;

struct Crime {
    char place[20];
    char member[20];
    char afterMath[20];
    char comments[20];
    struct Crime *l,*r;
};
struct CrimeList {
    int size;
    struct Crime *head,*tail;
};

struct Gang{
    char name[20];
    char occupation[20];
    char rating[20];
    struct Gang *l,*r;
};
struct GangList {
    int size;
    struct Gang *head,*tail;
};

struct Criminal{
    char fio[20];
    char nickName[20];
    int height;
    int weight;
    char hairColor[20];
    char signs[20];
    char citizenship[20];
    char languages[20];
    char occupation[20];
    char crimes[20];
    char gangs[20];
    struct Criminal *l,*r;
};
struct CriminalList {
    int size;
    struct Criminal *head,*tail;
};


void AddCriminal(
    struct CriminalList *v,
    char* fio,
    char* nickName,
    char* height,
    char* weight,
    char* hairColor,
    char* signs,
    char* citizenship,
    char* languages,
    char* occupation,
    char* crimes,
    char* gangs
) {
    struct Criminal* cur;
    cur = (struct Criminal*)malloc(sizeof(struct Criminal));

    cur -> l = v -> tail;
    cur -> r = NULL;
    strcpy_s(cur -> fio, sizeof(cur -> fio), fio);
    strcpy_s(cur -> nickName, sizeof(cur -> nickName), nickName);
    cur -> height = height;
    cur -> weight = weight;
    strcpy_s(cur -> hairColor, sizeof(cur -> hairColor), hairColor);
    strcpy_s(cur -> signs, sizeof(cur -> signs), signs);
    strcpy_s(cur -> citizenship, sizeof(cur -> citizenship), citizenship);
    strcpy_s(cur -> languages, sizeof(cur -> languages), languages);
    strcpy_s(cur -> occupation, sizeof(cur -> occupation), occupation);
    strcpy_s(cur -> crimes, sizeof(cur -> crimes), crimes);
    strcpy_s(cur -> gangs, sizeof(cur -> gangs), gangs);

    if(v -> tail)
    {
        v -> tail -> r = cur;
        v -> tail = v -> tail -> r;
    }
    else
        v -> head = v -> tail = cur;
    v -> size++;
}
void DeleteCriminal(struct CriminalList *v, int index) {
    if(index < 0 || index >= v -> size) return;
    struct Criminal *cur = v -> head ;
    while(index--) {
        cur = cur -> r;
    }
    if(cur -> l) cur -> l -> r = cur -> r;
    if(cur -> r) cur -> r -> l = cur -> l;
    free(cur);
    v -> size--;
}
void RecoveredCriminal(struct CriminalList *v) {
    if(v == NULL) return;
    struct Criminal *cur = v -> head;
    while(cur) {
        if(cur -> r){
            cur = cur -> r;
        } else {
            free(cur);
            break;
        }
        if(cur -> l) free(cur -> l);
    }
}
void LoadCriminal(struct CriminalList *v) {
    FILE *file;
    RecoveredCriminal(v);

    fopen_s(&file, "Criminals.txt", "r");
    if(!file) exit(1);
    char fio[20];
    char nickName[20];
    char height[20];
    char weight[20];
    char hairColor[20];
    char signs[20];
    char citizenship[20];
    char languages[20];
    char occupation[20];
    char crimes[20];
    char gangs[20];
    while(fgets(fio, 20, file))
    {
        fgets(nickName, 20, file);
        fgets(height, 20, file);
        fgets(weight, 20, file);
        fgets(hairColor, 20, file);
        fgets(signs, 20, file);
        fgets(citizenship, 20, file);
        fgets(languages, 20, file);
        fgets(occupation, 20, file);
        fgets(crimes, 20, file);
        fgets(gangs, 20, file);
        AddCriminal(v, fio, nickName, atoi(height), atoi(weight), hairColor, signs, citizenship, languages, occupation, crimes, gangs);
    }
    fclose(file);
}
void SaveCriminal(struct CriminalList * v) {
    FILE *file;
    fopen_s(&file, "Criminals1.txt", "w");
    struct Criminal *temp = v -> head;

    if(!file || ! (temp)) exit(1);
    while(temp)
    {
        char weight[4], height[4];
        _itoa_s(temp -> weight, weight, sizeof(weight) , 10);
        _itoa_s(temp -> height, height, sizeof(height), 10);

        fputs(temp -> fio, file);
        fputs(temp -> nickName, file);
        fputs(height, file);
        fputs("\n", file);
        fputs(weight, file);
        fputs("\n", file);
        fputs(temp -> hairColor, file);
        fputs(temp -> signs, file);
        fputs(temp -> citizenship, file);
        fputs(temp -> languages, file);
        fputs(temp -> occupation, file);
        fputs(temp -> crimes, file);
        fputs(temp -> gangs, file);

        temp = temp -> r;
    }
    fclose(file);
}
void PrintCriminal(struct Criminal *temp) {
    char weight[4], height[4];
    _itoa_s(temp -> height, height, sizeof(height), 10);
    _itoa_s(temp -> weight, weight, sizeof(weight), 10);
    puts(temp -> fio);
    puts(temp -> nickName);
    puts(height);
    puts(weight);
    puts(temp -> hairColor);
    puts(temp -> signs);
    puts(temp -> citizenship);
    puts(temp -> languages);
    puts(temp -> occupation);
    puts(temp -> crimes);
    puts(temp -> gangs);
    puts("\n");
}
void ShowCriminals(struct CriminalList *v) {
    struct Criminal *temp = v -> head;
    while(temp)
    {
        PrintCriminal(temp);
        temp = temp -> r;
    }
    puts("\n");
}

void AddCrime(
    struct CrimeList *v,
    char place[],
    char member[],
    char afterMath[],
    char comments[]
) {
    struct Crime* cur;
    cur = (struct Crime*)malloc(sizeof(struct Crime));

    cur -> l = v -> tail;
    cur -> r = NULL;
    strcpy_s(cur -> place, sizeof(cur -> place), place);
    strcpy_s(cur -> member, sizeof(cur -> member), member);
    strcpy_s(cur -> afterMath, sizeof(cur -> afterMath), afterMath);
    strcpy_s(cur -> comments, sizeof(cur -> comments), comments);

    if(v -> tail)
    {
        v -> tail -> r = cur;
        v -> tail = v -> tail -> r;
    }
    else
        v -> head = v -> tail = cur;
    v -> size++;
}
void DeleteCrime(struct CrimeList *v, int index) {
    if(index < 0 || index >= v -> size) return;
    struct Crime *cur = v -> head ;
    while(index--) {
        cur = cur -> r;
    }
    if(cur -> l) cur -> l -> r = cur -> r;
    if(cur -> r) cur -> r -> l = cur -> l;
    free(cur);
    v -> size--;
}
void RecoveredCrime(struct CrimeList *v) {
    if(v == NULL) return;
    struct Crime *cur = v -> head;
    while(cur) {
        if(cur -> r){
            cur = cur -> r;
        } else {
            free(cur);
            break;
        }
        if(cur -> l) free(cur -> l);
    }
}
void LoadCrime(struct CrimeList *v) {
    FILE *file;
    RecoveredCrime(v);

    fopen_s(&file, "Crimes.txt", "r");
    if(!file) exit(1);
    char place[20];
    char member[20];
    char afterMath[20];
    char comments[20];
    while(fgets(place, 20, file))
    {
        fgets(member, 20, file);
        fgets(afterMath, 20, file);
        fgets(comments, 20, file);
        AddCrime(v, place, member, afterMath, comments);
    }
    fclose(file);
}
void SaveCrime(struct CrimeList * v) {
    FILE *file;
    fopen_s(&file, "Crimes1.txt", "w");
    struct Crime *temp = v -> head;

    if(!file || ! (temp)) exit(1);
    while(temp)
    {
        fputs(temp -> place, file);
        fputs(temp -> member, file);
        fputs(temp -> afterMath, file);
        fputs(temp -> comments, file);
        temp = temp -> r;
    }
    fclose(file);
}
void PrintCrime(struct Crime *temp) {
    puts(temp -> place);
    puts(temp -> member);
    puts(temp -> afterMath);
    puts(temp -> comments);
    puts("\n");
}
void ShowCrime(struct CrimeList *v) {
    struct Crime *temp = v -> head;
    while(temp)
    {
        PrintCriminal(temp);
        temp = temp -> r;
    }
    puts("\n");
}

void AddGang(
    struct GangList *v,
    char name[20],
    char occupation[20],
    char rating[20]
) {
    struct Gang* cur;
    cur = (struct Gang*)malloc(sizeof(struct Gang));

    cur -> l = v -> tail;
    cur -> r = NULL;
    strcpy_s(cur -> name, sizeof(cur -> name), name);
    strcpy_s(cur -> occupation, sizeof(cur -> occupation), occupation);
    strcpy_s(cur -> rating, sizeof(cur -> rating), rating);

    if(v -> tail)
    {
        v -> tail -> r = cur;
        v -> tail = v -> tail    -> r;
    }
    else
        v -> head = v -> tail = cur;
    v -> size++;
}
void DeleteGang(struct GangList *v, int index) {
    if(index < 0 || index >= v -> size) return;
    struct Gang *cur = v -> head ;
    while(index--) {
        cur = cur -> r;
    }
    if(cur -> l) cur -> l -> r = cur -> r;
    if(cur -> r) cur -> r -> l = cur -> l;
    free(cur);
    v -> size--;
}
void RecoveredGang(struct GangList *v) {
    if(v == NULL) return;
    struct Gang *cur = v -> head;
    while(cur) {
        if(cur -> r){
            cur = cur -> r;
        } else {
            free(cur);
            break;
        }
        if(cur -> l) free(cur -> l);
    }
}
void LoadGang(struct GangList *v) {
    FILE *file;
    RecoveredGang(v);

    fopen_s(&file, "Gangs.txt", "r");
    if(!file) exit(1);
    char name[20];
    char occupation[20];
    char rating[20];
    while(fgets(name, 20, file))
    {
        fgets(occupation, 20, file);
        fgets(rating, 20, file);
        AddGang(v, name, occupation, rating);
    }
    fclose(file);
}
void SaveGang(struct GangList * v) {
    FILE *file;
    fopen_s(&file, "Crimes1.txt", "w");
    struct Gang *temp = v -> head;

    if(!file || ! (temp)) exit(1);
    while(temp)
    {
        fputs(temp -> name, file);
        fputs(temp -> occupation, file);
        fputs(temp -> rating, file);
        temp = temp -> r;
    }
    fclose(file);
}
void PrintGang(struct Gang *temp) {
    puts(temp -> name);
    puts(temp -> occupation);
    puts(temp -> rating);
    puts("\n");
}
void ShowGang(struct GangList *v) {
    struct Gang *temp = v -> head;
    while(temp)
    {
        PrintGang(temp);
        temp = temp -> r;
    }
    puts("\n");
}

void SearchCriminalfio(struct CriminalList *v, char fio[20]) {
    struct Criminal *temp = v -> head;
    if(!temp) return;
    while (temp -> r) {
        if(!strcmp(temp -> fio, fio)) {
            PrintCriminal(temp);
            temp  = temp -> r;
        }
        else
            temp = temp -> r;
    }
}
void SearchCriminalnickName(struct CriminalList *v, char nickName[20]){
    struct Criminal *temp = v -> head;
    if(!temp) return;
    while (temp -> r) {
        if(!strcmp(temp -> nickName, nickName)) {
            PrintCriminal(temp);
            temp  = temp -> r;
        }
        else
            temp = temp -> r;
    }
}
void SearchCriminalheight(struct CriminalList *v, int height){
    struct Criminal *temp = v -> head;
    if(!temp) return;
    while (temp -> r) {
        if(temp -> height == height) {
            PrintCriminal(temp);
            temp  = temp -> r;
        }
        else
            temp = temp -> r;
    }
}
void SearchCriminalweight(struct CriminalList *v, char weight){
    struct Criminal *temp = v -> head;
    if(!temp) return;
    while (temp -> r) {
        if(temp -> weight == weight) {
            PrintCriminal(temp);
            temp  = temp -> r;
        }
        else
            temp = temp -> r;
    }
}
void SearchCriminalhairColor(struct CriminalList *v, char hairColor[20]){
    struct Criminal *temp = v -> head;
    if(!temp) return;
    while (temp -> r) {
        if(!strcmp(temp -> hairColor, hairColor)) {
            PrintCriminal(temp);
            temp  = temp -> r;
        }
        else
            temp = temp -> r;
    }
}
void SearchCriminalsigns(struct CriminalList *v, char signs[20]){
    struct Criminal *temp = v -> head;
    if(!temp) return;
    while (temp -> r) {
        if(!strcmp(temp -> signs, signs)) {
            PrintCriminal(temp);
            temp  = temp -> r;
        }
        else
            temp = temp -> r;
    }
}
void SearchCriminalcitizenship(struct CriminalList *v, char citizenship[20]){
    struct Criminal *temp = v -> head;
    if(!temp) return;
    while (temp -> r) {
        if(!strcmp(temp -> citizenship, citizenship)) {
            PrintCriminal(temp);
            temp  = temp -> r;
        }
        else
            temp = temp -> r;
    }
}
void SearchCriminallanguages(struct CriminalList *v, char languages[20]){
    struct Criminal *temp = v -> head;
    if(!temp) return;
    while (temp -> r) {
        if(!strcmp(temp -> languages, languages)) {
            PrintCriminal(temp);
            temp  = temp -> r;
        }
        else
            temp = temp -> r;
    }
}
void SearchCriminaloccupation(struct CriminalList *v, char occupation[20]){
    struct Criminal *temp = v -> head;
    if(!temp) return;
    while (temp -> r) {
        if(!strcmp(temp -> occupation, occupation)) {
            PrintCriminal(temp);
            temp  = temp -> r;
        }
        else
            temp = temp -> r;
    }
}
void SearchCriminalcrimes(struct CriminalList *v, char crimes[20]){
    struct Criminal *temp = v -> head;
    if(!temp) return;
    while (temp -> r) {
        if(!strcmp(temp -> crimes, crimes)) {
            PrintCriminal(temp);
            temp  = temp -> r;
        }
        else
            temp = temp -> r;
    }
}
void SearchCriminalgangs(struct CriminalList *v, char gangs[20]){
    struct Criminal *temp = v -> head;
    if(!temp) return;
    while (temp -> r) {
        if(!strcmp(temp -> gangs, gangs)) {
            PrintCriminal(temp);
            temp  = temp -> r;
        }
        else
            temp = temp -> r;
    }
}

void SearchGangname(struct GangList *v, char name[20]){
    struct Gang *temp = v -> head;
    if(!temp) return;
    while (temp -> r) {
        if(!strcmp(temp -> name, name)) {
            PrintGang(temp);
            temp  = temp -> r;
        }
        else
            temp = temp -> r;
    }
}
void SearchGangoccupation(struct CriminalList *v, char occupation[20]){
    struct Gang *temp = v -> head;
    if(!temp) return;
    while (temp -> r) {
        if(!strcmp(temp -> occupation, occupation)) {
            PrintGang(temp);
            temp  = temp -> r;
        }
        else
            temp = temp -> r;
    }
}
void SearchGangrating(struct CriminalList *v, char rating[20]){
    struct Gang *temp = v -> head;
    if(!temp) return;
    while (temp -> r) {
        if(!strcmp(temp -> rating, rating)) {
            PrintGang(temp);
            temp  = temp -> r;
        }
        else
            temp = temp -> r;
    }
}

void SearchCrimeplace(struct CrimeList *v, char place[20]){
    struct Crime *temp = v -> head;
    if(!temp) return;
    while (temp -> r) {
        if(!strcmp(temp -> place, place)) {
            PrintGang(temp);
            temp  = temp -> r;
        }
        else
            temp = temp -> r;
    }
}
void SearchCrimemember(struct CrimeList *v, char member[20]){
    struct Crime *temp = v -> head;
    if(!temp) return;
    while (temp -> r) {
        if(!strcmp(temp -> member, member)) {
            PrintGang(temp);
            temp  = temp -> r;
        }
        else
            temp = temp -> r;
    }
}
void SearchCrimeafterMath(struct CrimeList *v, char afterMath[20]){
    struct Crime *temp = v -> head;
    if(!temp) return;
    while (temp -> r) {
        if(!strcmp(temp -> afterMath, afterMath)) {
            PrintGang(temp);
            temp  = temp -> r;
        }
        else
            temp = temp -> r;
    }
}
void SearchCrimecomments(struct CrimeList *v, char comments[20]){
    struct Crime *temp = v -> head;
    if(!temp) return;
    while (temp -> r) {
        if(!strcmp(temp -> comments, comments)) {
            PrintGang(temp);
            temp  = temp -> r;
        }
        else
            temp = temp -> r;
    }
}

void menushka() {
    struct CrimeList *crimeBase;
    crimeBase = (struct CrimeList*)malloc(sizeof(struct CrimeList));
    crimeBase -> size = 0;
    crimeBase -> head = crimeBase -> tail =  NULL;

    struct GangList *orgBase;
    orgBase = (struct GangList*)malloc(sizeof(struct GangList));
    orgBase -> size = 0;
    orgBase -> head = orgBase -> tail = NULL;

    struct CriminalList *criminalBase;
    criminalBase = (struct CriminalList*)malloc(sizeof(struct CriminalList));
    criminalBase -> size = 0;
    criminalBase -> tail = criminalBase -> head = NULL;

    LoadCrime(crimeBase);
    LoadGang(orgBase);
    LoadCriminal(criminalBase);
    puts("Welcome to Interpol base");
    while(1) {
        puts("\n");
        printf("%s", "Choose type:\n 1) Add\n 2) Show\n 3) Delete\n 4) Find\n 5) Exit\nChoose type: ");
        int type;
        scanf("%d", &type);
        puts("\n");
        switch(type) {
            case 1: {
                printf("%s", "Choose directory:\n 1) Crime\n 2) Gang\n 3) Criminal\n 4) Exit\nChoose type: ");
                int x;
                scanf("%d", &x);
                switch(x){
                    case 1:{
                        char place[20];
                        char member[20];
                        char afterMath[20];
                        char comments[20];
                        gets(place);
                        gets(member);
                        gets(afterMath);
                        gets(comments);
                        AddCrime(crimeBase, place, member, afterMath, comments);
                        break;
                    }
                    case 2:{
                        char name[20];
                        char occupation[20];
                        char rating[20];
                        gets(name);
                        gets(occupation);
                        gets(rating);
                        AddGang(orgBase, name, occupation, rating);
                        break;
                    }
                    case 3:{
                        char fio[20];
                        char nickName[20];
                        int height,weight;
                        char hairColor[20];
                        char signs[20];
                        char citizenship[20];
                        char languages[20];
                        char occupation[20];
                        char crimes[20];
                        char gangs[20];
                        gets(fio);
                        gets(nickName);
                        scanf("%d", &weight);
                        scanf("%d", &height);
                        gets(hairColor);
                        gets(signs);
                        gets(citizenship);
                        gets(languages);
                        gets(occupation);
                        gets(crimes);
                        gets(gangs);
                        AddCriminal(criminalBase, fio, nickName, height, weight, hairColor, signs, citizenship, languages, occupation, crimes, gangs);
                        break;
                    }
                    case 4:{
                        break;
                    }
                    default: {
                        puts("Incorrect Enter");
                    }
                }
                break;
            }
            case 2: {
                printf("%s", "Choose directory:\n 1) Crime\n 2) Gang\n 3) Criminal\n 4) Exit\nChoose type: ");
                int x;
                scanf("%d", &x);
                switch(x){
                    case 1:{
                        ShowCrime(crimeBase);
                        break;
                    }
                    case 2:{
                        ShowGang(orgBase);
                        break;
                    }
                    case 3:{
                        ShowCriminals(criminalBase);
                        break;
                    }
                    case 4:{
                        break;
                    }
                    default: {
                        puts("Incorrect Enter");
                    }
                }
                break;
            }
            case 3: {
                printf("%s", "Choose directory:\n 1) Crime\n 2) Gang\n 3) Criminal\n 4) Exit\nChoose type: ");
                int x;
                scanf("%d", &x);
                switch(x){
                    case 1:{
                        RecoveredCrime(crimeBase);
                        break;
                    }
                    case 2:{
                        RecoveredGang(orgBase);
                        break;
                    }
                    case 3:{
                        RecoveredCriminal(criminalBase);
                        break;
                    }
                    case 4:{
                        break;
                    }
                    default: {
                        puts("Incorrect Enter");
                    }
                }
                break;
            }
            case 4: {
                printf("%s", "Choose directory:\n 1) Crime\n 2) Gang\n 3) Criminal\n 4) Exit\nChoose type: ");
                int x;
                scanf("%d", &x);
                switch(x) {
                    case 1: {
                        printf("%s", "Chose field:\n 1) place\n 2) member\n 3) aftermath\n 4) comments\n 5) Exit\nChoose field: ");
                        int y;
                        scanf("%d", y);
                        switch(y) {
                            case 1: {
                                printf("%s", "place: ");
                                char temp[20];
                                scanf("%s", &temp);
                                SearchCrimeplace(crimeBase, temp);
                                break;
                            }
                            case 2: {
                                printf("%s", "member: ");
                                char temp[20];
                                scanf("%s", &temp);
                                SearchCrimemember(crimeBase, temp);
                                break;
                            }
                            case 3: {
                                printf("%s", "aftermath: ");
                                char temp[20];
                                scanf("%s", &temp);
                                SearchCrimeafterMath(crimeBase, temp);
                                break;
                            }
                            case 4: {
                                printf("%s", "comments: ");
                                char temp[20];
                                scanf("%s", &temp);
                                SearchCrimecomments(crimeBase, temp);
                                break;
                            }
                            case 5: {
                                break;
                            }
                            default: {
                                puts("Incorrect enter");
                            }
                        }
                        break;
                    }
                    case 2: {
                        printf("%s", "Chose field:\n 1) name\n 2) occupation\n 3) rating\n 4) Exit\nChoose field: ");
                        int y;
                        scanf("%d", y);
                        switch(y) {
                            case 1: {
                                printf("%s", "name: ");
                                char temp[20];
                                scanf("%s", &temp);
                                SearchGangname(crimeBase, temp);
                                break;
                            }
                            case 2: {
                                printf("%s", "occupation: ");
                                char temp[20];
                                scanf("%s", &temp);
                                SearchGangoccupation(crimeBase, temp);
                                break;
                            }
                            case 3: {
                                printf("%s", "rating: ");
                                char temp[20];
                                scanf("%s", &temp);
                                SearchGangrating(crimeBase, temp);
                                break;
                            }
                            case 4: {
                                break;
                            }
                            default: {
                                puts("Incorrect enter");
                            }
                        }
                        break;
                    }
                    case 3: {
                        printf("%s", "Chose field:\n 1) fio\n 2) nickName\n 3) height\n 4) weight\n 5) hairColor\n 6) signs\n 7) citizenship\n 8) languages\n 9) occupation\n 10) crimes\n 11) gangs \n 12) Exit\nChoose field: ");
                        int y;
                        scanf("%d", y);
                        switch(y) {
                            case 1: {
                                printf("%s", "fio: ");
                                char temp[20];
                                scanf("%s", &temp);
                                SearchCriminalfio(crimeBase, temp);
                                break;
                            }
                            case 2: {
                                printf("%s", "nickName: ");
                                char temp[20];
                                scanf("%s", &temp);
                                SearchCriminalnickName(crimeBase, temp);
                                break;
                            }
                            case 3: {
                                printf("%s", "height: ");
                                int temp;
                                scanf("%s", &temp);
                                SearchCriminalheight(crimeBase, temp);
                                break;
                            }
                            case 4: {
                                printf("%s", "weight: ");
                                int temp;
                                scanf("%s", &temp);
                                SearchCriminalweight(crimeBase, temp);
                                break;
                            }
                            case 5: {
                                printf("%s", "hairColor: ");
                                char temp[20];
                                scanf("%s", &temp);
                                SearchCriminalhairColor(crimeBase, temp);
                                break;
                            }
                            case 6: {
                                printf("%s", "signs: ");
                                char temp[20];
                                scanf("%s", &temp);
                                SearchCriminalsigns(crimeBase, temp);
                                break;
                            }
                            case 7: {
                                printf("%s", "citizenship: ");
                                char temp[20];
                                scanf("%s", &temp);
                                SearchCriminalcitizenship(crimeBase, temp);
                                break;
                            }
                            case 8: {
                                printf("%s", "languages: ");
                                char temp[20];
                                scanf("%s", &temp);
                                SearchCriminallanguages(crimeBase, temp);
                                break;
                            }
                            case 9: {
                                printf("%s", "occupation: ");
                                char temp[20];
                                scanf("%s", &temp);
                                SearchCriminaloccupation(crimeBase, temp);
                                break;
                            }
                            case 10: {
                                printf("%s", "crimes: ");
                                char temp[20];
                                scanf("%s", &temp);
                                SearchCriminalcrimes(crimeBase, temp);
                                break;
                            }
                            case 11: {
                                printf("%s", "gangs: ");
                                char temp[20];
                                scanf("%s", &temp);
                                SearchCriminalgangs(crimeBase, temp);
                                break;
                            }
                            case 12: {
                                break;
                            }
                            default: {
                                puts("Incorrect enter");
                            }

                        }
                    }
                    default: {
                        puts("Incorrect enter");
                    }

                    }
                    break;
                }
            case 5: {
                SaveCriminal(criminalBase);
                SaveCrime(crimeBase);
                SaveGang(orgBase);
                return;
            }
            default: {
                puts("Incorrect enter!");
            }
        }
    }
}
int main() {
    menushka();
    return 0;
}
