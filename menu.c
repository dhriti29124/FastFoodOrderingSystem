#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fastfood.h"

void addMenuItem() {
  MenuItem item;
  FILE *fp = fopen ("menu.txt","a"); 

  if (fp== NULL){
    printf("Error opening the menu file!\n");
    return;
  }
  printf("Enter Item ID: ");
    scanf("%d", &item.itemID);

    printf("Enter Item Name: ");
    scanf("%s", item.name);

    printf("Enter Category: ");
    scanf("%s", item.category);

    printf("Enter Price: ");
    scanf("%f", &item.price);

    printf("Is Available? (1 = Yes, 0 = No): ");
    scanf("%d", &item.isAvailable);

  fprintf(fp, %d %s %s %.2f %d\n"
         item.itemID, item.name, item.category, item.price, item.isAvailable);
  fclose(fp);

  printf("Menu item added successfully!\n");
}
  
}
void listMenuItems() {
  
    MenuItem item;
    FILE *fp = fopen("menu.txt", "r");

    if (fp == NULL) {
        printf("Menu file not found! Please add items first.\n");
        return;
    }

    printf("\n----- MENU ITEMS -----\n");

    while (fscanf(fp, "%d %s %s %f %d",
                  &item.itemID, item.name, item.category, &item.price, &item.isAvailable) == 5) {

        printf("ID: %d | Name: %s | Category: %s | Price: %.2f | Available: %s\n",
               item.itemID,
               item.name,
               item.category,
               item.price,
               item.isAvailable ? "Yes" : "No");
    }

    fclose(fp);
}


void searchMenuItemByID() {
    int id;
    int found = 0;
    MenuItem item;

    printf("Enter Item ID to search: ");
    scanf("%d", &id);

    FILE *fp = fopen("menu.txt", "r");

    if (fp == NULL) {
        printf("Menu file not found!\n");
        return;
    }

    while (fscanf(fp, "%d %s %s %f %d",
                  &item.itemID, item.name, item.category, &item.price, &item.isAvailable) == 5) {

        if (item.itemID == id) {
            printf("\n----- ITEM FOUND -----\n");
            printf("ID: %d\n", item.itemID);
            printf("Name: %s\n", item.name);
            printf("Category: %s\n", item.category);
            printf("Price: %.2f\n", item.price);
            printf("Available: %s\n", item.isAvailable ? "Yes" : "No");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Item with ID %d NOT FOUND in the menu.\n", id);
    }

    fclose(fp);
}

