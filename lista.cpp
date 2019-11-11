//LISTA (16.4.2. STR 615)
//Lista je struktura u kojoj brzina umetanja, odnosno izbacivanja
//elemenata ne ovisi o njegovom polozaju. Nezgodna strana liste jest da 
//se pojedini clanovi ne mogu dohvatiti izravno, vec se do pojedinog
//clana dolazi postepeno "krstareci" kroz listu, pocevsi od njene glave 
//ili repa. Zbog toga operator indeksiranja [] za liste nije definiran.
//Taj problem rijesavaju iteratori(pametni pointeri)
#include <list>       //spremnik ce biti list
#include <iostream>  //u spremniku ce biti string
#include <string>
using namespace std;

//funkcija za ispis clanova liste uz koristenje iteratora obradjenih
//na vjezbama

template <class T>
void print(list<T> &l)
	{
      list<T>::iterator i=l.begin();
	  for( ;i!=l.end();++i)
	  cout<<*i<<endl;
	  cout<<endl;
	}

int main(){
list<string> mojeNajboljePrijateljice;
//Lista podrzava i nekoliko njoj specificnih operacija. Sve te operacije
//su stabline, sto znaci da odrzavaju medjusobni redosljed elemenata
//koji imaju jednake vrijednosti: Funkcijski clanovi svojstveni listi su:
//(1)splice() prebacuje elemente iz zadane liste(koja se navodi kao drugi
//argument) u tekucu listu na polozaj koji se navodi kao prvi argument
//poziva . Prilikom prebacivanja elementi se iz izvorne liste uklanjaju
//(2) sort() razvrstava elemente liste po rastucem slijedu ili koristeci
//operator koji se proslijedjuje kao opcijski argument. 

//punimo listu stringovima
mojeNajboljePrijateljice.push_back(string("Mare"));
mojeNajboljePrijateljice.push_back(string("Kate"));
mojeNajboljePrijateljice.push_back(string("Dalmatinka"));
mojeNajboljePrijateljice.push_back(string("Djevojka sa "
								          "sela"));
cout<<"Unesena lista je:"<<endl;
print(mojeNajboljePrijateljice);

cout<<"A sada sortirana lista bi bila:"<<endl<<endl;
//razvrstavamo niz mojeNajboljePrijateljice  po abecedi
mojeNajboljePrijateljice.sort();
print(mojeNajboljePrijateljice);

//postoji i funkcija push_back() koja stavlja element liste na kraj liste
list<string> ostalePrijateljice;
ostalePrijateljice.push_back(string("Ena"));
ostalePrijateljice.push_back(string("Ivana"));
cout<<"Unesena lista je:"<<endl;
print(ostalePrijateljice);

//funkcija merge prebacuje elemente iz druge liste, tj. radi stopljenu
//listu od dvije liste. Ako su obje liste prije stapanja bile razvrstane
//tada ce elementi stopljene liste bitit razvrstani
mojeNajboljePrijateljice.merge(ostalePrijateljice);
//nakon ovog ce lista mojeNajboljePrijateljice sadrzavati i elemente
//Ena i Ivana. Svi elementi u prosirenoj listi bit ce razvrstani po 
//abecedi; ovo vrijedi samo u slucaju da su obje liste prije stapanja
//razvrstane. buduci da se elementi iz liste ostalePrijateljice prebacuju
//bez preslikavanja, ona ce nakon merge ostati prazna
print(mojeNajboljePrijateljice);

list<int> l1;
l1.push_back(1);
print(l1);
list<int> l2;
l2=l1;
print(l2); 
return 0;
}
