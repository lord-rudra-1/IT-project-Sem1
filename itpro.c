#include<stdio.h>
struct item{
    int item_no;
    char item_name[30];
    char discription[300];
    float price;
    int quant_instock;
    int expdate;
    char category[20];
};
int  main()
{
    int input;
    printf("\n\t** USER PANNEL **\n\n");
    printf("* Search item (1)\n* Add item (2)\n* Update item info (3)\n* Delete item (4)\n* Display inventory status (5)\n\n");
    printf("* Run Search for :\n");
    printf("Surplus Quantity Identification (6)\nLow-Quantity Identification (7)Total Inventory Value Calculation (8)\nItem Quantity Summation by Category (9)\nItem Expiry Tracking (10)\nSales Data (11)\n");
    printf("\n* Help (12)\n\n");

    scanf("%d",&input);

    FILE*fp=fopen("inventory data","a");
    return 0;
}

