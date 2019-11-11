//Prilikom definiranja predloska moguce je navesti  staticke
//clanove. U tom slucaju svaka instanca navedenog predloska
//ce imati svoj zasebni skup statickih clanova. Svaki od tih
//clanova se mora inicijalizirati zasebno.Npr.: Zelimo brojati 
//ukupan broj listi koji imamo u memoriji. To se jednostavno 
//moze uciniti tako da razredu lista dodamo staticki clan.
//U konstruktoru razreda potrebno je povecati clan za jedan.
//Staticki clan se i prilikom koristenja predlozaka moze definirati 
//na isti nacin kao i kod obicnih razreda. Provo nam opet treba
//razred ElementListe iz pr9

#include <iostream>
using namespace std;

//RAZRED ELEMENTLISTE
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

template <class Tip>
inline ElementListe<Tip>::ElementListe(const Tip &elem){
	vrij=elem;
	prethodni=NULL;
	sljedeci=NULL;
}

template <class Tip>
inline Tip &ElementListe<Tip>::DajVrijednost(){
	return vrij;
}

//f-ja za ispis 
template <class Tip>
void Ispisi(ElementListe<Tip> &Elem){//tu je Tip stvarni parametar
	ElementListe<Tip> *pok=&Elem;
	cout<<"Vrijednost elementa je: "<<pok->DajVrijednost()<<endl;
	cout<<"Vrijednost pokazivaca prethodni je: "<<pok->Prethodni()<<endl;
	cout<<"Vrijednost pokazivaca sljedeci je: "<<pok->Sljedeci()<<endl;
}

//radimo specjalizaciju razreda ElementListe za tip char *
class ElementListe<char *> {
private:
	char *vrij;
	ElementListe *sljedeci, *prethodni;
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
	ElementListe(char *elem);
	~ElementListe();
	char *DajVrijednost(){
		return vrij;
	}
    void Kopiraj(char *buff);
};

ElementListe<char *>::~ElementListe(){
	delete[] vrij;
}

//Sljedeci funcijski clan kopira funkcijski niz u memorijski 
//prostor, te je svojstven samo implementaciji za znakovne nizove

void ElementListe<char *>::Kopiraj(char *buff){
	 strcpy(vrij,buff);
}

ElementListe<char *>::ElementListe(char *elem){
	vrij=new char[strlen(elem)+1];
	sljedeci=NULL;
	prethodni=NULL;
	strcpy(vrij,elem);
}

//RAZRED LISTA
template <class T>
class Lista{
private:
	ElementListe<T> *glava, *rep;
public:
	static int brojLista;

	Lista();
	~Lista();
	void Dodaj(T *elt);
	void Brisi(T *elt);
	ElementListe<T> *Pocetak(){
		return glava;
	}
	ElementListe<T> *Kraj(){
		return rep;
	}
};

//konstruktor
template <class T>
Lista<T>::Lista(){
	glava=NULL;
    rep=NULL;
	brojLista++;
}
//destruktor
template <class T>
Lista<T>::~Lista(){
	brojLista--;
}
//Staticki clanovi se u zaglavlju razreda samo deklariraju, no
//inicijalizirat se moraju izvan razreda, i to na sljedeci nacin
template <class T>
int Lista<T>::brojLista=0;
//Znacenje prethodnog:"Za svaki razred napravljen po predlosku
//stvori cjelobrojni staticki clan brojLista i inicijaliziraj ga 
//na nulu. Moguce je takodjer definirati specijalizirane 
//inicijalizacije statickih clanova. Npr:

int Lista<float>::brojLista=5;
//To znaci da pocinjemo brojati liste realnih brojeva od broja 5.

int main(){
	Lista<int> lista1, lista2;
	Lista<char *> lista3;
	//prilikom pristupa statickim clanovima razreda definiranog 
	//predloskom potrebno je navest puno ime predloska. Naime
	//svaka varijanta razreda lista imat ce svoj brojac koji
	//koji ce brojati samo objekte tog tipa pa je prilikom 
	//pristupa potrebno naznaciti kojem se brojacu pristupa:
	cout<<"Broj cjelobrojnih lista: "<<
		Lista<int>::brojLista<<endl;
	cout<<"Broj lista znakovnih nizova: "<<
		Lista<char *>::brojLista<<endl;
	return 0;
}
