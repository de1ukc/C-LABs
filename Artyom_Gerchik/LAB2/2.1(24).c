//Task 2.1, Variant 24.
#include <stdio.h>
#include <stdbool.h>

enum Statement{
    NothingReady,
    ConnectionsReady,
    FloorsReady,
    CellingsReady,
    PartitionReady,
    AllReady
};
enum Statement realTimeStatement;

float oneMeterCablePrice = 1.5;
float oneSocketPrice = 1;
float oneConnectorPrice = 1;
float oneLockerPriceAndInstallationPrice = 143;
float oneCanalPrice = 20;

void calculateEquipmentAndPrices(float avgCableLenght, int numberOfConnections, int numberOfFloors, float heightOfCellings, float thicknessOfThePartition)
{
    float cableLenght = 0;

    int numberOfSockets = 0;
    int numberOfConnectors = 0;
    int numberOfLockers = 0;
    int numberOfCanals = 0;

    float cablePrice = 0;
    float socketsPrice = 0;
    float connectorsPrice = 0;
    float lockersPrice = 0;
    float canalsPrice = 0;
    float networkDesignPrice = 0;
    float finalPrice = 0;

    cableLenght = avgCableLenght * numberOfConnections +((numberOfFloors - 1) * (heightOfCellings + thicknessOfThePartition)) + (heightOfCellings / 2);

    numberOfSockets = numberOfConnections * 1;
    numberOfConnectors = numberOfConnections * 2;
    numberOfLockers = numberOfFloors * 1;
    numberOfCanals = numberOfFloors - 1;

    cablePrice = oneMeterCablePrice * cableLenght;
    socketsPrice = oneSocketPrice * numberOfSockets;
    connectorsPrice = oneConnectorPrice * numberOfConnectors;
    lockersPrice = oneLockerPriceAndInstallationPrice * numberOfLockers;
    canalsPrice = oneCanalPrice * numberOfCanals;
    networkDesignPrice = (cablePrice + socketsPrice + connectorsPrice + lockersPrice + canalsPrice) * 0.3;
    finalPrice = cablePrice + socketsPrice + connectorsPrice + lockersPrice + canalsPrice + networkDesignPrice;

    printf("Yours Preset:\n");
    printf("Number Of Connections: %d\n", numberOfConnections);
    printf("Number Of Floors: %d\n", numberOfFloors);
    printf("Height Of The Ceiling(meters): %.3f\n", heightOfCellings);
    printf("The Thickness Of The Partition(meters): %.3f\n", thicknessOfThePartition);
    printf("Average Length Of The Cable To The Point(meters): %.3f\n\n", avgCableLenght);

    printf("Full Lenght Of Cable:%.3f\n", cableLenght);
    printf("Sockets Need: %d\n", numberOfSockets);
    printf("Connectors Need: %d\n", numberOfConnectors);
    printf("Lockers Need: %d\n", numberOfLockers);
    printf("Canals Need: %d\n\n", numberOfCanals);

    printf("Cable Price: %.3f $\n", cablePrice);
    printf("Sockets Price: %.3f $\n", socketsPrice);
    printf("Connectors Price: %.3f $\n", connectorsPrice);
    printf("Lockers Price(installation included): %.3f $\n", lockersPrice);
    printf("Canals Price: %.3f $\n", canalsPrice);
    printf("Network Design Price: %.3f $\n", networkDesignPrice);
    printf("Final Price: %.3f $\n\n", finalPrice);

}

