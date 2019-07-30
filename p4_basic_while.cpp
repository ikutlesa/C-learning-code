/*program izraèunava faktorijele unesene cijelobrojne vrijednosti*/

#include <stdio.h>

void main(void)
{
 long int fakt, i;
 printf("Unesite vrijednost: ");
 scanf("%d",&i);
 fakt=1;
 while (i > 1)
	{ 
	 fakt=fakt*i;
	 i=i-1;
	}
 printf("\nFaktorijel = %ld\n",fakt);
}