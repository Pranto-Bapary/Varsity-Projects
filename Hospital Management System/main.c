/*
    Project Name : Hospital Management System
    Author Name  : Pranto Bapary
    Date         : 28th August 2022
*/

// Header Files
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>

// Global Variables
int valid = 0;
int len = 0;

// Structure
typedef struct patient
{
    char age[3];
    char gender;
    char first_name[20];
    char last_name[20];
    char address[30];
    char phone[15];
    char problem[50];
    char doctor[20];
} patient;

patient patient_info;

// Functions
void title();
void inner_title();
void login();
void main_menu();
void add_record();
void view_record();
void search_record();
void update_record();
void delete_record();
void gotoxy(short x, short y)
{
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
// Main Function
int main()
{
    title();
    login();
    return 0;
}

// title function is used to display the name of the hospital
void title()
{
    printf("\n\t\t\t--------------------------------------\n");
    printf("\t\t\t       Welcome to PBC Hospital       \n");
    printf("\t\t\t--------------------------------------\n");
}

// inner_title function will display the name of the hospital in large size
void inner_title()
{
    printf("\n\t\t\t----------------------------------------------------------------\n");
    printf("\t\t\t                   Welcome to PBC Hospital       \n");
    printf("\t\t\t----------------------------------------------------------------\n");
}

// login function is Used to login into the main_menu function
void login()
{
    int pass_count = 0;
    int try_limit = 3;
    char username[20];
    char password[20];
    char original_username[20] = "Pranto";
    char original_password[20] = "221002113";

    do
    {
        printf("\n\t\t\tEnter Your Username and Password\n\n\n");
        printf("\t\t\tEnter Your Username : ");
        gets(username);

        printf("\n\t\t\tEnter Your Password : ");
        gets(password);

        if (strcmp(username, original_username) == 0 && strcmp(password, original_password) == 0)
        {
            printf("\n\t\t\tLogin Successful");
            getch();
            system("cls");
            main_menu();
            break;
        }
        else
        {
            try_limit--;
            system("cls");
            inner_title();
            printf("\n\t\t\tIncorrect Username and Password. You Can Try %d more times \n\n", try_limit);
        }
        pass_count++;

    } while (pass_count <= 2);

    if (pass_count > 2)
    {
        printf("\n\t\t\tSorry You've crossed the limit. You cannot login.");
        getch();
    }
    else
    {
        main_menu();
    }
}

// main_menu function is used to display the services provided by the hospital
void main_menu()
{
    system("cls");
    title();
    int choice;

    printf("\n\t\t\t1. Add Patients Record\n\n");
    printf("\t\t\t2. View Patients Record\n\n");
    printf("\t\t\t3. Search Patients Record\n\n");
    printf("\t\t\t4. Update Patients Record\n\n");
    printf("\t\t\t5. Remove Patients Record\n\n");
    printf("\t\t\t6. Exit\n\n\n");

    printf("\t\t\tEnter Your Choice : ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        add_record();
        break;

    case 2:
        view_record();
        break;

    case 3:
        search_record();
        break;

    case 4:
        update_record();
        break;

    case 5:
        delete_record();
        break;

    case 6:
        printf("\n\t\t\tThank You. Visit Us Next Time.");
        exit(1);
        break;

    default:
        printf("\n\n\t\t\tInvalid Input. Please Try Again");
        break;
    }
}

// add_record is to add new patients record
void add_record()
{
    system("cls");
    inner_title();

    printf("\n\t\t\t!!!!!!!!!!!!!!!!!!!!!!Add Patient Records!!!!!!!!!!!!!!!!!!!!!!!\n");
    char add_more_record;
    FILE *fptr;

    do
    {
        fptr = fopen("record.txt", "a");
    A:
        fflush(stdin);
        printf("\n\t\t\tEnter Your First Name   : ");
        gets(patient_info.first_name);
        patient_info.first_name[0] = toupper(patient_info.first_name[0]);

        if (strlen(patient_info.first_name) > 20 || strlen(patient_info.first_name) < 4)
        {
            printf("\n\t\t\tName is too short or too long\n");
            goto A;
        }
        else
        {
            for (len = 0; len < strlen(patient_info.first_name); len++)
            {
                if (isalpha(patient_info.first_name[len]))
                    valid = 1;
                else
                {
                    valid = 0;
                    break;
                }
            }
            if (!valid)
            {
                printf("\n\t\t\tInvalid Name. Enter Correct Name\n");
                goto A;
            }
        }

    B:
        printf("\n\t\t\tEnter Your Last Name    : ");
        gets(patient_info.last_name);
        patient_info.last_name[0] = toupper(patient_info.last_name[0]);

        if (strlen(patient_info.last_name) > 20 || strlen(patient_info.last_name) < 4)
        {
            printf("\n\t\t\tName is too short or too long\n");
            goto B;
        }
        else
        {
            for (len = 0; len < strlen(patient_info.last_name); len++)
            {
                if (isalpha(patient_info.last_name[len]))
                    valid = 1;
                else
                {
                    valid = 0;
                    break;
                }
            }
            if (!valid)
            {
                printf("\n\t\t\tInvalid Name. Enter Correct Name\n");
                goto B;
            }
        }

        printf("\n\t\t\tEnter Your Gender (F/M) : ");
        scanf("%c", &patient_info.gender);
        fflush(stdin);

        printf("\n\t\t\tEnter Your Age          : ");
        gets(patient_info.age);

        printf("\n\t\t\tEnter Your Phone Number : ");
        gets(patient_info.phone);

    C:
        printf("\n\t\t\tEnter Your Full Address : ");
        gets(patient_info.address);
        patient_info.address[0] = toupper(patient_info.address[0]);

        if (strlen(patient_info.address) > 30 || strlen(patient_info.address) < 5)
        {
            printf("\n\t\t\tAddress is too short or too long\n");
            goto C;
        }

        printf("\n\t\t\tEnter Your Problem      : ");
        gets(patient_info.problem);

    D:
        printf("\n\t\t\tEnter the Doctor You Want to Visit : ");
        gets(patient_info.doctor);
        patient_info.doctor[0] = toupper(patient_info.doctor[0]);

        if (strlen(patient_info.doctor) > 20 || strlen(patient_info.doctor) < 4)
        {
            printf("\n\t\t\tDoctor's Name is too short or too long\n");
            goto D;
        }
        if (fptr == NULL)
        {
            printf("File Not Found");
            exit(1);
        }
        fprintf(fptr, "%s %s %c %s %s %s %s %s \n", patient_info.first_name, patient_info.last_name, patient_info.gender, patient_info.age, patient_info.phone, patient_info.address, patient_info.problem, patient_info.doctor);
        printf("\n\n\t\t\t         Record Added Successfully\n");
        fclose(fptr);

        printf("\n\t\t\t Do You Want to Add More Records (Y/N) : ");
        scanf("%c", &add_more_record);
        fflush(stdin);
    } while (add_more_record != 'N');

    printf("\n\t\t\t   Thank You.Press Any Key to Continue ");
    getch();
    main_menu();
}
// view_record function is used to view the total patients record
void view_record()
{
    system("cls");
    inner_title();

    int row;
    FILE *fptr;
    fptr = fopen("record.txt", "r");

    printf("\n\t\t\t!!!!!!!!!!!!!!!!!!!!View Patient Records!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    gotoxy(1, 8);
    printf("Full Name");

    gotoxy(15, 8);
    printf("Gender");

    gotoxy(25, 8);
    printf("Age");

    gotoxy(35, 8);
    printf("Phone");

    gotoxy(47, 8);
    printf("Full Address");

    gotoxy(64, 8);
    printf("Problem");

    gotoxy(78, 8);
    printf("Prescribed Doctor");

    printf("\n-------------------------------------------------------------------------------------------------\n");

    row = 10;
    while (fscanf(fptr, "%s %s %c %s %s %s %s %s\n", patient_info.first_name, patient_info.last_name, &patient_info.gender, patient_info.age, patient_info.phone, patient_info.address, patient_info.problem, patient_info.doctor) != EOF)
    {
        gotoxy(1, row);
        printf("%s %s", patient_info.first_name, patient_info.last_name);

        gotoxy(18, row);
        printf("%c", patient_info.gender);

        gotoxy(26, row);
        printf("%s", patient_info.age);

        gotoxy(34, row);
        printf("%s", patient_info.phone);

        gotoxy(50, row);
        printf("%s", patient_info.address);

        gotoxy(65, row);
        printf("%s", patient_info.problem);

        gotoxy(78, row);
        printf("%s", patient_info.doctor);
        row++;
    }
    fclose(fptr);
    printf("\n\n\t\t\tPress Any Key to Go Back to the Main Menu");
    getch();
    main_menu();
}

// search_record to search the records by name
void search_record()
{
    char first_name[20], last_name[20];
    char search_again;

    system("cls");
    inner_title();

    FILE *fptr;
    fptr = fopen("record.txt", "r");
    printf("\n\t\t\t!!!!!!!!!!!!!!!!!!Search Patient Records!!!!!!!!!!!!!!!!!!!!!!!!\n");

    fflush(stdin);
    printf("\n\n\n\t\t\tEnter the First Name of the Patient : ");
    gets(first_name);

    fflush(stdin);
    printf("\n\n\t\t\tEnter the Last Name of the Patient : ");
    gets(last_name);

    first_name[0] = toupper(first_name[0]);
    last_name[0] = toupper(last_name[0]);

    while (fscanf(fptr, "%s %s %c %s %s %s %s %s\n", patient_info.first_name, patient_info.last_name, &patient_info.gender, patient_info.age, patient_info.phone, patient_info.address, patient_info.problem, patient_info.doctor) != EOF)
    {
        if (strcmp(first_name, patient_info.first_name) == 0 && strcmp(last_name, patient_info.last_name) == 0)
        {
            gotoxy(1, 14);
            printf("Full Name");

            gotoxy(15, 14);
            printf("Gender");

            gotoxy(25, 14);
            printf("Age");

            gotoxy(35, 14);
            printf("Phone");

            gotoxy(47, 14);
            printf("Full Address");

            gotoxy(64, 14);
            printf("Problem");

            gotoxy(78, 14);
            printf("Prescribed Doctor");
            printf("\n-------------------------------------------------------------------------------------------------\n");

            gotoxy(1, 17);
            printf("%s %s", patient_info.first_name, patient_info.last_name);

            gotoxy(18, 17);
            printf("%c", patient_info.gender);

            gotoxy(26, 17);
            printf("%s", patient_info.age);

            gotoxy(34, 17);
            printf("%s", patient_info.phone);

            gotoxy(50, 17);
            printf("%s", patient_info.address);

            gotoxy(65, 17);
            printf("%s", patient_info.problem);

            gotoxy(78, 17);
            printf("%s", patient_info.doctor);
            break;
        }
    }

    if (strcmp(first_name, patient_info.first_name) != 0 || strcmp(last_name, patient_info.last_name) != 0)
        printf("\n\n\t\t\t\t   Record Not Found\n");

    fclose(fptr);

check_more:

    fflush(stdin);
    printf("\n\n\t\t\tDo You Want to Search More [Y/N] ? ");
    scanf("%c", &search_again);

    if (toupper(search_again) == 'Y')
        search_record();

    else if (toupper(search_again) == 'N')
    {
        printf("\n\n\t\t\t             !!!Thank You!!!");
        printf("\n\n\t\t\tPress Any Key to Go Back to the Main Menu");
        getch();
        main_menu();
    }
    else
    {
        printf("\n\n\t\t\t    Invalid Choice.Please Try Agaain");
        goto check_more;
    }
}

// update_record function to update the existing data
void update_record()
{
    system("cls");
    inner_title();
    printf("\n\t\t\t!!!!!!!!!!!!!!!!!!!Update Patients Record!!!!!!!!!!!!!!!!!!!!!!!!\n");

    FILE *fptr, *new_ptr;
    char first_name[20], last_name[20];

    char ch;
    int valid = 0;

    new_ptr = fopen("new_record.txt", "w+");
    fptr = fopen("record.txt", "r");

    if (fptr == NULL)
    {
        printf("\n\n\t\t\tFile cannot be opened.");
        getch();
        main_menu();
    }

    fflush(stdin);
    printf("\n\t\t\tEnter the First Name of the Patient : ");
    gets(first_name);

    fflush(stdin);
    printf("\n\t\t\tEnter the Last Name of the Patient  : ");
    gets(last_name);

    first_name[0] = toupper(first_name[0]);
    last_name[0] = toupper(last_name[0]);

    if (new_ptr == NULL)
    {
        printf("\n\n\t\t\tFile cannot be opened.");
        getch();
        main_menu();
    }

    printf("\n\t\t\t!!!!!!!!!!!!!Existing Record!!!!!!!!!!!!!\n\n\n");
    while (fscanf(fptr, "%s %s %c %s %s %s %s %s\n", patient_info.first_name, patient_info.last_name, &patient_info.gender, patient_info.age, patient_info.phone, patient_info.address, patient_info.problem, patient_info.doctor) != EOF)
    {
        if (strcmp(first_name, patient_info.first_name) == 0 && strcmp(last_name, patient_info.last_name) == 0)
        {
            valid = 1;
            gotoxy(1, 13);

            printf("Full Name");
            gotoxy(15, 13);

            printf("Gender");
            gotoxy(25, 13);

            printf("Age");
            gotoxy(35, 13);

            printf("Phone");
            gotoxy(47, 13);

            printf("Full Address");
            gotoxy(64, 13);

            printf("Problem");
            gotoxy(78, 13);

            printf("Prescribed Doctor");
            printf("\n-------------------------------------------------------------------------------------------------\n");

            gotoxy(1, 15);
            printf("%s %s", patient_info.first_name, patient_info.last_name);

            gotoxy(18, 15);
            printf("%c", patient_info.gender);

            gotoxy(26, 15);
            printf("%s", patient_info.age);

            gotoxy(34, 15);
            printf("%s", patient_info.phone);

            gotoxy(50, 15);
            printf("%s", patient_info.address);

            gotoxy(65, 15);
            printf("%s", patient_info.problem);

            gotoxy(78, 15);
            printf("%s", patient_info.doctor);

            fflush(stdin);
            printf("\n\n\t\t\tEnter Your New First Name   : ");
            gets(patient_info.first_name);

            fflush(stdin);
            printf("\n\t\t\tEnter Your New Last Name    : ");
            gets(patient_info.last_name);

            printf("\n\t\t\tEnter Your Gender (F/M)     : ");
            scanf("%c", &patient_info.gender);
            fflush(stdin);

            printf("\n\t\t\tEnter Your Age              : ");
            gets(patient_info.age);

            printf("\n\t\t\tEnter Your Phone Number     : ");
            gets(patient_info.phone);

            printf("\n\t\t\tEnter Your Full Address     : ");
            gets(patient_info.address);
            patient_info.address[0] = toupper(patient_info.address[0]);

            printf("\n\t\t\tEnter Your Problem          : ");
            gets(patient_info.problem);

            printf("\n\t\t\tEnter the Doctor You Want to Visit : ");
            gets(patient_info.doctor);
            patient_info.doctor[0] = toupper(patient_info.doctor[0]);

            printf("\n\t\t\tPress 'U' to Confirm Update Process : ");
            ch = getche();

            if (toupper(ch) == 'U')
            {
                fprintf(new_ptr, "%s %s %c %s %s %s %s %s \n", patient_info.first_name, patient_info.last_name, patient_info.gender, patient_info.age, patient_info.phone, patient_info.address, patient_info.problem, patient_info.doctor);
                printf("\n\n\t\t\t         Record Updated Successfully\n");
            }
        }
        else
        {
            fprintf(new_ptr, "%s %s %c %s %s %s %s %s \n", patient_info.first_name, patient_info.last_name, patient_info.gender, patient_info.age, patient_info.phone, patient_info.address, patient_info.problem, patient_info.doctor);
        }
    }
    if (!valid)
    {
        printf("\t\t\t             No Record Found\n");
    }
    fclose(new_ptr);
    fclose(fptr);

    remove("record.txt");
    rename("new_record.txt", "record.txt");

    printf("\n\t\t\tPress Any Key to Go Back to the Main Menu");
    getch();
    main_menu();
}

void delete_record()
{
    system("cls");
    inner_title();
    printf("\n\t\t\t!!!!!!!!!!!!!!!!!!!Remove Patients Record!!!!!!!!!!!!!!!!!!!!!!!!\n");

    FILE *fptr, *new_ptr;
    int found = 0;

    char first_name[20], last_name[20];
    char ch;

    new_ptr = fopen("new_record.txt", "w+");
    fptr = fopen("record.txt", "r");

    fflush(stdin);
    printf("\n\t\t\tEnter the First Name of the Patient : ");
    gets(first_name);

    fflush(stdin);
    printf("\n\t\t\tEnter the Last Name of the Patient  : ");
    gets(last_name);

    first_name[0] = toupper(first_name[0]);
    last_name[0] = toupper(last_name[0]);

    printf("\n\t\t\t!!!!!!!!!!!!!Existing Record!!!!!!!!!!!!!\n\n\n");

    while (fscanf(fptr, "%s %s %c %s %s %s %s %s\n", patient_info.first_name, patient_info.last_name, &patient_info.gender, patient_info.age, patient_info.phone, patient_info.address, patient_info.problem, patient_info.doctor) != EOF)
    {
        if (strcmp(first_name, patient_info.first_name) != 0 || strcmp(last_name, patient_info.last_name) != 0)
        {
            fprintf(new_ptr, "%s %s %c %s %s %s %s %s \n", patient_info.first_name, patient_info.last_name, patient_info.gender, patient_info.age, patient_info.phone, patient_info.address, patient_info.problem, patient_info.doctor);
        }
        else
        {
            found = 1;

            gotoxy(1, 13);
            printf("Full Name");

            gotoxy(15, 13);
            printf("Gender");

            gotoxy(25, 13);
            printf("Age");

            gotoxy(35, 13);
            printf("Phone");

            gotoxy(47, 13);
            printf("Full Address");

            gotoxy(64, 13);
            printf("Problem");

            gotoxy(78, 13);
            printf("Prescribed Doctor");
            printf("\n-------------------------------------------------------------------------------------------------\n");

            gotoxy(1, 15);
            printf("%s %s", patient_info.first_name, patient_info.last_name);

            gotoxy(18, 15);
            printf("%c", patient_info.gender);

            gotoxy(26, 15);
            printf("%s", patient_info.age);

            gotoxy(34, 15);
            printf("%s", patient_info.phone);

            gotoxy(50, 15);
            printf("%s", patient_info.address);

            gotoxy(65, 15);
            printf("%s", patient_info.problem);

            gotoxy(78, 15);
            printf("%s", patient_info.doctor);
        }
    }

    if (found == 0)
    {
        printf("\t\t\t             No Record Found\n");
        getch();
        main_menu();
    }
    else
    {
        fclose(new_ptr);
        fclose(fptr);

        printf("\n\n\t\t\tPress 'R' to Confirm Remove Process : ");
        ch = getche();
        if (toupper(ch) == 'R')
        {
            remove("record.txt");
            rename("new_record.txt", "record.txt");
            printf("\n\n\t\t\t      Record Removed Successfully\n");
        }
        printf("\n\t\t\tPress Any Key to Go Back to the Main Menu");
        getch();
        main_menu();
    }
}
