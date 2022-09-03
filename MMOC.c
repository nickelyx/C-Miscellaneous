#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int Divide(char *Product_ID, char *Warehouse, char *Product, char *Qualifier);

int main(void)
{
    char Product_ID[16] = "ATL1203S14"; 
    char Warehouse[4] = ""; 
    char Product[6] = "";
    char Qualifier[5] = "";
    
    Divide(Product_ID, Warehouse, Product, Qualifier);
    
    printf("\nWarehouse: %s\nProduct: %s\nQualifier: %s", Warehouse, Product, Qualifier);
    
    return 0;
}

int Divide(char *Product_ID, char *Warehouse, char *Product, char *Qualifier)
{
    int i = 0, j = 0;

    /*Finds the lenght of uppercase letters*/
    while(isupper((int) Product_ID[i]))
    {
        i++;
    }

    /*Puts a \0 at the end of the warehouse*/
    strncpy(Warehouse, Product_ID, i);
    Warehouse[i + 1] = '\0';    
    j = i;

    /*Finds the length of digits*/
    while(isdigit((int) Product_ID[i]))
    {
        i++;
    }

    /*Puts a \0 at the end of the product*/
    strncpy(Product, Product_ID + j, i - j); 
    Product[i - j] = '\0';
    j = i;

    /*Finds the lenght of printable characters*/
    while(isprint((int) Product_ID[i]))
    {
        i++;
    }

    strncpy(Qualifier, Product_ID + j, i - j);

    return 0;
}