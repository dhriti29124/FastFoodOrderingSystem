#ifndef FASTFOOD_H
#define FASTFOOD_H

typedef struct {
    int itemID;
    char name[50];
    char category[20];
    float price;
    int isAvailable; // 1 = available, 0 = not available
} MenuItem;

typedef struct {
    int orderID;
    int itemID;
    int quantity;
    float totalCost;
} Order;

void addMenuItem();
void listMenuItems();
void searchMenuItemByID(int searchID);


void placeOrder();
void updateInventory();
void generateSalesReport();

#endif
