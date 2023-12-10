                                            //SOFTWARE FOR GEU BADMINTON TOURNAMENT ADMINSTRATION.........

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TOTAL_PLAYERS 2
#define MALE_PLAYERS 15
#define FEMALE_PLAYERS 15
#define DOUBLE_ENTRIES 16
#define MIXED_DOUBLE_ENTRIES 16
#define ENTRY_FEE 250

typedef struct
{
    char name[50];
    int age;
    char gender;
    char nationality[50];
    bool isInternational;
    bool isSingle;
    bool isDouble;
    bool isMixedDouble;
    bool isValid;
} Player;

int main()
{
    Player players[TOTAL_PLAYERS];
    int maleCount = 0, femaleCount = 0, doubleCount = 0, mixedDoubleCount = 0;

    printf("Welcome to GEU Badminton Tournament Administration Software\n");

    for (int i = 0; i < TOTAL_PLAYERS; i++)
    {
        printf("\nEntering details for Player %d:\n", i + 1);

        printf("Name without space: ");
        scanf("%s", players[i].name);

        printf("Age between 18-25: ");
        scanf("%d", &players[i].age);

        printf("Gender (M/F): ");
        scanf(" %c", &players[i].gender);

        printf("Nationality: ");
        scanf("%s", players[i].nationality);

        printf("Is International (1 for Yes / 0 for No): ");
        scanf("%d", &players[i].isInternational);

        players[i].isValid = (players[i].age >= 18 && players[i].age <= 25 &&((players[i].gender == 'M','m' && maleCount < MALE_PLAYERS) ||
                             (players[i].gender == 'F','f' && femaleCount < FEMALE_PLAYERS) ||
                             (players[i].isInternational && (maleCount + femaleCount) < TOTAL_PLAYERS)));

        if (players[i].isValid)
        {
            // Update counts based on gender and event type......


            if (players[i].gender == 'M','m')
            {
                maleCount++;
            }
            else
            {
                femaleCount++;
            }

            // Entry type single,double,mixed......


            printf("Enter 1 for Single, 2 for Double, 3 for Mixed Double: ");


            int entryType;

            scanf("%d", &entryType);

            switch (entryType)

            {

            case 1:

                players[i].isSingle = true;

                break;

            case 2:

                if (doubleCount < DOUBLE_ENTRIES)

                {

                    players[i].isDouble = true;
                    doubleCount++;
                }
                else
                {
                    printf("Maximum Double entries reached. Not eligible for Double event.\n");
                }
                break;

            case 3:

                if (mixedDoubleCount < MIXED_DOUBLE_ENTRIES)
                {
                    players[i].isMixedDouble = true;
                    mixedDoubleCount++;
                }
                else
                {
                    printf("Maximum Mixed Double entries reached. Not eligible for Mixed Double event.\n");
                }
                break;

            default:

                printf("Invalid entry type. Not eligible for any event.\n");
            }
        }
        else
        {
            printf("Player is not eligible based on age, gender, or nationality.\n");
        }
    }

    // Display entered players
    printf("Entered Players:\n");
    for (int i = 0; i < TOTAL_PLAYERS; i++)
    {
        if (players[i].isValid){
printf("Player %d: %s, Age: %d, Gender: %c, Nationality: %s\n", i + 1,players[i].name,
players[i].age, players[i].gender, players[i].nationality);
            if (players[i].isSingle) printf("   - Single Event\n");
            if (players[i].isDouble) printf("   - Double Event\n");
            if (players[i].isMixedDouble) printf("   - Mixed Double Event\n");
        }
    }

    // Calculate and display total entry fees
    int totalEntryFees = 0;
    for (int i = 0; i < TOTAL_PLAYERS; i++)
    {
        if (players[i].isValid)
        {
            totalEntryFees += ENTRY_FEE;
        }
    }
    printf("\nTotal Entry Fees Collected: %d RS\n", totalEntryFees);
    printf("CREATOR OF THIS CODE: KRISHNA RAWAT ");

    return 0;
}
