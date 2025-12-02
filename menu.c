#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fastfood.h"

void addMenuItem() {
  MenuItem item;
  FILE *fp = fopen ("menu.txt","a"); 

  if (fp== NULL){
    printf("Error opening the menu file!\n");
    return;
  }
  printf("Enter Item ID: ");
    scanf("%d", &item.itemID);

    printf("Enter Item Name: ");
    scanf("%s", item.name);

    printf("Enter Category: ");
    scanf("%s", item.category);

    printf("Enter Price: ");
    scanf("%f", &item.price);

    printf("Is Available? (1 = Yes, 0 = No): ");
    scanf("%d", &item.isAvailable);

  fprintf(fp, %d %s %s %.2f %d\n"
         item.itemID, item.name, item.category, item.price, item.isAvailable);
  fclose(fp);

  printf("Menu item added successfully!\n");
}
  
}
void listMenuItems() {}
void searchMenuItemByID(int searchID) {}
