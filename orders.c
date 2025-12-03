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

//Generate Sales Report Function
void generateSalesReport() {
    FILE *orderFile = fopen(ORDER_FILE, "r");
    //open the order file in read mode
    if (!orderFile) {
        printf("No orders found.\n");
        return;
    }
    //variable to store order
    Order order;

    //accumulators for summary
    float totalRevenue = 0;
    int orderCount = 0;

    //print report header
    printf("\n======= SALES REPORT =======\n");
    printf("OrderID   ItemID   Qty   TotalCost\n");
    printf("-----------------------------------\n");

    //read and process order from the file
    while (fscanf(orderFile, "%d %d %d %f",
                  &order.orderID,
                  &order.itemID,
                  &order.quantity,
                  &order.totalCost) != EOF)
    {
        //display order details
        printf("%6d   %6d   %3d   $%.2f\n",
               order.orderID, order.itemID,
               order.quantity, order.totalCost);

        //add to running totals
        totalRevenue += order.totalCost;
        orderCount++;
    }

    //print summary footer
    printf("-----------------------------------\n");
    printf("Total Orders: %d\n", orderCount);
    printf("Total Revenue: $%.2f\n", totalRevenue);

    //close the file 
    fclose(orderFile);
}
