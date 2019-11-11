//Jednostavan rad sa pokazivaèima

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
int *kazalo; //deklaracija varijable kazalo kao pokazivaè na broj tipa int
int n=5;    //deklaracija varijable n ipridruživanje vrijednosti 5
kazalo=&n;  //pridruživnje varijabli kazalo vrijednost mem.adr. na koju 
		    //je pohranjena varijabla n pa vrijednost n možemo dohvaæati
			//ili posredno preko pokazivaèa

cout<<"n= "<<n<<endl;             //ispisuje 5 
cout<<"kazalo= "<<*kazalo<<endl;  //...opet 5 
cout<< "kazalo= "<<kazalo<<endl;  //ispisuje mem.adr.varijable n
*kazalo +=5;
cout<<*kazalo<<endl;          //isto kao: n+=5; sada je n=10
n=*kazalo-2;                      //isto kao: n=n-2;  sada je n=8
cout<<"n= "<<n<<endl;
int m=3;
kazalo =&m;
cout<<*kazalo<<endl;          //treba ispisati 3
float x[5]={10,20,5,8,9};                  //x je ustvari pokazivaè na 1. el. polja
float a=x[2];
cout<<"a = "<<a<<endl;
a=*(x+2);
cout<<"a = "<<a<<endl;     //ekvivalentno prethodnom sluèaju  
cout<< x <<endl;           //adresa poèetnog èlana polja x
cout<< *x <<endl;          //vrijednos poèetnog èlana polja
cout<< &(x[1]) <<endl;     //adresa  èlana x[1]
cout<< (x+1)<< endl;	   //ista stvar kao i prethodni sluèaj
return 0;



}