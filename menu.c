#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fastfood.h"

//func to add new menu item
void addMenuItem() {
    MenuItem item;

    //open menu file
    FILE *fp = fopen(MENU_FILE, "a");
    if (fp == NULL) {
        printf("Error opening the menu file!\n");
        return;
    }

    //user input - ask user what they want to put in their belly
    printf("Enter Item ID: ");
    scanf("%d", &item.itemID);

    printf("Enter Item Name: ");
    scanf(" %[^\n]", item.name);   

    printf("Enter Category: ");
    scanf(" %[^\n]", item.category); 

    printf("Enter Price: ");
    scanf("%f", &item.price);

    printf("Is Available? (1 = Yes, 0 = No): ");
    scanf("%d", &item.isAvailable);

    //write on new item to the file 
    fprintf(fp, "%d %s %s %.2f %d\n",
            item.itemID, item.name, item.category, item.price, item.isAvailable);

    //close file
    fclose(fp);
    printf("Menu item added successfully!\n");
}

//func to lsit all menu item and display them 
void listMenuItems() {
    MenuItem item;
    FILE *fp = fopen(MENU_FILE, "r");

    //open file to read
    if (fp == NULL) {
        printf("Menu file not found! Please add items first.\n");
        return;
    }

    printf("\n----- MENU ITEMS -----\n");

    //read and display menu items
    while (fscanf(fp, "%d %49s %19s %f %d",
                  &item.itemID, item.name, item.category,
                  &item.price, &item.isAvailable) == 5) {
        //display item details 
        printf("ID: %d | Name: %s | Category: %s | Price: %.2f | Available: %s\n",
               item.itemID,
               item.name,
               item.category,
               item.price,
               item.isAvailable ? "Yes" : "No");
    }
    //close file
    fclose(fp);
}

//func to search for specific menu item 
void searchMenuItemByID() {
    int id;
    int found = 0; //if item found then flag 
    MenuItem item;

    //get item id for search
    printf("Enter Item ID to search: ");
    scanf("%d", &id);

    //open menu file
    FILE *fp = fopen(MENU_FILE, "r");
    if (fp == NULL) {
        printf("Menu file not found!\n");
        return;
    }

    //search through all menu 
    while (fscanf(fp, "%d %49s %19s %f %d",
                  &item.itemID, item.name, item.category,
                  &item.price, &item.isAvailable) == 5) {

        //check current item matches the serach
        if (item.itemID == id) {
            //display detailed info about found item
            printf("\n----- ITEM FOUND -----\n");
            printf("ID: %d\n", item.itemID);
            printf("Name: %s\n", item.name);
            printf("Category: %s\n", item.category);
            printf("Price: %.2f\n", item.price);
            printf("Available: %s\n", item.isAvailable ? "Yes" : "No");
            found = 1;
            break; //exit loop
        }
    }

    
    if (!found) {
        printf("OOOOOppppppaaaa!!!! Item with ID %d NOT FOUND.\n", id);
    }

    //close file
    fclose(fp);
}
