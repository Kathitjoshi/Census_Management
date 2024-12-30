#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char username[20], password[20], name[20], pass[20]; //Declaration of variables
    printf("Enter the username you want to set: "); //Module 4(Security Module)
    scanf("%s", username);
    system("pause");
    printf("Enter the password you want to set: ");
    scanf("%s", password);
    printf("Enter the username: ");
    scanf("%s", name);
    printf("Enter the password: ");
    scanf("%s", pass);

    if (strcmp(username, name) == 0 && strcmp(password, pass) == 0) //Module 4's checking condition
    {
        int census_age[5][10], census_location[5][7]; //Module 2(Data storage module)
        int year[5] = {2019, 2020, 2021, 2022, 2023};
        for (int i = 0; i < 5; i++) //Module 1(Data Input Module)
        {
            printf("Enter the Census Data for year %d \n", year[i]);
            printf("\nEnter the no of people in age group of 0-10:");
            scanf("%d", &census_age[i][0]);
            printf("\nEnter the no of people in age group of 11-20:");
            scanf("%d", &census_age[i][1]);
            printf("\nEnter the no of people in age group of 21-30:");
            scanf("%d", &census_age[i][2]);
            printf("\nEnter the no of people in age group of 31-40:");
            scanf("%d", &census_age[i][3]);
            printf("\nEnter the no of people in age group of 41-50:");
            scanf("%d", &census_age[i][4]);
            printf("\nEnter the no of people in age group of 51-60:");
            scanf("%d", &census_age[i][5]);
            printf("\nEnter the no of people in age group of 61-70:");
            scanf("%d", &census_age[i][6]);
            printf("\nEnter the no of people in age group of 71-80:");
            scanf("%d", &census_age[i][7]);
            printf("\nEnter the no of people in age group of 81-90:");
            scanf("%d", &census_age[i][8]);
            printf("\nEnter the no of people in age group of 91-130:");
            scanf("%d", &census_age[i][9]);

            printf("\nEnter the no of people in location 1(Asia):");
            scanf("%d", &census_location[i][0]);
            printf("\nEnter the no of people in location 2(Africa):");
            scanf("%d", &census_location[i][1]);
            printf("\nEnter the no of people in location 3(Europe):");
            scanf("%d", &census_location[i][2]);
            printf("\nEnter the no of people in location 4(North America):");
            scanf("%d", &census_location[i][3]);
            printf("\nEnter the no of people in location 5(South America):");
            scanf("%d", &census_location[i][4]);
            printf("\nEnter the no of people in location 6(Australia):");
            scanf("%d", &census_location[i][5]);
            printf("\nEnter the no of people in location 7(Antarctica):");
            scanf("%d", &census_location[i][6]);
        }
        printf("Disclaimer:The Census data inputted here are dummy values as this is a mini project and It is difficult to input the values accurately for each year according to the two categories since it is tedious and time-consuming so please refrain from using this as your go-to census management data and use this link for the same https://www.census.gov/data.html\n");
        printf("Menu\n"); //Module 3(Data Display and Statistical Ananlysis Module)
        printf("1.Display the Census Data based on age groups\n");
        printf("2.Display the Census Data based on location\n");
        int choice;
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Census Data based on age groups\n");
            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    printf("The no of people in age group %d for year %d is %d\n", j + 1, year[i], census_age[i][j]);
                }
            }
            break;
        case 2:
            printf("Census Data based on location\n");
            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 7; j++)
                {
                    printf("The no of people in location %d for year %d is %d\n", j + 1, year[i], census_location[i][j]);
                }
            }
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
    else
    {
        printf("Invalid username or password\n");
    }
    system("pause"); // Add this line to pause the console window
    return 0;
}
