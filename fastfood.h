#ifndef FASTFOOD_H
#define FASTFOOD_H

//stores menu item info
#define MENU_FILE "menu.txt" 
//stores order 
#define ORDER_FILE "orders.txt"

//menu item structure 
typedef struct {
    int itemID; //menu id
    char name[50]; //name of item 
    char category[20]; //eg. burger, drinks , dessert
    float price; //price of item in  $
    int isAvailable; //check availability
} MenuItem;

//order stucture
typedef struct {
    int orderID; //order id 
    int itemID; //menu id of the order 
    int quantity; //no of item ordered 
    float totalCost; //price * quantity = total
} Order;

//menu functions
void addMenuItem();
void listMenuItems();
void searchMenuItemByID();

//order and inventory functions
void placeOrder();
void updateInventory();
void generateSalesReport();

#endif

