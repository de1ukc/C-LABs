#include <stdio.h>
#include <time.h>
#include <malloc.h>

const int payForDay = 400 / 30;

struct Date {
    int day;
    int month;
    int year;
};

struct tm DateToTm(struct Date date) {
    struct tm timeInfo;

    timeInfo.tm_year = date.year - 1900;
    timeInfo.tm_mon = date.month - 1;
    timeInfo.tm_mday = date.day;

    timeInfo.tm_hour = 0;
    timeInfo.tm_min = 0;
    timeInfo.tm_sec = 0;

    return timeInfo;
}

double getSecondsBetween(struct Date dateBegin, struct Date dateEnd) {
    struct tm timeStart = DateToTm(dateBegin);
    struct tm timeEnd = DateToTm(dateEnd);

    int begin = mktime(&timeStart);
    int end = mktime(&timeEnd);

    return difftime(end, begin) + (60 * 60 * 24);
}

int getWeekday(struct Date date) {
    struct tm timeInfo = DateToTm(date);

    mktime(&timeInfo);

    return timeInfo.tm_wday;
}

int main() {

    struct Date dateBegin, dateEnd;

    dateBegin.year = -1;
    int developerCount = -1;

    double payForDay = 400. / 30.;
    double profitPerHour = 9.;
    double percentOfExpenses = 250.;
    int clearProfit;

    int calcProfit = -1;

    while(1) {
        printf("\n");

        printf("menu:\n");
        printf("1. Enter project date\n");
        printf("2. Enter developer count\n");
        printf("3. Print project duration\n");
        printf("4. Calc profit\n");
        printf("5. Is optimal take project?\n");
        printf("6. Info about author\n");
        printf("7. Exit\n");

        printf("\n");

        int type;
        scanf("%d", &type);

        if (type == 1) {
            calcProfit = -1;

            printf("Enter date begin in format dd:mm:year\n");
            scanf("%d %d %d", &dateBegin.day, &dateBegin.month, &dateBegin.year);

            printf("Enter date end in format dd:mm:year\n");
            scanf("%d %d %d", &dateEnd.day, &dateEnd.month, &dateEnd.year);

            printf("\n");
        }

        if (type == 2) {
            calcProfit = -1;

            printf("Enter developer count:");
            scanf("%d", &developerCount);

            printf("\n");

        }

        if (type == 3) {

            if (dateBegin.year == -1) {
                printf("Enter project duration before do it\n");
                continue;
            }

            int secondsBetween = (int)getSecondsBetween(dateBegin, dateEnd);

            int days = secondsBetween / 60 / 60 / 24;

            int _days = days;
            int workdays = days;
            int dayOrder = getWeekday(dateBegin);

            dayOrder--;

            if (dayOrder < 0) {
                dayOrder = 6;
            }

            int firstWeek = 7;
            if (days < 7) {
                firstWeek = days;
            }

            if (dayOrder == 6) {
                workdays -= (firstWeek / 1 > 0);
            }
            else {
                workdays -= ((firstWeek / (7 - dayOrder)) > 0);
                workdays -= ((firstWeek / (6 - dayOrder)) > 0);
            }

            _days -= firstWeek;

            workdays -= _days / 7;
            workdays -= _days / 6;
            workdays += _days / (7 * 6);


            printf("This project duration is:\n");
            printf("Days:%d\n", days);
            printf("Workdays:%d\n", workdays);
        }

        if (type == 4) {
            calcProfit = 1;

            if (developerCount == -1) {
                printf("Enter developers before do it\n");
                continue;
            }

            int days = getSecondsBetween(dateBegin, dateEnd) / 60 / 60 / 24;

            int payForDevops = payForDay * developerCount * days;
            int profit = profitPerHour * days * 24.;

            int expenses = payForDevops * (percentOfExpenses / 100.);

            clearProfit = profit - payForDevops - expenses;

            printf("Payment for devops:%d\n", payForDevops);
            printf("Expenses:%d\n", expenses);
            printf("Profit for project:%d\n", profit);
            printf("Clear profit:%d\n", clearProfit);
        }

        if (type == 5) {
            if (calcProfit == -1) {
                printf("Calc profit before it\n");
                continue;
            }

            printf("Clear profit for project:%d\n", clearProfit);

            if (clearProfit < 1000) {
                printf("Project isn`t optimal\n");
            }
            else {
                printf("Project is optimal\n");

            }
        }

        if (type == 6) {
            printf("by theboatman\n");
            printf("zxc?\n");
        }

        if (type == 7) {
            printf("bye");
            break;
        }

    }

    return 0;
}
