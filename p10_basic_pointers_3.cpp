//program je ilustracija rada polja i pokazivaca
//Polje je niz podataka istog tipa koji su u memoriji zapisani u kontinu-
//iranom slijedu. Buduci da pokazivaci sadrze adrese objekata (podataka)
//u memoriji i da adresna aritmetika omogucuje kretanje kroz meoriju, 
//mozemo zakljuciti da se polja mogu zamijeniti pokazivacima

#include <stdio.h>
 
void main(void)
{
	int p[5]={1,2,3,4,5}; 
			  //deklaracija jednodimenzionalnog cijelobrijnog polja od 
              //5 clanova
	int *pp;  //deklaracija pokazivaca pp na cijelobrijnu vrijednos
	
	
	pp=p;     //incijalizacija pok. pp t.d. mu je pridruzena pocetna
	          //vrijednost polja, isto kao da pise pp=p[0];
	int vrijednost,i;
		
	printf("Pocetni clanovi polja su:\n");
	for(i=0;i<5;i++)
		printf("	%d",p[i]);
	vrijednost=*pp; //vrijednost prvog clana polja
	printf("\nVrij. varijeable vrijednost je %d",vrijednost);
	*pp=100;        //promijena vrijednosti prvog clana polja
    printf("\nVrij. prvog clana polja nakon promijene preko pok. pp je %d",pp[0]);
    vrijednost=*(p+2); //vrijednost treceg clana polja
	printf("\nvrij. 3. clana polja preko varijable vrijednost je %d",vrijednost);
    vrijednost=pp[2]; //vrijednost treceg clana polja
	printf("\nvrij. varijable vrijednost je ista %d\",vrijednost);
//zakljucak: indeks clana polja odgovara cijelobrojnoj vrijednosti za
//koju se povecava pokazivac. Upravo zato indeksi clanova polja polaze
//od 0, a ne od 1

//*******Pokazivaci i niz znakova************
//Niz znakova u C-u definiran je preko jednodimenzionalnog polja znakova 
//Kako su polja i pokazivaci u C-u zamijenjivi proistjece da se i niz 
//znakova moze zamijeniti pokazivacima

//char string[80];
//char *pc;

//pc=& string[0]; //ili pc=string;
//printf("Vrijednost sa adrese pc je %c",*pc);
}