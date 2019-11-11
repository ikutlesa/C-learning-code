//ilistracija promjene pokazivaca unutar funkcije

#include <iostream>
#include <iomanip>
using namespace std;

char *UnesiIme1(char *ime) //ako nema * ispred UnesiIme van f-je necemo
{					      //dobiti promjenu van f-je
	  cout<<"Upisi ime:";
	  ime=new char[100];  //pridruzuje se adresa alociranog mem. bloka
	  cin>>ime;			  //na to mjesto ucitava znakovni niz (korisnik)
	  return ime;	      //vraca pokazivac na novi objekt, tj. na zn.niz	 
}					      //upisan na alociranu mem. lokaciju

//ista stvar samo preko reference

void UnesiIme2(char * & ime) //argument je referenca na pokazivac
	{
	  cout <<"Upisi ime:";
	  ime=new char[100];    //pristup preko reference
	  cin>>ime;
	}

int main()
	{   
	   char *korisnik1="";     //inicijalizaija zbog prevoditelja
	   korisnik1=UnesiIme1(korisnik1); //korisnik se prenosi kao argument 
	   cout<<korisnik1<<endl;		//f-ji UnesiIme() te mu se odmah 
	   delete [] korisnik1;   	   //pridruzuje vrij. koju f-ja vraca
	   char *korisnik2;
	   UnesiIme2(korisnik2);       //proslijedjuje se adresa ali to nije
								   //potrebno eksplicitno navesti
	   cout<<korisnik2<<endl;
	   delete [] korisnik2;
	   return 0;
	}
