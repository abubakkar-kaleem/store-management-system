#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

// Struct to hold product information
struct shop {
    char productname[100];
    char quantity[100];
    int price;
} shop;

// Function prototypes
void TITLE();
int cls();
void ADMINPANEL();
int Access();
void Adminaccount();
void Add();
void View();
void EDIT();
void Search();
void Delete();
int buythings();
int billtitle(int bal);

// File pointer for managing the product database
FILE *fp;

// Main function
int main() {
    int choice, acc;
    TITLE(); // Display the title screen
    cls();   // Clear screen and show the store title

    // Main menu
    puts("\n\t\tWhat would you like to do?\n");
    puts("\t1. Purchase as a Customer");
    puts("\t2. Login as Authorized Administrator");
    puts("\t3. Exit");
    printf("Enter your choice: ");
    fflush(stdin);
    scanf("%d", &choice);

    // Handle user choice
    switch (choice) {
        case 1:
            buythings();
            break;
        case 2:
            cls();
            system("color 4E"); // Set console text color
            acc = Access();
            if (acc == 1)
                Adminaccount();
            else {
                getch();
                main();
            }
            break;
        case 3:
            cls();
            printf("\n\n\t\tGOODBYE!");
            return 0;
        default:
            cls();
            system("color B1");
            puts("\n\n\n\t\tINVALID CHOICE. TRY AGAIN.");
            getch();
            main();
    }
    return 0;
}

// Display the title screen
void TITLE() {
    printf("\n\n\n\n\n\t\tIMTIAZ SUPER STORE MANAGEMENT SYSTEM\n");
    puts("\nPress any key to continue");
    getch();
}

// Clear the screen and display the store title
int cls() {
    system("cls");
    printf("\n\t\t\tIMTIAZ SUPER STORE\n");
    return 0;
}

// Administrator panel menu
void ADMINPANEL() {
    printf("\t\n\t\tADMINISTRATOR PANEL\n\n");
}

// Display the bill title with the current balance
int billtitle(int bal) {
    system("cls");
    printf("\n\t\tIMTIAZ SUPER STORE\n");
    printf("\n\t\t\t\t\t\tCurrent Expense = %d", bal);
    return 0;
}

// Admin login screen and options
void Adminaccount() {
    system("color 2E");
    int select;

    fp = fopen("database.txt", "a+");
    cls();
    ADMINPANEL();

    // Admin options
    printf("\t1. Add New Product\n");
    printf("\t2. View Available Products\n");
    printf("\t3. Edit Existing Product\n");
    printf("\t4. Search for a Product\n");
    printf("\t5. Delete Product\n");
    printf("\t6. Return to Previous Screen\n");
    printf("\nEnter your choice: ");
    scanf("%d", &select);

    // Handle admin options
    switch (select) {
        case 1: Add(); break;
        case 2: View(); break;
        case 3: EDIT(); break;
        case 4: Search(); break;
        case 5: Delete(); break;
        case 6: main(); break;
        default:
            printf("\nInvalid choice. Try again.");
            Adminaccount();
    }
}

// Add a new product to the database
void Add() {
    cls();
    char id[100];
    ADMINPANEL();
    printf("\n\t****Adding a New Product****\n");
    fflush(stdin);

    printf("\nProduct Name: ");
    gets(id);

    // Check if product already exists
    while (fread(&shop, sizeof(shop), 1, fp) == 1) {
        if (strcmp(shop.productname, id) == 0) {
            printf("\nThis product already exists.\n");
            printf("\nPress any key to add another product...");
            getch();
            Add();
            return;
        }
    }

    // Add new product details
    strcpy(shop.productname, id);
    printf("Quantity: ");
    gets(shop.quantity);
    printf("Price: ");
    scanf("%d", &shop.price);

    // Save to file
    fwrite(&shop, sizeof(shop), 1, fp);
    printf("\nProduct added successfully.\n");
    printf("Press any key to return to the previous menu...");
    getch();
    fclose(fp);
    Adminaccount();
}

// View all products
void View() {
    cls();
    ADMINPANEL();
    printf("\n\t**Viewing Available Products**\n\n");
    rewind(fp);

    // Display all products
    while (fread(&shop, sizeof(shop), 1, fp) == 1) {
        printf("Product Name: %s\n", shop.productname);
        printf("Quantity: %s\n", shop.quantity);
        printf("Price: %d\n\n", shop.price);
    }
    printf("\nPress any key to return to the previous menu...");
    getch();
    fclose(fp);
    Adminaccount();
}

