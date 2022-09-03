#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
void first_split(char *Product_ID,char *Warehouse, char *Product, char *Qualifier);
void print(char *Warehouse, char *Product, char *Qualifier);

int
main(void)
  {
  char Product_ID[16]="ATL1203S14", Warehouse[4]="", Product[6]="", Qualifier[5]="";
  first_split(Product_ID, Warehouse, Product, Qualifier); 
  print(Warehouse, Product, Qualifier);
  return(0);
  }

void first_split(char *Product_ID,char *Warehouse, char *Product, char *Qualifier)
  {
  int i=0, j=0, k=0;

  while (isupper((int)Product_ID[i]))
    {
    i++;
    }
  strncpy(Warehouse, Product_ID,i);
  Warehouse[i+1]='\0';
  j=i;
  while (isdigit((int)Product_ID[i]))
    {
    i++;
    }
  strncpy(Product, Product_ID+j,i-j); 
  Product[i-j]='\0';
  j=i;
  while (isprint((int)Product_ID[i]))
    {
    i++;
    }
  strncpy(Qualifier, Product_ID+j,i-j);
  }

void print(char *Warehouse, char *Product, char *Qualifier)
  {
  printf("\n\nWarehouse= %s\nProduct= %s\nQualifiers= %s",Warehouse, Product, Qualifier);
  }