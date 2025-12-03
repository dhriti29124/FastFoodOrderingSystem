#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fastfood.h"

//place order func
void placeOrder() {
  
    //menu file and order file
    FILE *menuFile = fopen(MENU_FILE, "r");
    FILE *orderFile = fopen(ORDER_FILE, "a");

    //check if both open successfully - error checking
    if (!menuFile || !orderFile) {
        printf("Error: Could not open required files.\n");
        return;
    }

    //variable declaration
    int searchID, qty;
    MenuItem item;
    int found = 0;

    //get item iD - user input
    printf("Enter Item ID to order: ");
    scanf("%d", &searchID);

    printf("Enter quantity: ");
    scanf("%d", &qty);

    // Read menu file line by line to find req item
    while (fscanf(menuFile, "%d %49s %19s %f %d",
                  &item.itemID, item.name, item.category,
                  &item.price, &item.isAvailable) != EOF)
    {
        //check if current item matches searched id 
        if (item.itemID == searchID) {
            found = 1; //mark 1 as found 
          
            //check if avalaible in stock
            if (item.isAvailable == 0) {
                printf("Item is out of stock.\n");
                fclose(menuFile);
                fclose(orderFile);
                return;
            }
          
            //cal total cost for order
            float cost = item.price * qty;

            // generate order ID
            static int orderCount = 1;
          
            //write to order file
            fprintf(orderFile, "%d %d %d %.2f\n",
                    orderCount, item.itemID, qty, cost);
          
            //display order confirmation
            printf("\nOrder placed successfully!\n");
            printf("Order ID: %d\n", orderCount);
            printf("Item: %s\n", item.name);
            printf("Quantity: %d\n", qty);
            printf("Total Cost: $%.2f\n", cost);
          
            //increment 
            orderCount++;
            break; //exit loop once item is found and processed
        }
    }
  
    //alert user if item id not found
    if (!found) {
        printf("Item with ID %d not found.\n", searchID);
    }
  
    //close files
    fclose(menuFile);
    fclose(orderFile);
}
