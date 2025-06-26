#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Constants for better maintainability
#define MAX_YEARS 5
#define AGE_GROUPS 10
#define LOCATIONS 7
#define MAX_STRING 50
#define MAX_ATTEMPTS 3

// Structure definitions
typedef struct {
    char username[MAX_STRING];
    char password[MAX_STRING];
} User;

typedef struct {
    int census_age[MAX_YEARS][AGE_GROUPS];
    int census_location[MAX_YEARS][LOCATIONS];
    int years[MAX_YEARS];
} CensusData;

// Age group labels for better readability
const char* age_labels[AGE_GROUPS] = {
    "0-10", "11-20", "21-30", "31-40", "41-50",
    "51-60", "61-70", "71-80", "81-90", "91-130"
};

// Location labels
const char* location_labels[LOCATIONS] = {
    "Asia", "Africa", "Europe", "North America",
    "South America", "Australia", "Antarctica"
};

// Function prototypes
bool authenticate_user(void);
void input_census_data(CensusData* data);
void display_menu(void);
void display_age_data(const CensusData* data);
void display_location_data(const CensusData* data);
void display_summary_statistics(const CensusData* data);
void clear_input_buffer(void);
int get_valid_integer(const char* prompt, int min_val, int max_val);
void print_separator(int count);

