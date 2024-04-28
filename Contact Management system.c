#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

void gotoxy(int x, int y) {
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

struct contact {
    char name[20];
    char number[15];
    char email[40];
    char address[50];
};

void menu();
void add();
void view();
void modify();
void deletecon();
void search();

struct contact contacts[100]; // Array to store contacts
int contactCount = 0; // Keeps track of the number of contacts

int main(void) {
    gotoxy(10, 8);
    printf("<******CONTACT MANAGEMENT SYSTEM******>");

    gotoxy(10, 15);
    printf("Enter any key to continue: ");
    getch();
    menu();

    return 0;
}

void menu() {
    system("cls");
    gotoxy(10, 4);
    printf("<------MENU------>\n\n");
    int choice;
    printf("1. Add contact\n");
    printf("2. View contacts\n");
    printf("3. Modify contact\n");
    printf("4. Delete contact\n");
    printf("5. Search contact\n");
    printf("6. EXIT\n");
    printf("Enter a number according to your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            add();
            break;
        case 2:
            view();
            break;
        case 3:
            modify();
            break;
        case 4:
            deletecon();
            break;
        case 5:
            search();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice\n");
    }
}

void add() {
    system("cls");
    printf("Enter Contact Details:\n");
    printf("Name: ");
    scanf("%s", contacts[contactCount].name);
    printf("Number: ");
    scanf("%s", contacts[contactCount].number);
    printf("Email: ");
    scanf("%s", contacts[contactCount].email);
    printf("Address: ");
    scanf("%s", contacts[contactCount].address);
    contactCount++;
    printf("Contact added successfully!\n");
    getch();
    menu();
}

void view() {
system("cls");
printf("CONTACTS:\n");
printf("Name            Number                  Email                                           Address\n");
 for (int i = 0; i < contactCount; i++) {
        printf("%s\t%s\t\t%s\t\t%s\n", contacts[i].name, contacts[i].number, contacts[i].email, contacts[i].address);
        }
getch();
menu();
}

void modify() {
    system("cls");
    char searchName[20];
    printf("Enter name to modify: ");
    scanf("%s", searchName);
    int found = 0;
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(searchName, contacts[i].name) == 0) {
            printf("Enter new details for %s:\n", searchName);
            printf("Name: ");
            scanf("%s", contacts[i].name);
            printf("Number: ");
            scanf("%s", contacts[i].number);
            printf("Email: ");
            scanf("%s", contacts[i].email);
            printf("Address: ");
            scanf("%s", contacts[i].address);
            printf("Contact modified successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found!\n");
    }
    getch();
    menu();
}

void deletecon() {
    system("cls");
    char searchName[20];
    printf("Enter name to delete: ");
    scanf("%s", searchName);
    int found = 0;
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(searchName, contacts[i].name) == 0) {
            for (int j = i; j < contactCount - 1; j++) {
                strcpy(contacts[j].name, contacts[j + 1].name);
                strcpy(contacts[j].number, contacts[j + 1].number);
                strcpy(contacts[j].email, contacts[j + 1].email);
                strcpy(contacts[j].address, contacts[j + 1].address);
            }
            contactCount--;
            printf("Contact deleted successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found!\n");
    }
    getch();
    menu();
}

void search() {
    system("cls");
    char searchName[20];
    printf("Enter name to search: ");
    scanf("%s", searchName);
    int found = 0;
    printf("Name\tNumber\t\tEmail\t\tAddress\n");
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(searchName, contacts[i].name) == 0) {
            printf("%s\t%s\t\t%s\t\t%s\n", contacts[i].name, contacts[i].number, contacts[i].email, contacts[i].address);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found!\n");
    }
    getch();
    menu();
}
