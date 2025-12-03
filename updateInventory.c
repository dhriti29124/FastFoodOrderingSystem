#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fastfood.h"

//func to update availability status of menu items
void updateInventory() {
    //open menu file for reading
    FILE *menuFile = fopen(MENU_FILE, "r");
    FILE *tempFile = fopen("temp.txt", "w");

    //check if both open successfully - error checking
    if (!menuFile || !tempFile) {
        printf("Error: Could not open file.\n");
        return;
    }

    //variable declaration
    int searchID, newStatus;
    MenuItem item;
    int found = 0;

    //get item id ffrom user
    printf("Enter Item ID to update inventory: ");
    scanf("%d", &searchID);

    //get new availability status from user
    printf("Enter new availability (1 = available, 0 = out of stock): ");
    scanf("%d", &newStatus);

    //read entire menu file 
    while (fscanf(menuFile, "%d %49s %19s %f %d",
                  &item.itemID, item.name, item.category,
                  &item.price, &item.isAvailable) != EOF)
    {
        //check if current item matches the searched id
        if (item.itemID == searchID) {
            found = 1;//mark item as found
            item.isAvailable = newStatus; //update 
        }

        //write item to temporary file 
        fprintf(tempFile, "%d %s %s %.2f %d\n",
                item.itemID, item.name, item.category,
                item.price, item.isAvailable);
    }

    //close files 
    fclose(menuFile);
    fclose(tempFile);

    //replace original menu with update temp file
    remove(MENU_FILE); //delete orig menu file
    rename("temp.txt", MENU_FILE); //remove temp file

    //item found or no?
    if (found)
        printf("Inventory updated successfully.\n");
    else
        printf("Item ID not found.\n");
}
