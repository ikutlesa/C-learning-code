//Slicno predloscima funkcija postoje i PREDLOSCI RAZREDA za 
//definiranje opcih razreda koji se zatim konkretiziraju 
//stvarnim tipovima. Tipican primjer za takve razrede su 
//spremnici ili kontejnerski razredi(cesto se koriste za
// pohranjivanje nizova objekata)
//Razred Lista realizirat cemo pomocu predlozaka
//Imat cemo dva razreda:
//(1) razred Lista ce definirati opca svojstva liste, vodit
//ce racuna o pocetnom i zavrsnom clanu te ce definirati 
//javno sucelje liste
//(2) razred ElementiListe ce definirati objekt koji se smjesta 
//u listu. Taj objekt ce sadzavati pokazivace na prethodni 
//i sljedeci element te samu vrijednost objekta

//Definicija predloska razreda: zapocinje tako da se iza 
//kljucne rijeci claa umetne kljucna rijec template iza koje
//se unutar znakova <i> navode argumenti predloska, npr:
//template <class Tip>
//class Lista;
//Sada cemo samo definirati razred ElementListe
//Slijed primjer definicije razreda ElementListe
#include <iostream>
using namespace std;

template <class Tip>
class ElementListe{
private:
	Tip vrij;
	ElementListe *prethodni, *sljedeci;
public:
	ElementListe *Prethodni(){
		return prethodni;
	}
	ElementListe *Sljedeci(){
		return sljedeci;
	}
    void PostaviPrethodni(ElementListe *pret){
		prethodni=pret;
	}
	void PostaviSljedeci(ElementListe *sljed){
		sljedeci=sljed;
	}
	ElementListe(const Tip &elem);
	ElementListe() {}
	Tip &DajVrijednost();
};

//Kao sto vidimo: unutar razreda se identifikator ElementListe
//koristi bez parametara, sto je i logicno: parametri su 
//navedeni u template deklaraciji ispred pocetka deklaracije
//razreda. Medjutim, izvan deklaracije razreda, pored identifikatora
//razreda se uvijek MORAJU NAVESTI PARAMETRI.

//pr. za ovo gore je (1)definicija konstruktora
template <class Tip>
inline ElementListe<Tip>::ElementListe(const Tip &elem){
	vrij=elem;
	prethodni=NULL;
	sljedeci=NULL;
}

//(2) definicija funkcijskog clana DajVrijednost()
template <class Tip>
inline Tip &ElementListe<Tip>::DajVrijednost(){
	return vrij;
}

//Moze se dogoditit da se predlozak treba instancirati unutar
//definicije drugog predloska. Tada se parametar predloska
//koji se definira moze koristiti kao stvarni parametar predloska
//koji se instancira. Npr. pretpostavimo da svakoj varijanti 
//razreda ElementListe zelimo pridruziti funkciju Ispisi()
//koja ce ispisati sadrzaj elementa na ekran. Takva funkcija se 
//mora definirati predloskom

template <class Tip>
void Ispisi(ElementListe<Tip> &Elem){//tu je Tip stvarni parametar
	ElementListe<Tip> *pok=&Elem;
	cout<<"Vrijednost elementa je: "<<pok->DajVrijednost()<<endl;
	cout<<"Vrijednost pokazivaca prethodni je: "<<pok->Prethodni()<<endl;
	cout<<"Vrijednost pokazivaca sljedeci je: "<<pok->Sljedeci()<<endl;
}

int main(){
	//Predlozak se instancira tako da se izvan naziva razreda
	//unutar znakova <i> navedu svi stvarni parametri predloska
	//Pa imamo za element tipa integer
	ElementListe<int> eli(3);
	cout<<eli.DajVrijednost()<<endl;
	cout<<eli.Prethodni()<<endl;
	cout<<eli.Sljedeci()<<endl;
	Ispisi<int>(eli);
	//Element koji je znakovni niz (char *)
	ElementListe<char *>  elz("Listam");
	cout<<elz.DajVrijednost()<<endl;
	//Kad bi imali definiran razred Kompleksni imali bi:
	//ElementListe<Kompleksni> elk(Kompleksni());
	//Ovo gore su sve razredi za pojedini tip
	
	return 0;
}
