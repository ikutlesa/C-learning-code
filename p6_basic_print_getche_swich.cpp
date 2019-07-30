/*Primjer korištenja do-while petlje*/
/*Program prikazuje izbor za èetri raèunske operacije: zbrajanje, */
/*množenje i dijeljenje, te ovisno o unesenom poèetnom slovu omoguæuje*/
/*unos dviju realnih vrijednosti i prikazuje rezultat izabrane operac.*/
/*Kraj programa odreðen je unosom slova 'k' ili 'K'*/

#include <stdio.h>
#include <conio.h>

void main(void)
{
  float x,y;
  char ch;

  do
  {
	  printf("\n Brojevi: ");
	  scanf("%f %f", &x,&y);     /*uèitavanje brojeva*/
	  printf("\n Operacija: ");
	  printf("\n ===========");
	  printf("\n Zbrajanje ");
	  printf("\n Oduzimanje");

	  printf("\n Mnozenje");
	  printf("\n Dijeljenje");
	  printf("\n Kraj\n");
	  ch=getche();             /*uèitaj operaciju*/

	  switch(ch)
	  {
	     case 'Z':
		   printf("\n %f + %f = %f",x,y,x+y);
	     break; 
		 case 'O':
		   printf("\n %f - %f = %f",x,y,x-y);
		 break;
		 case  'M':
		   printf("\n %f * %f = %f",x,y,x*y);
		 break;
		 case 'D':
			 printf("\n %f / %f = %f",x,y,x/y);
		 break;
		 case 'K':
		 case 'k':
		 break;
		 default:
			 printf("\n Pogrešna tipka ...");
	  }
	} while (ch != 'K' && ch != 'k');
	  printf("\n.....Kraj.....\n");
  }




		 