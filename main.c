#include <stdio.h>
#include "fastfood.h"

int main() {
    int choice;

    while (1) {
        printf("\n\n===== FAST FOOD ORDERING SYSTEM =====\n");
        printf("1. Add New Menu Item\n");
        printf("2. List All Menu Items\n");
        printf("3. Search Menu Item by ID\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                addMenuItem();
                break;

            case 2:
                listMenuItems();
                break;

            case 3:
                searchMenuItemByID();
                break;

            case 0:
                printf("Exiting program... Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

