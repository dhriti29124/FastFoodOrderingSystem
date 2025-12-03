#include <stdio.h>
#include "fastfood.h"

int main() {
    int choice;

    //main program loop - runs until user chooses to exit
    while (1) {
        //displays our main menu options
        printf("\n\n===== FAST FOOD ORDERING SYSTEM =====\n");
        printf("1. Add New Menu Item\n");
        printf("2. List All Menu Items\n");
        printf("3. Search Menu Item by ID\n");
        printf("4. Place Order\n");
        printf("5. Update Inventory\n");
        printf("6. Generate Sales Report\n");
        printf("0. Exit\n");

        //get user chioce
        printf("Enter your choice: ");
        scanf("%d", &choice);

        //switch statements
        switch (choice) {

            case 1:
                //adds a new item to mneu
                addMenuItem();
                break;

            case 2:
                //display all menu items only available onces
                listMenuItems();
                break;

            case 3:
                //searches for specific menu item by id no.
                searchMenuItemByID();
                break;

            case 4:
                //process customer order
                placeOrder();
                break;

            case 5:
                //modify inventory quantities by items 
                updateInventory();
                break;

            case 6:
                //displays sales report
                generateSalesReport();
                break;

            case 0:
                //exit 
                printf("Exiting program... Goodbye!\n");
                return 0;

            default:
                //error handling or invalid menu selection
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

