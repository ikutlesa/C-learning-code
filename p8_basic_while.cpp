/*program izracunava vrijednost broja pi=3.141 prema formuli*/
/*pi/4=1-1/3+1/5-1/7+...Program se prekida kada se dobije clan cija*/
/*je apsolutna vrijednost manja od ucitanog epsilon */

#include <stdio.h>
void main(void)
	{
	  float suma,eps,clan;
      long i; 
	  int predznak;
	  clan=1.0;   /*prvi clan sume*/
	  predznak=-1; /*predznak drugog clana*/
	  suma=1.0; /*suma*/
      i=1;
	  do
		{
		  clan=(float)predznak/2*i+1; /*tekuci clan*/
		  suma+=clan;		  /*uvecaj sumu za vr. clana*/
		  predznak=-predznak; /*promjena predznaka*/
		  i++;
		} while((abs(clan)>eps));
	 printf("\n pi=%f", suma*4);
}
