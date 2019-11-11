//programcic(odredjivanje minimuma dvaju elemenata nekog tipa)
// ilustrira definiciju  predloska funkcije koja zapocinje
//kljucnom rijeci template. Svaki predlozak ima jos i listu formalnih 
//parametara koja se navodi izmedju znakova <(manje od) i >(vece od)
//Lista parametara ne moze biti prazna. Svaki formalni parametar se
//sastoji od kljucne rijeci class iza koje se navodi identifikator
//Taj identifikator predstavlja neki ugradjeni ili korisnicki tip
//koji ce se navesti prilikom poziva funkcije.

#include <iostream>
using namespace std;

//Funkcija manji()
template <class NekiTip>
NekiTip manji(NekiTip a,NekiTip b){
	return a < b ? a : b;
}

//rjesenje za ovo je mogla biti i obicna makro naredba
//#define manji(a,b)    ((a) <(b) ? (a) : (b))
int main(){
	//NekiTip je u ovom slucaju int
	cout<<manji(2,3)<<endl; //radilo bi i kod makro naredbe
	int i=4,j;
	j=manji(++i,10);  //nebi radilo kod makro naredbe
	cout<<j<<endl;    //dobili bi br. 6 a ne 5 sto ocekujemo jer 
	return 0;		  // i 2 puta uvecava
}