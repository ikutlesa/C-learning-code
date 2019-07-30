//ilustracija rada s pokazivacima
#include <stdio.h>

void main(void)
{
   int     *px; //deklaracija pokazivaca na cijelobrojnu vrijednost
   int   y,x;
   float f,*pf;
   
   y=128;
   px=&y;  //pokazivac px sadrzi adresu na kojoj s nalazi varijabla y
   x=*px;  //x postavljamo na vrijednost sa adrese pok. px a to je 
			//upravo vrijednost varijable y
   printf("\nAdresa varijable y=%p",&y);
   printf("\nAdresa na koju pokazuje px=%p",px);
   printf("\nVrijednost varijable y je %d",y);
   printf("\nVrijednost sa adrese pokazivaca px je %d",*px);
   printf("\nDakle vrij. sa adrese pok. px je upravo vrij. varijab. y\n");
   
   //npr.  pf=100; 
   //pokazivac nakon izraza  pf+=10; ce sadrzavati vrijednost 140, jer
   //je pokazivavc pc deklariran kao tip float, a realni tip podataka 
   //zauzima 4 bajta u memoriji, povecanje pokazivaca za 10 povecat ce
   //adrssu za 10*4 bajta. Pa se rezuktat dobije iz izraza:
       //adresa = tekuca_adresa + (sizeof(tip_podataka) * broj);
   f=111.11;
   pf=&f;
   printf("Vrijednost pokazivaca prije povecanja je %p\n",pf);
   pf+=10;
   printf("Vrijednost pokazivaca nakon povecanaj za 10 je %p\n",pf);
}
