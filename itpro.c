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
void filterBYprice();

int main() {
    int input;

    do {
        printf("\n\t** USER PANEL **\n\n");
        printf("(1) Search item\n(2) Add item\n(3) Update item info\n(4) Delete item\n(5) Display inventory\n\n");
        printf("* Run Search for :\n");
        printf("(6) Surplus Quantity Identification\n(7) Low-Quantity Identification\n(8) Total Inventory Value Calculation\n(9) Item Quantity Summation by Category\n(10) Item Expiry Tracking\n(11) Display items in given price range \n");
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
                filterBYprice();
                break;
            case 12:
                printf("Contact us in case of any issue:\nRudra (202311073)\nRishabh (202311071)\nShreya (202311080)\nPankaj (202311061)\nYanshu (202311088)\n");
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
    printf("Search by:\n1. Item Number\n2. Item Name\nEnter your choice: \n3. Category: \n");
    scanf("%d", &choice);
    int search_no;
    char search_name[30];
    char search_cat[30];
    if (choice == 1)
    {
        printf("Enter item number to search: ");
        scanf("%d", &search_no);
    }
    else if(choice == 2)
    {
        printf("Enter item name to search: ");
        scanf("%29s", search_name);
    }
    else
    {
        printf("Enter item category to search: ");
        scanf("%29s", search_cat);
    }
    int found = 0;
    Item currentItem;

    while (fscanf(fp, "%d %s %s %f %d %s %s", &currentItem.item_no, currentItem.item_name, currentItem.description,&currentItem.price, &currentItem.quant_instock, currentItem.expdate, currentItem.category) != EOF)
    {
        if ((choice == 1 && currentItem.item_no == search_no) || (choice == 2 && strcmp(currentItem.item_name, search_name) == 0) || (choice == 3 && strcmp(currentItem.category, search_cat)==0))
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
    int num_line,total_line=0,sel;
	char ch,choice='Y';
	FILE *fp= fopen("inventory.txt", "r");
	while((ch=getc(fp))!=EOF)
    {
		if(ch=='\n')
		total_line++;
	}
	struct item *p = (struct item *)malloc(total_line*sizeof(struct item));
	rewind(fp);
	for(int i = 0; i < total_line; i++)
    fscanf(fp, "%d %s %s %f %d %s %s", &(p + i)->item_no, (p + i)->item_name, (p + i)->description, &(p + i)->price, &(p + i)->quant_instock, (p + i)->expdate, (p + i)->category);

    fclose(fp);
    printf("Enter the item no.\n");
    scanf("%d", &num_line);
    while(choice=='Y'|| choice=='y')
    {
		printf("for changes\n Enter 1 for item_name\n Enter 2 for description\n Enter 3 for price\n Enter 4 for quant_instock\n Enter 5 for expdate \n Enter 6 for category\n");
		scanf("%d",&sel);
		switch (sel) {
		        case 1:
		            printf("enter new Item  Name\n");
		            scanf("%s",(p + num_line - 1)->item_name);
		            break;
		        case 2:
		            printf("enter new Description\n");
		            scanf("%s",(p + num_line - 1)->description);
		            break;
		        case 3:
		            printf("enter new Price\n");
		            scanf("%f",&(p + num_line - 1)->price);
		            break;
		        case 4:
		            printf("enter new Quantity in stock\n");
		            scanf("%d",&(p + num_line - 1)->quant_instock);
		            break;
		        case 5:
		            printf("enter new Expiry Date\n");
		            scanf("%s",(p + num_line - 1)->expdate);
		            break;
		        case 6:
		            printf("enter new category\n");
		            scanf("%s",(p + num_line - 1)->category);
		            break;
		        default:
		            printf("Enter Correct Number . Please try again.\n");
    	}
    	printf("Continue? 'Y'/'N'");
    	scanf(" %c",&choice);
    }
    fp = fopen("inventory.txt", "w");
    for(int i = 0; i < total_line; i++)
    fprintf(fp, "%-3d %-15s %8s %-12f %-5d %-10s %-10s\n", (p + i)->item_no, (p + i)->item_name, (p + i)->description, (p + i)->price, (p + i)->quant_instock, (p + i)->expdate, (p + i)->category);

    printf("\nUdpate Successfully\n");
    fclose(fp);
    free(p);
}

void deleteitem() {
    int del_line,total_line=0,i=0;
	char ch,del_name[50];
	FILE *fp= fopen("inventory.txt", "r");
	while((ch=getc(fp))!=EOF){
		if(ch=='\n'){
			total_line++;
		}
	}
	struct item *p = (struct item *)malloc(total_line*sizeof(struct item));
	rewind(fp);
	for(int i = 0; i < total_line; i++){
        fscanf(fp, "%d %s %s %f %d %s %s", &(p + i)->item_no, (p + i)->item_name, (p + i)->description, &(p + i)->price, &(p + i)->quant_instock, (p + i)->expdate, (p + i)->category);
    }
    fclose(fp);
    printf("Enter item number to delete: ");
    scanf("%d", &del_line);

    fp = fopen("inventory.txt", "w");
    for(i = 0; i < total_line; i++)
    {
    	if(i!=(del_line-1))
    	{
    		fprintf(fp, "%-3d %-15s %8s %-12f %-5d %-10s %-10s\n", (p + i)->item_no, (p + i)->item_name, (p + i)->description, (p + i)->price, (p + i)->quant_instock, (p + i)->expdate, (p + i)->category);
    	}
    }
    fclose(fp);
	printf("\nDelete Successfully\n");
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
    FILE* fp = fopen("inventory.txt", "r");
    int choice;
    printf("Enter the stock amount above which you want to check\n");
    scanf("%d", &choice);
    Item currentItem;
    printf("\nthe items with more stock the entered value :\n\n");

    while (fscanf(fp, "%d %s %s %f %d %s %s", &currentItem.item_no, currentItem.item_name, currentItem.description,&currentItem.price, &currentItem.quant_instock, currentItem.expdate, currentItem.category) != EOF)
    {
        if (currentItem.quant_instock>=choice)
        {
            printf("\n\n");
            printf("Item Number: %d\n", currentItem.item_no);
            printf("Item Name: %s\n", currentItem.item_name);
            printf("Description: %s\n", currentItem.description);
            printf("Price: %.2f\n", currentItem.price);
            printf("Quantity in stock: %d\n", currentItem.quant_instock);
            printf("Expiry Date: %s\n", currentItem.expdate);
            printf("Category: %s\n", currentItem.category);
            printf("\n\n");
        }
    }
    fclose(fp);
}

void lowQuantityIdentification() {
    FILE* fp = fopen("inventory.txt", "r");
    int choice;
    printf("Enter the stock amount below which you want to check\n");
    scanf("%d", &choice);
    Item currentItem;
    printf("\nthe items with less stock the entered value :\n\n");

    while (fscanf(fp, "%d %s %s %f %d %s %s", &currentItem.item_no, currentItem.item_name, currentItem.description,&currentItem.price, &currentItem.quant_instock, currentItem.expdate, currentItem.category) != EOF)
    {
        if (currentItem.quant_instock<=choice)
        {
            printf("\n\n");
            printf("Item Number: %d\n", currentItem.item_no);
            printf("Item Name: %s\n", currentItem.item_name);
            printf("Description: %s\n", currentItem.description);
            printf("Price: %.2f\n", currentItem.price);
            printf("Quantity in stock: %d\n", currentItem.quant_instock);
            printf("Expiry Date: %s\n", currentItem.expdate);
            printf("Category: %s\n", currentItem.category);
            printf("\n\n");
        }
    }
    fclose(fp);
}

void totalInventoryValueCalculation() {
    FILE* fp = fopen("inventory.txt", "r");
    int value=0;
    Item currentItem;
    while (fscanf(fp, "%d %s %s %f %d %s %s", &currentItem.item_no, currentItem.item_name, currentItem.description,&currentItem.price, &currentItem.quant_instock, currentItem.expdate, currentItem.category) != EOF)
    {
        value+=(currentItem.price * currentItem.quant_instock);
    }

    printf("\n** The total value of your inventory is : %d **\n",value);
    fclose(fp);
}

void itemQuantitySummationByCategory() {
    FILE* fp = fopen("inventory.txt", "r");
    int value=0;
    Item currentItem;
    char cat[20];
    printf("Enter the category\n");
    scanf("%19s",cat);
    while (fscanf(fp, "%d %s %s %f %d %s %s", &currentItem.item_no, currentItem.item_name, currentItem.description,&currentItem.price, &currentItem.quant_instock, currentItem.expdate, currentItem.category) != EOF)
    {
        if(strcmp(currentItem.category,cat)==0)
        {
            printf("Item Number: %d\n", currentItem.item_no);
            printf("Item Name: %s\n", currentItem.item_name);
            printf("Quantity in stock: %d\n", currentItem.quant_instock);
            value+=(currentItem.quant_instock);
        }
    }
    printf("\nThe total quantity of items in this category is : %d\n",value);
    fclose(fp);
}

void itemExpiryTracking() {
    FILE* fp = fopen("inventory.txt", "r");
    int dd,mm,yy,a,b,c;
    printf("Enter today's date : dd mm yy\n");
    scanf("%d %d %d",&dd,&mm,&yy);
    Item currentItem;
    while (fscanf(fp, "%d %s %s %f %d %s %s", &currentItem.item_no, currentItem.item_name, currentItem.description,&currentItem.price, &currentItem.quant_instock, currentItem.expdate, currentItem.category) != EOF)
    {
        sscanf(currentItem.expdate,"%d/%d/%d",&a,&b,&c);
        if ( yy>c )
            {
                printf("\n\n");
                printf("Item Number: %d\n", currentItem.item_no);
                printf("Item Name: %s\n", currentItem.item_name);
                printf("Description: %s\n", currentItem.description);
                printf("Price: %.2f\n", currentItem.price);
                printf("Quantity in stock: %d\n", currentItem.quant_instock);
                printf("Expiry Date: %s\n", currentItem.expdate);
                printf("Category: %s\n", currentItem.category);
                printf("\n\n");
            }
        else if(yy==c && mm>b)
            {
                printf("\n\n");
                printf("Item Number: %d\n", currentItem.item_no);
                printf("Item Name: %s\n", currentItem.item_name);
                printf("Description: %s\n", currentItem.description);
                printf("Price: %.2f\n", currentItem.price);
                printf("Quantity in stock: %d\n", currentItem.quant_instock);
                printf("Expiry Date: %s\n", currentItem.expdate);
                printf("Category: %s\n", currentItem.category);
                printf("\n\n");
            }
        else if(yy==c && mm==b && dd>=a)
            {
                printf("\n\n");
                printf("Item Number: %d\n", currentItem.item_no);
                printf("Item Name: %s\n", currentItem.item_name);
                printf("Description: %s\n", currentItem.description);
                printf("Price: %.2f\n", currentItem.price);
                printf("Quantity in stock: %d\n", currentItem.quant_instock);
                printf("Expiry Date: %s\n", currentItem.expdate);
                printf("Category: %s\n", currentItem.category);
                printf("\n\n");
            }
    }
    fclose(fp);
}

void filterBYprice() {
    FILE* fp = fopen("inventory.txt", "r");
    float max,min;
    printf("Enter Max price :  ");
    scanf("%f",&max);
    printf("Enter Min price :  ");
    scanf("%f",&min);

    Item currentItem;
    while (fscanf(fp, "%d %s %s %f %d %s %s", &currentItem.item_no, currentItem.item_name, currentItem.description,&currentItem.price, &currentItem.quant_instock, currentItem.expdate, currentItem.category) != EOF)
    {
        if (currentItem.price >= min && currentItem.price <= max)
        {
            printf("\n\n");
            printf("Item Number: %d\n", currentItem.item_no);
            printf("Item Name: %s\n", currentItem.item_name);
            printf("Description: %s\n", currentItem.description);
            printf("Price: %.2f\n", currentItem.price);
            printf("Quantity in stock: %d\n", currentItem.quant_instock);
            printf("Expiry Date: %s\n", currentItem.expdate);
            printf("Category: %s\n", currentItem.category);
            printf("\n\n");
        }
    }
    fclose(fp);
}
