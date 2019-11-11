//Sljedeci program opisuje SPRCJALIZACIJU PREDLOZAKA FUNKCIJA
//Postoje situacije u kojima opceniti algoritam predloska
//moze biti neodgovarajuci ili neefikasan za pojedine tipove 
//podataka. U takvim slucajevima pisemo specijalizaciju 
//predloska funkcije. Npr. imamo funkciju manji() koja 
//usporedjuje dva objekta i kao rezultat vraca manji od njih.
//Medjutim, javlja se problem u slucaju da imamo za objekte
//dva znakovna niza. Operator < se u tom slucaju ne interpretira
//kao usporedba nizova , nego kao usporedba pokazivaca .

#include <iostream>
#include <cstring>
using namespace std;

//predlozak za opcenite tipove
template <class Tip>
Tip manji(Tip a,Tip b){
	return a<b ? a : b;
}

//specjalizacija za char slucaj(spesjalizacija se definira 
//bez koristenja kljucne rijeci template)
char *manji<char *>(char *a,char *b){//moze i bez <char *>
	return strcmp(a,b)<0 ? a : b;
}

int main(){
	int a,b;
	cout<<"Unesi dva broja:";
	cin>>a;
	cin>>b;
	cout<<"Mani od "<<a<<" i "<<b<<" je "<<manji(a,b)<<endl;
    char *n1="manji";
	char *n2="veci";
	//poziv specjalizacije
	char *rez=manji(n1,n2);
	cout<<rez<<endl;
	
	//Kod predlozaka s vise parametara moguce je napraviti i tzv.
	//DJELOMICNU SPECIJALIZACUJU: specjalizira se samo dio
	//parametara, dok se ostali ostave opcima: npr.
	//template <class T1,class T2>
	//void f();  //originalni predlozak
    
	//template <class T>
	//f<T,char>();   //djelomicna specjalizacija
}  