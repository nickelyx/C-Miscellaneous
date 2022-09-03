#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void first_split(char *productcode,char *warehouse, char *id, char *quali);
void print(char *warehouse, char *id, char *quali);

int
main(void)
  {
  char productcode[16]="ATL1203S14", warehouse[4]="", id[6]="", quali[5]="";
  first_split(productcode, warehouse, id, quali); 
  print(warehouse, id, quali);
  return(0);
  }

void first_split(char *productcode,char *warehouse, char *id, char *quali)
  {
  int i=0, j=0, k=0;

  while (isupper((int)productcode[i]))
    {
    i++;
    }
  strncpy(warehouse, productcode,i);
  warehouse[i+1]='\0';
  j=i;
  while (isdigit((int)productcode[i]))
    {
    i++;
    }
  strncpy(id, productcode+j,i-j); 
  id[i-j]='\0';
  j=i;
  while (isprint((int)productcode[i]))
    {
    i++;
    }
  strncpy(quali, productcode+j,i-j);
  }

void print(char *warehouse, char *id, char *quali)
  {
  printf("\n\nWarehouse= %s\nProduct Id= %s\nQualifiers= %s",warehouse, id, quali);
  }