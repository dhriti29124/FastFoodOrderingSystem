                           FAST FOOD DELIVERING SYSTEM 

This project is a simple fast-food ordering system written in C.
It allows adding menu items, placing customer orders, updating inventory, and generating sales reports.
The project uses structures, file handling, and modular programming.

# Team Members

Dhriti – Menu Management

Ehsanul – Order & Inventory Management

# Project Structure
FastFoodOrderingSystem/
│── main.c          → Program menu + main loop
│── fastfood.h      → Structs + function prototypes
│── menu.c          → Menu features (Dhriti)
│── orders.c        → Orders, inventory, reports (Ehsanul)
│── README.md       → Project documentation

# Features
Dhriti (menu.c)

addMenuItem() – Add new items to the menu file (menu.txt)

listMenuItems() – Display all menu items

searchMenuItemByID() – Search for an item by ID

Ehsanul (orders.c)

placeOrder() – Create a new order

updateInventory() – Change availability / stock

generateSalesReport() – Show revenue + quantity sold

# How to Compile

Use this command:

gcc main.c menu.c orders.c -o fastfood


# File Handling Used

menu.txt → stores menu item details

orders.txt → stores all customer orders

# Technical Requirements

C Structures

File I/O (fopen, fscanf, fprintf)

Modular code (main.c, menu.c, orders.c)

Error validation and testing
