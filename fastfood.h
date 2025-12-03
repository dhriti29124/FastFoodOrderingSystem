#ifndef FASTFOOD_H
#define FASTFOOD_H

#define MENU_FILE "menu.txt"
#define ORDER_FILE "orders.txt"

typedef struct {
    int itemID;
    char name[50];
    char category[20];
    float price;
    int isAvailable;
} MenuItem;

typedef struct {
    int orderID;
    int itemID;
    int quantity;
    float totalCost;
} Order;

void addMenuItem();
void listMenuItems();
void searchMenuItemByID();


void placeOrder();
void updateInventory();
void generateSalesReport();

#endif