int main() {
    printf("=== Enhanced Census Data Management System ===\n");
    printf("Console Display Version\n\n");
    
    // Authentication
    if (!authenticate_user()) {
        printf("Authentication failed. Exiting program.\n");
        return 1;
    }
    
    CensusData census;
    
    // Initialize years (2019-2023)
    for (int i = 0; i < MAX_YEARS; i++) {
        census.years[i] = 2019 + i;
    }
    
    // Input census data
    input_census_data(&census);
    
    // Display disclaimer
    printf("\n");
    print_separator(60);
    printf("DISCLAIMER: The census data entered here are for demonstration purposes only.\n");
    printf("For official census data, visit: https://www.census.gov/data.html\n");
    print_separator(60);
    printf("\n");
    
    // Main menu loop
    int choice;
    do {
        display_menu();
        choice = get_valid_integer("Enter your choice: ", 0, 4);
        
        switch (choice) {
            case 1:
                display_age_data(&census);
                break;
            case 2:
                display_location_data(&census);
                break;
            case 3:
                display_summary_statistics(&census);
                break;
            case 4:
                printf("Thank you for using the Census Data Management System!\n");
                break;
            case 0:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        
        if (choice != 0 && choice != 4) {
            printf("\nPress Enter to continue...");
            getchar();
        }
        
    } while (choice != 0 && choice != 4);
    
    return 0;
}

bool authenticate_user(void) {
    User setup, login;
    int attempts = 0;
    
    printf("=== User Setup ===\n");
    printf("Create your username: ");
    if (scanf("%49s", setup.username) != 1) {
        printf("Error reading username.\n");
        return false;
    }
    
    printf("Create your password: ");
    if (scanf("%49s", setup.password) != 1) {
        printf("Error reading password.\n");
        return false;
    }
    
    clear_input_buffer();
    
    printf("\n=== Login ===\n");
    
    while (attempts < MAX_ATTEMPTS) {
        printf("Username: ");
        if (scanf("%49s", login.username) != 1) {
            printf("Error reading username.\n");
            attempts++;
            continue;
        }
        
        printf("Password: ");
        if (scanf("%49s", login.password) != 1) {
            printf("Error reading password.\n");
            attempts++;
            continue;
        }
        
        clear_input_buffer();
        
        if (strcmp(setup.username, login.username) == 0 && 
            strcmp(setup.password, login.password) == 0) {
            printf("Authentication successful!\n\n");
            return true;
        } else {
            attempts++;
            printf("Invalid credentials. Attempts remaining: %d\n\n", MAX_ATTEMPTS - attempts);
        }
    }
    
    return false;
}

void input_census_data(CensusData* data) {
    printf("=== Census Data Input ===\n");
    printf("Please enter population data for each year and category.\n\n");
    
    for (int year = 0; year < MAX_YEARS; year++) {
        printf("--- Data for Year %d ---\n", data->years[year]);
        
        // Age group data
        printf("\nAge Group Data:\n");
        for (int age = 0; age < AGE_GROUPS; age++) {
            char prompt[100];
            snprintf(prompt, sizeof(prompt), "Population in age group %s: ", age_labels[age]);
            data->census_age[year][age] = get_valid_integer(prompt, 0, 2000000000);
        }
        
        // Location data
        printf("\nLocation Data:\n");
        for (int loc = 0; loc < LOCATIONS; loc++) {
            char prompt[100];
            snprintf(prompt, sizeof(prompt), "Population in %s: ", location_labels[loc]);
            data->census_location[year][loc] = get_valid_integer(prompt, 0, 2000000000);
        }
        
        printf("\nData entry completed for year %d\n", data->years[year]);
        if (year < MAX_YEARS - 1) {
            printf("Press Enter to continue to next year...");
            getchar();
        }
        printf("\n");
    }
}

void display_menu(void) {
    printf("\n=== Main Menu ===\n");
    printf("1. Display Census Data by Age Groups\n");
    printf("2. Display Census Data by Location\n");
    printf("3. Display Summary Statistics\n");
    printf("4. Exit Program\n");
    printf("0. Quick Exit\n");
}

void display_age_data(const CensusData* data) {
    printf("\n=== Census Data by Age Groups ===\n");
    printf("%-6s", "Year");
    for (int age = 0; age < AGE_GROUPS; age++) {
        printf("%-12s", age_labels[age]);
    }
    printf("\n");
    print_separator(100);
    
    for (int year = 0; year < MAX_YEARS; year++) {
        printf("%-6d", data->years[year]);
        for (int age = 0; age < AGE_GROUPS; age++) {
            printf("%-12d", data->census_age[year][age]);
        }
        printf("\n");
    }
}

void display_location_data(const CensusData* data) {
    printf("\n=== Census Data by Location ===\n");
    printf("%-6s", "Year");
    for (int loc = 0; loc < LOCATIONS; loc++) {
        printf("%-15s", location_labels[loc]);
    }
    printf("\n");
    print_separator(110);
    
    for (int year = 0; year < MAX_YEARS; year++) {
        printf("%-6d", data->years[year]);
        for (int loc = 0; loc < LOCATIONS; loc++) {
            printf("%-15d", data->census_location[year][loc]);
        }
        printf("\n");
    }
}

void display_summary_statistics(const CensusData* data) {
    printf("\n=== Summary Statistics ===\n");
    
    // Calculate totals for each year
    printf("Year-wise Total Population:\n");
    for (int year = 0; year < MAX_YEARS; year++) {
        long long total = 0;
        for (int age = 0; age < AGE_GROUPS; age++) {
            total += data->census_age[year][age];
        }
        printf("  %d: %lld\n", data->years[year], total);
    }
    
    // Calculate age group averages across all years
    printf("\nAverage Population by Age Group (across all years):\n");
    for (int age = 0; age < AGE_GROUPS; age++) {
        long long sum = 0;
        for (int year = 0; year < MAX_YEARS; year++) {
            sum += data->census_age[year][age];
        }
        printf("  %s: %.0f\n", age_labels[age], (double)sum / MAX_YEARS);
    }
    
    // Calculate location averages across all years
    printf("\nAverage Population by Location (across all years):\n");
    for (int loc = 0; loc < LOCATIONS; loc++) {
        long long sum = 0;
        for (int year = 0; year < MAX_YEARS; year++) {
            sum += data->census_location[year][loc];
        }
        printf("  %s: %.0f\n", location_labels[loc], (double)sum / MAX_YEARS);
    }
}

void clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int get_valid_integer(const char* prompt, int min_val, int max_val) {
    int value;
    int attempts = 0;
    
    while (attempts < 3) {
        printf("%s", prompt);
        if (scanf("%d", &value) == 1) {
            if (value >= min_val && value <= max_val) {
                clear_input_buffer();
                return value;
            } else {
                printf("Please enter a value between %d and %d.\n", min_val, max_val);
            }
        } else {
            printf("Invalid input. Please enter a number.\n");
            clear_input_buffer();
        }
        attempts++;
    }
    
    printf("Too many invalid attempts. Using default value 0.\n");
    return 0;
}

void print_separator(int count) {
    for (int i = 0; i < count; i++) {
        printf("=");
    }
    printf("\n");
}