int main() {
    int userInputSwitch = 0;
    int numberOfConnections = 0;
    int numberOfFloors = 0;
    float heightOfCellings = 0;
    float thicknessOfThePartition = 0;
    float averageLengthOfTheCableToThePoint = 0;
    printf("AMP Greets You!\n\n");

    while(true)
    {
        switch (realTimeStatement) {
            case NothingReady:
                printf("0 - Exit.\n");
                printf("1 - Enter The Number Of Connections.\n");
                printf("2 - Info & Contacts AMP. \n\n");
                printf("Yours Choose: ");
                scanf("%d", &userInputSwitch);
                fflush(stdin); // buffer clearing
                printf("\n");

                switch (userInputSwitch) {
                    case 0:
                        printf("See You. Bye!\n");
                        return 0;
                        break;
                    case 1:
                        printf("Enter Number Of Connections: ");
                        scanf("%d", &numberOfConnections);
                        fflush(stdin);
                        realTimeStatement = ConnectionsReady;
                        break;
                    case 2:
                        printf("AMP: Solutions for Power\n\n");
                        printf("We are a premier manufacturer of standard and custom electrical distribution equipment products.\n\n");
                        printf ("Over the years, electrical consulting engineers, supply houses and contractors have requested A.M.P. products because of their innovative designs, ease of installation and dependability.\n\n");
                        printf("Contact Us: (763) 551.1555 | (800) 328.8658\n\n");
                        break;
                    default:
                        printf("Invalid Input. Try Again.\n");
                        break;
                }
                break;

            case ConnectionsReady:
                printf("0 - Exit.\n");
                printf("1 - Enter The Number Of Connections.\n");
                printf("2 - Enter The Number Of Floors.\n");
                printf("3 - Info & Contacts AMP. \n\n");
                printf("Yours Choose: ");
                scanf("%d", &userInputSwitch);
                fflush(stdin);
                printf("\n");

                switch (userInputSwitch) {
                    case 0:
                        printf("See You. Bye!\n");
                        return 0;
                        break;
                    case 1:
                        printf("Enter Number Of Connections: ");
                        scanf("%d", &numberOfConnections);
                        fflush(stdin);
                        break;
                    case 2:
                        printf("Enter Number Of Floors: ");
                        scanf("%d", &numberOfFloors);
                        fflush(stdin);
                        realTimeStatement = FloorsReady;
                        break;
                    case 3:
                        printf("AMP: Solutions for Power\n\n");
                        printf("We are a premier manufacturer of standard and custom electrical distribution equipment products.\n\n");
                        printf ("Over the years, electrical consulting engineers, supply houses and contractors have requested A.M.P. products because of their innovative designs, ease of installation and dependability.\n\n");
                        printf("Contact Us: (763) 551.1555 | (800) 328.8658\n\n");
                        break;
                    default:
                        printf("Invalid Input. Try Again.\n");
                        break;
                }
                break;

            case FloorsReady:
                printf("0 - Exit.\n");
                printf("1 - Enter The Number Of Connections.\n");
                printf("2 - Enter The Number Of Floors.\n");
                printf("3 - Enter The Height Of The Ceiling(meters).\n");
                printf("4 - Info & Contacts AMP. \n\n");
                printf("Yours Choose: ");
                scanf("%d", &userInputSwitch);
                fflush(stdin);
                printf("\n");

                switch (userInputSwitch) {
                    case 0:
                        printf("See You. Bye!\n");
                        return 0;
                        break;
                    case 1:
                        printf("Enter Number Of Connections: ");
                        scanf("%d", &numberOfConnections);
                        fflush(stdin);
                        break;
                    case 2:
                        printf("Enter Number Of Floors: ");
                        scanf("%d", &numberOfFloors);
                        fflush(stdin);
                        break;
                    case 3:
                        printf("Enter Height Of The Ceiling: ");
                        scanf("%f", &heightOfCellings);
                        fflush(stdin);
                        realTimeStatement = CellingsReady;
                        break;
                    case 4:
                        printf("AMP: Solutions for Power\n\n");
                        printf("We are a premier manufacturer of standard and custom electrical distribution equipment products.\n\n");
                        printf ("Over the years, electrical consulting engineers, supply houses and contractors have requested A.M.P. products because of their innovative designs, ease of installation and dependability.\n\n");
                        printf("Contact Us: (763) 551.1555 | (800) 328.8658\n\n");
                        break;
                    default:
                        printf("Invalid Input. Try Again.\n");
                        break;
                }
                break;

            case CellingsReady:
                printf("0 - Exit.\n");
                printf("1 - Enter The Number Of Connections.\n");
                printf("2 - Enter The Number Of Floors.\n");
                printf("3 - Enter The Height Of The Ceiling(meters).\n");
                printf("4 - Enter The Thickness Of The Partition(meters).\n");
                printf("5 - Info & Contacts AMP. \n\n");
                printf("Yours Choose: ");
                scanf("%d", &userInputSwitch);
                fflush(stdin);
                printf("\n");

                switch (userInputSwitch) {
                    case 0:
                        printf("See You. Bye!\n");
                        return 0;
                        break;
                    case 1:
                        printf("Enter Number Of Connections: ");
                        scanf("%d", &numberOfConnections);
                        fflush(stdin);
                        break;
                    case 2:
                        printf("Enter Number Of Floors: ");
                        scanf("%d", &numberOfFloors);
                        fflush(stdin);
                        break;
                    case 3:
                        printf("Enter Height Of The Ceiling: ");
                        scanf("%f", &heightOfCellings);
                        fflush(stdin);
                        break;
                    case 4:
                        printf("Enter Thickness Of The Partition: ");
                        scanf("%f", &thicknessOfThePartition);
                        fflush(stdin);
                        realTimeStatement = PartitionReady;
                        break;
                    case 5:
                        printf("AMP: Solutions for Power\n\n");
                        printf("We are a premier manufacturer of standard and custom electrical distribution equipment products.\n\n");
                        printf ("Over the years, electrical consulting engineers, supply houses and contractors have requested A.M.P. products because of their innovative designs, ease of installation and dependability.\n\n");
                        printf("Contact Us: (763) 551.1555 | (800) 328.8658\n\n");
                        break;
                    default:
                        printf("Invalid Input. Try Again.\n");
                        break;
                }
                break;

            case PartitionReady:
                printf("0 - Exit.\n");
                printf("1 - Enter The Number Of Connections.\n");
                printf("2 - Enter The Number Of Floors.\n");
                printf("3 - Enter The Height Of The Ceiling(meters).\n");
                printf("4 - Enter The Thickness Of The Partition(meters).\n");
                printf("5 - Enter The Average Length Of The Cable To The Point(meters).\n");
                printf("6 - Info & Contacts AMP. \n\n");
                printf("Yours Choose: ");
                scanf("%d", &userInputSwitch);
                fflush(stdin);
                printf("\n");

                switch (userInputSwitch) {
                    case 0:
                        printf("See You. Bye!\n");
                        return 0;
                        break;
                    case 1:
                        printf("Enter Number Of Connections: ");
                        scanf("%d", &numberOfConnections);
                        fflush(stdin);
                        break;
                    case 2:
                        printf("Enter Number Of Floors: ");
                        scanf("%d", &numberOfFloors);
                        fflush(stdin);
                        break;
                    case 3:
                        printf("Enter Height Of The Ceiling: ");
                        scanf("%f", &heightOfCellings);
                        fflush(stdin);
                        break;
                    case 4:
                        printf("Enter Thickness Of The Partition: ");
                        scanf("%f", &thicknessOfThePartition);
                        fflush(stdin);
                        break;
                    case 5:
                        printf("Enter Average Length Of The Cable To The Point: ");
                        scanf("%f", &averageLengthOfTheCableToThePoint);
                        fflush(stdin);
                        realTimeStatement = AllReady;
                        break;
                    case 6:
                        printf("AMP: Solutions for Power\n\n");
                        printf("We are a premier manufacturer of standard and custom electrical distribution equipment products.\n\n");
                        printf ("Over the years, electrical consulting engineers, supply houses and contractors have requested A.M.P. products because of their innovative designs, ease of installation and dependability.\n\n");
                        printf("Contact Us: (763) 551.1555 | (800) 328.8658\n\n");
                        break;
                    default:
                        printf("Invalid Input. Try Again.\n");
                        break;
                }
                break;

            case AllReady:
                printf("0 - Exit.\n");
                printf("1 - Enter The Number Of Connections.\n");
                printf("2 - Enter The Number Of Floors.\n");
                printf("3 - Enter The Height Of The Ceiling(meters).\n");
                printf("4 - Enter The Thickness Of The Partition(meters).\n");
                printf("5 - Enter The Average Length Of The Cable To The Point(meters).\n");
                printf("6 - Perform Calculations.\n");
                printf("7 - Info & Contacts AMP. \n\n");
                printf("Yours Choose: ");
                scanf("%d", &userInputSwitch);
                fflush(stdin);
                printf("\n");

                switch (userInputSwitch) {
                    case 0:
                        printf("See You. Bye!\n");
                        return 0;
                        break;
                    case 1:
                        printf("Enter Number Of Connections: ");
                        scanf("%d", &numberOfConnections);
                        fflush(stdin);
                        break;
                    case 2:
                        printf("Enter Number Of Floors: ");
                        scanf("%d", &numberOfFloors);
                        fflush(stdin);
                        break;
                    case 3:
                        printf("Enter Height Of The Ceiling: ");
                        scanf("%f", &heightOfCellings);
                        fflush(stdin);
                        break;
                    case 4:
                        printf("Enter Thickness Of The Partition: ");
                        scanf("%f", &thicknessOfThePartition);
                        fflush(stdin);
                        break;
                    case 5:
                        printf("Enter Average Length Of The Cable To The Point: ");
                        scanf("%f", &averageLengthOfTheCableToThePoint);
                        fflush(stdin);
                        break;
                    case 6:
                        calculateEquipmentAndPrices(averageLengthOfTheCableToThePoint, numberOfConnections, numberOfFloors, heightOfCellings, thicknessOfThePartition);
                        break;
                    case 7:
                        printf("AMP: Solutions for Power\n\n");
                        printf("We are a premier manufacturer of standard and custom electrical distribution equipment products.\n\n");
                        printf ("Over the years, electrical consulting engineers, supply houses and contractors have requested A.M.P. products because of their innovative designs, ease of installation and dependability.\n\n");
                        printf("Contact Us: (763) 551.1555 | (800) 328.8658\n\n");
                        break;
                    default:
                        printf("Invalid Input. Try Again.\n");
                        break;
                }
                break;


            default:
                break;
        }
    }

    return 0;
}
