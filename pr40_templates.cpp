//Poneki funkcijski clanovi predloska razreda mogu biti neadekvatni
//za neke tipove koji se mogu proslijedititi predloku kao parametar.
//Tada radimo SPECJALIZACU PREDLOSKA RAZREDA. U prethodnom 
//slucaju moguce je definirati specijalizaciju funkcijskog
//clana koja ce precizno definirati nacin na koji doticni
//clan mora biti obradjen. Npr. ako bismo razred ElementListe
//iz pr7. paramterizirali tipom char *. Tamo smo imali konstruktor
//template <class Tip>
//inline ElementListe<Tip>::ElementListe(const Tip &elem){
//	vrij=elem;
//	prethodni=NULL;
//	sljedeci=NULL;
//Ovaj konstruktor nebi djelovao ispravno ako bismo razred
//ElementListe parametrizirali tipom char*. Za tip char * 
//taj konstruktor ce lokalni objekt vrij inicijalizirati 
//pokazivacem na znakovni niz, sto nije ispravno. 
//Dabi rijesili prethodni problem, potrebno je alocirati zasebni
//memorijski prostor za proslijedjeni niz  te kopirati proslijedjeni
//niz u to mijesto. Upravo u takvom slucaju smo prisiljeni 
//napraviti specjalizaciju predloska razreda.
//Specjalizacija pojedinog funkcijskog clana se definira tako 
//da se iza naziva clana umjesto formalnih navedu stvarni tipovi 
//na koje se specjalizacija odnosi. Pa imamo sljedece

//inline ElementListe<char *>::ElementListe(char * const &elem){
	//ulazni parametar je referenca na konstantan pokazivac 
	//na znak
//	vrij=new char[strlen(elem)+1];
//	prethodni=NULL;
//	sljedeci=NULL;
//	strcpy(vrij,elem);
//}
//No zbog dinamicke alokacije potreban je i dodatni funkcijski
//clan -destruktor.Predlozak razreda ne definira destruktor
//jer ce svi podatkovni clanovi biti automatski unisteni. 
//Objekt koji se cuva u listi bit ce  automatski unisten 
//pomocu podrazumjevanog destrukto. No u slucaju znakovnih 
//nizova podrazumjevani destruktor nece osloboditi zauzetu memoriju.
//Zbog toga je potrebno definirati SPECIJALIZACIJU CIJELOG
//RAZREDA.Ona se definira tako da se nakon naziva razreda
//unutar znakova <> navede tip za koji se specjalizacija definira.



#include <iostream>
#include <cstring>
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

int main(){
	ElementListe<int> eli(1);
	Ispisi(eli);
	ElementListe<char *> elc("Lista");
	Ispisi(elc); 
	return 0;
}