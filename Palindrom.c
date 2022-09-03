#include <stdio.h>
#include <string.h>

int is_palindrome_rec(char *str);
int is_palindrome_rec_len(char *str, int lgt);
int is_palindrome_iter(char *str);



int main(void) 
{
  char str[100];

  do
  {
    printf("Enter string (the string exit will stop the program): ");
    scanf("%s", str);

    if (strcmp(str,"exit") != 0){
      if (is_palindrome_iter(str))
        printf("Iterative %s is a palindrome\n", str);
      else
        printf("Iterative: %s is NOT a palindrome\n", str);
    }

    if (strcmp(str,"exit") != 0){
      if (is_palindrome_rec(str))
        printf("Recursive: %s is a palindrome\n", str);
      else
        printf("Recursive: %s is NOT a palindrome\n", str);
    }

  }
  while (strcmp(str,"exit") != 0);

  return 0;
}


int is_palindrome_rec(char *str)
{
  int lgt = strlen(str);
  return is_palindrome_rec_len(str, lgt);
}

int is_palindrome_rec_len(char *str, int lgt)
{
  if (lgt < 2)
    return 1;
  else
    return str[0] == str[lgt-1] && is_palindrome_rec_len(str+1, lgt-2);
}

int is_palindrome_iter(char *str)
{
  int i, j;
  for(i = 0, j = strlen(str)-1; i < j; i++, j--)
    if (str[i] != str[j]) 
      return 0;
  return 1;     
}