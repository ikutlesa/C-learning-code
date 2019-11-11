//prgram racuna duljinu znakovnog niza (f-ja strlen)
//znakovni nizovi su takodjer polja, sto znaci da f-ji treba prenjeti 
//pokazivac na prvi clan. Kako su znakovni nizovi zakljuceni nul-znakom,
//podatak o duljini niza nije nephodno prenijeti

#include <iostream>
#include <iomanip>
using namespace std;

int str_len(char *niz)
	{
	 int i=0;
	 while(*(niz+i)!=0)
		 i++;
	 return i;
	}
char *dolijepi(char *prvi, char *drugi, char *spojeni=0)
//da je spojeni lokalni objekt unutar funlcije nebi radilo)
	{
	 
	spojeni=new char[str_len(prvi)+str_len(drugi)+1];
	char *indeks=spojeni;
	while (*prvi)
		*(indeks++)=*(prvi++);
	while (*drugi)
		*(indeks++)=*(drugi++);
	*indeks='\0';
	return spojeni;
	}
	
	//funkcija za kopiranje jednog stringa u drugi
    void str_copy(char *str1,char *str2)
		{
		 while(*(str1++)=*(str2++));
		}
		
	int main()
	{
	  char *string="INES";
	  //cout<<"Unesi niz zanakova:";
	  //cin>>*string;
	  cout<<"Duljina niza je:"<<str_len(string)<<endl;;
	  char *pocetak="plan";
	  char *kraj="iranje";
	  char *zajedno="";
	  zajedno=dolijepi(pocetak,kraj,zajedno);
	  cout<<zajedno<<endl;
	  cout<<"Duljina niza "<<zajedno<<" je "<<str_len(zajedno)<<endl;
	  delete [] zajedno;
	  char *q="Ines";
	  char *p=new char[str_len(q)+1];
	  str_copy(p,q);
	  cout<<p<<endl;
	  delete [] p;
	  return 0;
	}