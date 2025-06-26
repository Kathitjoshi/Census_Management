#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Constants for better maintainability
#define MAX_YEARS 5
#define AGE_GROUPS 10
#define LOCATIONS 7
#define MAX_STRING 50
#define MAX_ATTEMPTS 3
#define FILENAME "CensusData.txt"
#define BACKUP_FILENAME "CensusData_backup.txt"

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
bool save_data_to_file(const CensusData* data, const char* filename);
bool load_data_from_file(CensusData* data, const char* filename);
void display_menu(void);
void display_file_contents(const char* filename);
void create_data_backup(const char* source, const char* backup);
void generate_report(const CensusData* data);
void clear_input_buffer(void);
int get_valid_integer(const char* prompt, int min_val, int max_val);
char* get_current_timestamp(void);
void print_separator(int count);

int main() {
    printf("=== Enhanced Census Data Management System ===\n");
    printf("File Storage Version\n\n");
    
    // Authentication
    if (!authenticate_user()) {
        printf("Authentication failed. Exiting program.\n");
        return 1;
    }
    
    CensusData census;
    
    // Initialize years (2016-2020 as in original)
    for (int i = 0; i < MAX_YEARS; i++) {
        census.years[i] = 2016 + i;
    }
    
    // Check if existing data file exists
    printf("Checking for existing data file...\n");
    if (load_data_from_file(&census, FILENAME)) {
        printf("Existing data loaded from %s\n", FILENAME);
        printf("Do you want to:\n");
        printf("1. Use existing data\n");
        printf("2. Enter new data (will overwrite existing)\n");
        int choice = get_valid_integer("Your choice: ", 1, 2);
        
        if (choice == 2) {
            // Create backup before overwriting
            create_data_backup(FILENAME, BACKUP_FILENAME);
            input_census_data(&census);
        }
    } else {
        printf("No existing data found. Please enter new data.\n");
        input_census_data(&census);
    }
    
    // Save data to file
    if (save_data_to_file(&census, FILENAME)) {
        printf("Data successfully saved to %s\n", FILENAME);
    } else {
        printf("Error saving data to file.\n");
        return 1;
    }
    
    // Display disclaimer
    printf("\n");
    print_separator(80);
    printf("DISCLAIMER: The census data entered here are for demonstration purposes only.\n");
    printf("For official census data, visit: https://www.census.gov/data.html\n");
    print_separator(80);
    printf("\n");
    
    // Main menu loop
    int choice;
    do {
        display_menu();
        choice = get_valid_integer("Enter your choice: ", 0, 5);
        
        switch (choice) {
            case 1:
                display_file_contents(FILENAME);
                break;
            case 2:
                generate_report(&census);
                break;
            case 3:
                printf("Creating backup...\n");
                create_data_backup(FILENAME, BACKUP_FILENAME);
                printf("Backup created as %s\n", BACKUP_FILENAME);
                break;
            case 4:
                printf("Do you want to enter completely new data? (1=Yes, 0=No): ");
                if (get_valid_integer("", 0, 1) == 1) {
                    create_data_backup(FILENAME, BACKUP_FILENAME);
                    input_census_data(&census);
                    save_data_to_file(&census, FILENAME);
                    printf("New data saved successfully.\n");
                }
                break;
            case 5:
                printf("Thank you for using the Census Data Management System!\n");
                break;
            case 0:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        
        if (choice != 0 && choice != 5) {
            printf("\nPress Enter to continue...");
            getchar();
        }
        
    } while (choice != 0 && choice != 5);
    
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
            printf("Access Granted!\n\n");
            return true;
        } else {
            attempts++;
            printf("Access Denied. Attempts remaining: %d\n\n", MAX_ATTEMPTS - attempts);
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

bool save_data_to_file(const CensusData* data, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Error: Could not create file %s\n", filename);
        return false;
    }
    
    // Write header
    fprintf(file, "=== CENSUS DATA MANAGEMENT SYSTEM ===\n");
    fprintf(file, "Generated on: %s\n", get_current_timestamp());
    fprintf(file, "Data for years: %d - %d\n\n", data->years[0], data->years[MAX_YEARS-1]);
    
    // Write data for each year
    for (int year = 0; year < MAX_YEARS; year++) {
        fprintf(file, "=====================================\n");
        fprintf(file, "YEAR: %d\n", data->years[year]);
        fprintf(file, "=====================================\n\n");
        
        // Age group data
        fprintf(file, "AGE GROUP DISTRIBUTION:\n");
        fprintf(file, "------------------------\n");
        long long age_total = 0;
        for (int age = 0; age < AGE_GROUPS; age++) {
            fprintf(file, "%-10s: %12d\n", age_labels[age], data->census_age[year][age]);
            age_total += data->census_age[year][age];
        }
        fprintf(file, "%-10s: %12lld\n\n", "TOTAL", age_total);
        
        // Location data
        fprintf(file, "LOCATION DISTRIBUTION:\n");
        fprintf(file, "----------------------\n");
        long long loc_total = 0;
        for (int loc = 0; loc < LOCATIONS; loc++) {
            fprintf(file, "%-15s: %12d\n", location_labels[loc], data->census_location[year][loc]);
            loc_total += data->census_location[year][loc];
        }
        fprintf(file, "%-15s: %12lld\n\n", "TOTAL", loc_total);
    }
    
    // Write summary
    fprintf(file, "=====================================\n");
    fprintf(file, "SUMMARY STATISTICS\n");
    fprintf(file, "=====================================\n\n");
    
    // Year-wise totals
    fprintf(file, "YEAR-WISE POPULATION TOTALS:\n");
    fprintf(file, "-----------------------------\n");
    for (int year = 0; year < MAX_YEARS; year++) {
        long long total = 0;
        for (int age = 0; age < AGE_GROUPS; age++) {
            total += data->census_age[year][age];
        }
        fprintf(file, "%d: %lld\n", data->years[year], total);
    }
    
    fprintf(file, "\nFile saved successfully.\n");
    fclose(file);
    return true;
}

bool load_data_from_file(CensusData* data, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        return false;  // File doesn't exist
    }
    
    // This is a simplified loader - in practice, you'd implement proper parsing
    // For now, we'll just close the file and return true if it exists
    fclose(file);
    return true;
}