// Edit an existing product
void EDIT() {
    cls();
    ADMINPANEL();
    FILE *tptr;
    char id[30];
    int temp = 0;

    printf("\nEnter the product name to edit: ");
    fflush(stdin);
    gets(id);

    tptr = fopen("temporary.txt", "w");
    rewind(fp);

    // Edit product details
    while (fread(&shop, sizeof(shop), 1, fp) == 1) {
        if (strcmp(shop.productname, id) == 0) {
            temp = 1;
            printf("\nEditing Product: %s\n", id);
            printf("New Product Name: ");
            gets(shop.productname);
            printf("New Quantity: ");
            gets(shop.quantity);
            printf("New Price: ");
            scanf("%d", &shop.price);
        }
        fwrite(&shop, sizeof(shop), 1, tptr);
    }

    if (temp == 0) {
        printf("\nProduct not found.\n");
    }

    fclose(fp);
    fclose(tptr);
    remove("database.txt");
    rename("temporary.txt", "database.txt");
    fp = fopen("database.txt", "a+");
    Adminaccount();
}

// Search for a product
void Search() {
    cls();
    ADMINPANEL();
    char id[30];
    int found = 0;

    printf("\nEnter the product name to search: ");
    fflush(stdin);
    gets(id);

    // Search for the product in the database
    while (fread(&shop, sizeof(shop), 1, fp) == 1) {
        if (strcmp(shop.productname, id) == 0) {
            printf("\nProduct Found:\n");
            printf("Name: %s\n", shop.productname);
            printf("Quantity: %s\n", shop.quantity);
            printf("Price: %d\n", shop.price);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nProduct not found.\n");
    }

    printf("\nPress any key to continue...");
    getch();
    Adminaccount();
}

// Delete a product
void Delete() {
    cls();
    ADMINPANEL();
    FILE *tptr;
    char id[30];
    int temp = 0;

    printf("\nEnter the product name to delete: ");
    fflush(stdin);
    gets(id);

    tptr = fopen("temp.txt", "w");
    rewind(fp);

    // Remove product from the database
    while (fread(&shop, sizeof(shop), 1, fp) == 1) {
        if (strcmp(shop.productname, id) != 0) {
            fwrite(&shop, sizeof(shop), 1, tptr);
        } else {
            printf("\nProduct deleted successfully.\n");
            temp = 1;
        }
    }

    if (temp == 0) {
        printf("\nProduct not found.\n");
    }

    fclose(fp);
    fclose(tptr);
    remove("database.txt");
    rename("temp.txt", "database.txt");
    fp = fopen("database.txt", "a+");
    Adminaccount();
}

// Customer purchase flow
int buythings() {
    cls();
    char product[100];

    printf("\n\t\t\tCUSTOMER PURCHASE\n");
    fp = fopen("database.txt", "r");

    // Display available products
    printf("\nAvailable Products:\n\n");
    while (fread(&shop, sizeof(shop), 1, fp) == 1) {
        printf("\nProduct Name: %s\n", shop.productname);
        printf("Quantity: %s\n", shop.quantity);
        printf("Price: %d\n", shop.price);
    }

    printf("\n\nEnter the product name to purchase (or type 'RETURN' to cancel): ");
    fflush(stdin);
    gets(product);

    if (strcmp(product, "RETURN") == 0) {
        fclose(fp);
        main();
    }

    // Process purchase
    rewind(fp);
    while (fread(&shop, sizeof(shop), 1, fp) == 1) {
        if (strcmp(shop.productname, product) == 0) {
            billtitle(shop.price);
            printf("\nProduct Name: %s\n", shop.productname);
            printf("Quantity: %s\n", shop.quantity);
            printf("Price: %d\n", shop.price);
            printf("\nTotal Bill: %d\n", shop.price);
            printf("\nPress any key to return...");
            getch();
            fclose(fp);
            main();
        }
    }

    printf("\nProduct not found.\nPress any key to return...");
    getch();
    fclose(fp);
    main();
}

// Admin authentication
int Access() {
    char pass[30];
    printf("\nEnter Admin Password: ");
    fflush(stdin);
    gets(pass);

    if (strcmp(pass, "admin") == 0) {
        printf("\nAccess Granted.\nPress any key to continue...");
        getch();
        return 1;
    } else {
        printf("\nAccess Denied.\nPress any key to return...");
        getch();
        return 0;
    }
}
