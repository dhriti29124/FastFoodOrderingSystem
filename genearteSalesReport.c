#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fastfood.h"


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
