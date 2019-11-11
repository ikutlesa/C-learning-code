//program je primjer rada sa pokazivacem na pokazivace uz alokaciju mem.

#include <iostream>
#include <iomanip>
using namespace std;

int main()              
{                       //dvaDpolje je pok. na pok. na var tiipa float
  float **dvaDpolje;  //uravo tako nemoramo odmah odrediti dimenije po.
  int i,redaka,stupaca;//i mozemo imati dvodim. polje sa razlicitim 
						 //brojem stupaca za svaki redak
  cout<<"Broj redaka: ";
  cin>>redaka;
  dvaDpolje=new float*[redaka]; //alociran prostor za polje poka.na float
  for(i=0;i<redaka;i++)
	{
	  cout <<"Broj clanova u "<<(i+1)<<".  retku:";
	  cout <<"Broj stupaca za taj redaka:";
	  cin>>stupaca;
	  dvaDpolje[i]=new float[stupaca+1];//alociranje prostora za clanove 
	  dvaDpolje[i][0]=stupaca;			//svakog pojedinog retka
		   for(int j=1;j<=stupaca;j++)
			   dvaDpolje[i][j]=i+1+j/100;
	}
	 cout<<"Ispis clanova polja:"<<endl;
	 for(i=0;i<redaka;i++)
		 for(int j=0;j<=dvaDpolje[i][0];j++)
			 cout<<"["<<i<<"]""["<<j<<"]"="<<dvaDpolje[i][j]<<endl;
    //slijedi oslibadjanje alociranog prostora
	for(i=0;i<redaka;i++)
		delete [] dvaDpolje[i];
	delete [] dvaDpolje;
	return 0;
}