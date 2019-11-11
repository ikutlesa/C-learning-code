//Jednostavan rad sa pokaziva�ima

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
int *kazalo; //deklaracija varijable kazalo kao pokaziva� na broj tipa int
int n=5;    //deklaracija varijable n ipridru�ivanje vrijednosti 5
kazalo=&n;  //pridru�ivnje varijabli kazalo vrijednost mem.adr. na koju 
		    //je pohranjena varijabla n pa vrijednost n mo�emo dohva�ati
			//ili posredno preko pokaziva�a

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
float x[5]={10,20,5,8,9};                  //x je ustvari pokaziva� na 1. el. polja
float a=x[2];
cout<<"a = "<<a<<endl;
a=*(x+2);
cout<<"a = "<<a<<endl;     //ekvivalentno prethodnom slu�aju  
cout<< x <<endl;           //adresa po�etnog �lana polja x
cout<< *x <<endl;          //vrijednos po�etnog �lana polja
cout<< &(x[1]) <<endl;     //adresa  �lana x[1]
cout<< (x+1)<< endl;	   //ista stvar kao i prethodni slu�aj
return 0;



}