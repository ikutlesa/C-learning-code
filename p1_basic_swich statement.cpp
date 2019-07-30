/* Program unosi broj i ispisuje dali je jednak 1 ili 2 ili */
/* nesto drugo */

#include <stdio.h>

void main()
{
  int i;
  printf("Unesi broj:\n");
  scanf("%d",&i);
  switch(i)
  {
  case 1:
	  printf("\nBroj 1\n");
	  break;
  case 2:
	  printf("\nBroj 2\n");
	  break;
  default:
	  printf("\nNiti 1 niti 2\n");
  }
}