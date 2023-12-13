#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct item {
    int item_no;
    char item_name[30];
    char description[300];
    float price;
    int quant_instock;
    char expdate[10];
    char category[20];
} Item;

void additem();
void searchitem();
void updateitem();
void deleteitem();
void displayitem();
void surplusQuantityIdentification();
void lowQuantityIdentification();
void totalInventoryValueCalculation();
void itemQuantitySummationByCategory();
void itemExpiryTracking();
void salesData();

int main() {
    int input;

    do {
        printf("\n\t** USER PANEL **\n\n");
        printf("(1) Search item\n(2) Add item\n(3) Update item info\n(4) Delete item\n(5) Display inventory\n\n");
        printf("* Run Search for :\n");
        printf("(6) Surplus Quantity Identification\n(7) Low-Quantity Identification\n(8) Total Inventory Value Calculation\n(9) Item Quantity Summation by Category\n(10) Item Expiry Tracking\n(11) Sales Data\n");
        printf("\n(12) Help\n");
        printf("(0) Exit\n\n");

        scanf("%d", &input);

        switch (input) {
            case 1:
                searchitem();
                break;
            case 2:
                additem();
                break;
            case 3:
                updateitem();
                break;
            case 4:
                deleteitem();
                break;
            case 5:
                displayitem();
                break;
            case 6:
                surplusQuantityIdentification();
                break;
            case 7:
                lowQuantityIdentification();
                break;
            case 8:
                totalInventoryValueCalculation();
                break;
            case 9:
                itemQuantitySummationByCategory();
                break;
            case 10:
                itemExpiryTracking();
                break;
            case 11:
                salesData();
                break;
            case 12:
                printf("Contact us in case of any issue:\nRudra (202311073)\nRishabh (202311071)\nShreya\nPankaj\nYanshu\n");
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (input != 0);

    return 0;
}

void additem() {
    int j, n;
    Item* it;

    printf("Enter the number of items to add: ");
    scanf("%d", &n);

    it = (Item*)malloc(n * sizeof(Item));
    if (it == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    FILE* fp = fopen("inventory.txt", "a");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        exit(1);
    }

    for (j = 0; j < n; j++) {
        printf("\nEnter item details:\n");
        printf("Item Number: ");
        scanf("%d", &it[j].item_no);
        printf("Item Name: ");
        scanf("%29s", it[j].item_name);
        printf("Description: ");
        scanf("%299s", it[j].description);
        printf("Price: ");
        scanf("%f", &it[j].price);
        printf("Quantity in stock: ");
        scanf("%d", &it[j].quant_instock);
        printf("Expiry Date: ");
        scanf("%9s", it[j].expdate);
        printf("Category: ");
        scanf("%19s", it[j].category);

        fprintf(fp, "%d %s %s %f %d %s %s\n", it[j].item_no, it[j].item_name, it[j].description, it[j].price,
                it[j].quant_instock, it[j].expdate, it[j].category);
    }

    fclose(fp);
    free(it);
}

void searchitem() {
    FILE* fp = fopen("inventory.txt", "r");
    int choice;
    printf("Search by:\n1. Item Number\n2. Item Name\nEnter your choice: ");
    scanf("%d", &choice);
    int search_no;
    char search_name[30];
    if (choice == 1)
    {
        printf("Enter item number to search: ");
        scanf("%d", &search_no);
    } else
    {
        printf("Enter item name to search: ");
        scanf("%29s", search_name);
    }
    int found = 0;
    Item currentItem;

    while (fscanf(fp, "%d %s %s %f %d %s %s", &currentItem.item_no, currentItem.item_name, currentItem.description,&currentItem.price, &currentItem.quant_instock, currentItem.expdate, currentItem.category) != EOF)
    {
        if ((choice == 1 && currentItem.item_no == search_no) || (choice == 2 && strcmp(currentItem.item_name, search_name) == 0))
        {
            printf("\nItem Found:\n");
            printf("Item Number: %d\n", currentItem.item_no);
            printf("Item Name: %s\n", currentItem.item_name);
            printf("Description: %s\n", currentItem.description);
            printf("Price: %.2f\n", currentItem.price);
            printf("Quantity in stock: %d\n", currentItem.quant_instock);
            printf("Expiry Date: %s\n", currentItem.expdate);
            printf("Category: %s\n", currentItem.category);
            found = 1;
            break;
        }
    }
    fclose(fp);
}

void updateitem() {
    
}

void deleteitem() {
    
}

void displayitem() {
    FILE* fp = fopen("inventory.txt", "r");
    Item currentItem;
    while (fscanf(fp, "%d %s %s %f %d %s %s", &currentItem.item_no, currentItem.item_name, currentItem.description,&currentItem.price, &currentItem.quant_instock, currentItem.expdate, currentItem.category) != EOF)
    {
        printf("\n");
        printf("Item Number: %d\n", currentItem.item_no);
        printf("Item Name: %s\n", currentItem.item_name);
        printf("Description: %s\n", currentItem.description);
        printf("Price: %.2f\n", currentItem.price);
        printf("Quantity in stock: %d\n", currentItem.quant_instock);
        printf("Expiry Date: %s\n", currentItem.expdate);
        printf("Category: %s\n", currentItem.category);
        printf("\n");
    }
    fclose(fp);
}

void surplusQuantityIdentification() {
    
}

void lowQuantityIdentification() {
    
}

void totalInventoryValueCalculation() {
    
}

void itemQuantitySummationByCategory() {
    
}

void itemExpiryTracking() {
    
}

void salesData() {
    
}