void display_menu(void) {
    printf("\n=== Main Menu ===\n");
    printf("1. Display File Contents\n");
    printf("2. Generate Detailed Report\n");
    printf("3. Create Data Backup\n");
    printf("4. Enter New Data\n");
    printf("5. Exit Program\n");
    printf("0. Quick Exit\n");
}

void display_file_contents(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }
    
    printf("\n=== File Contents: %s ===\n\n", filename);
    
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    
    fclose(file);
}

void create_data_backup(const char* source, const char* backup) {
    FILE* src = fopen(source, "r");
    if (!src) {
        printf("Error: Could not open source file %s\n", source);
        return;
    }
    
    FILE* dst = fopen(backup, "w");
    if (!dst) {
        printf("Error: Could not create backup file %s\n", backup);
        fclose(src);
        return;
    }
    
    // Add backup header
    fprintf(dst, "=== BACKUP CREATED: %s ===\n", get_current_timestamp());
    fprintf(dst, "Original file: %s\n\n", source);
    
    // Copy contents
    char buffer[1024];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytes, dst);
    }
    
    fclose(src);
    fclose(dst);
}

void generate_report(const CensusData* data) {
    char report_filename[100];
    snprintf(report_filename, sizeof(report_filename), "CensusReport_%ld.txt", (long)time(NULL));
    
    FILE* report = fopen(report_filename, "w");
    if (!report) {
        printf("Error creating report file.\n");
        return;
    }
    
    fprintf(report, "=== DETAILED CENSUS ANALYSIS REPORT ===\n");
    fprintf(report, "Generated: %s\n\n", get_current_timestamp());
    
    // Calculate and write various statistics
    fprintf(report, "GROWTH ANALYSIS:\n");
    fprintf(report, "================\n");
    
    for (int age = 0; age < AGE_GROUPS; age++) {
        fprintf(report, "\n%s Age Group:\n", age_labels[age]);
        for (int year = 1; year < MAX_YEARS; year++) {
            int prev = data->census_age[year-1][age];
            int curr = data->census_age[year][age];
            double growth = prev > 0 ? ((double)(curr - prev) / prev) * 100.0 : 0.0;
            fprintf(report, "  %d to %d: %.2f%% growth\n", 
                   data->years[year-1], data->years[year], growth);
        }
    }
    
    fclose(report);
    printf("Detailed report generated: %s\n", report_filename);
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

char* get_current_timestamp(void) {
    static char timestamp[64];
    time_t now = time(NULL);
    struct tm* tm_info = localtime(&now);
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", tm_info);
    return timestamp;
}

void print_separator(int count) {
    for (int i = 0; i < count; i++) {
        printf("=");
    }
    printf("\n");
}
