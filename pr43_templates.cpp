//PREDLOSCI I UGNJEZDENI TIPOVI(10.3.7 str 439)
//C++ dozvoljava ugnjezdene tipove.Npr. razred ElementLista iz
//prethodnih primjera mora biti parametriziran istim tipom kao
//i razred Lista. Dakle, svaka Lista ima odgovarajuci ElementListe
//(a i objekti razreda nemaju smisla osim u kontekst razreda 
//Lista,pa nebi bilo lose omoguciti stvaranje objekata razreda
//iz glavnog programa).Rjesenje problema bi bilo:
//template <class Tip>
//class Lista{
//private:
//     class ElementListe {
//     public:
//			 Tip vrij;
//			 ElementiListe *prethodni,*sljedeci;
//        };
//     ElementiListe *glava,*rep;
//};
//Ako su ugnjezdeni tipovi javni, moze im se pristupati iz 
//okolnog programa. Pri tome je potrebno potpuno navesti put
//do razreda kojem se zeli pristupiti . Svaka varijanta razreda 
//lista definira jedan razred ElementListe. Tako je moguce
//koristiti tipove
//Lista<int>::ElementiListe i Lista<char *>::ElementiListe

//Predlozak razreda takodjer moze imati ugnjezdjena pobrojenja.
//Njima se isto tako moze pristupiti iz okolnog podrucja pod
//uvjetim da se navede puna staza do tipa. Npr., razred Spremnik
//moze definirati pobrojenja koja opisuju redni broj zadnjeg
//elementa u spremniku te kriticnu velicinu spremnika koja je 
//jednaka 75% ukupne velicine:

#include <iostream>
using namespace std;

template <int duljina> //predlozak parametriziran izrazom
class Spremnik{
private:
	char podrucje[duljina];
public:
	enum {kriticna=(int)(0.75 * duljina),
		zadnji=duljina - 1, maksimum=1000};
	void Puni(char *pok, int dulj);
	void Citaj(char *pok, int dulji);
};

//Sada je moguce iz vanjskog programa pristupati pobrojenjima, 
//ali tako da se navede ukupna staza do identifikatora
int main(){
	cout<<Spremnik<20>::kriticna<<endl;
	cout<<Spremnik<99>::zadnji<<endl;
	//Punu stazu je potrebno navesti i prilikom pristupa identifikatoru
	//maksimum, bez obzira na to sto se vrijednost tog identifikatora
	//ne mijenja u tazlivitim instancijama razreda. Dakle sljedece
	//bi bilo pogresno:
	//cout<<Spremnik::maksimum<<endl; //pogresno
	//A ispravno bi bilo
	cout<<Spremnik<20>::maksimum<<endl; //ispravno
	return 0;
}
   
