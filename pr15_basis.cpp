//polja kao argumenti u funkciji, program postvlja sve clanove poja na 0
//vazno je: POLJE SE NE PRENOSI PO VRIJEDNOSTI VEC SE PRENOSI POKAZIVAC
//NA NJEGOV PRVI CLAN

#include <iostream>
#include <iomanip>
using namespace std;

void Pocisti1(int polje[], int duljina) //moglo je i: 
//void Pocisti(int polje[5], int duljina);
//void Pocisti(int *polje, int duljina);
	{
	  while (duljina--)
		  polje[duljina]=0;
	}

//ista stvar samo koristenje aritmetike sa pokazivacima
void Pocisti2(int *polje, int duljina)
	{
	  int i=0;
	  while(duljina--)
		{
		 *(polje+i)=0;
		 i++;
	  }
	}	
int main()
	{
	int b[]={3,10,15};
	Pocisti1(b,3);
	cout<<b[0]<<endl    //doista je pocistio
		<<b[1]<<endl
		<<b[2]<<endl;
	
	int c[]={1,4,5,6,7};
    Pocisti2(c,5);
	cout<<endl<<c[0]<<endl
		<<c[1]<<endl
		<<c[2]<<endl;
	return 0;
	}	
