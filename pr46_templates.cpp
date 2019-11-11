//REALIZACIJA RAZREDA LISTA PREDLOSKOM (10.5 str 449)
//Program je kompletna realizacija razreda Lista pomocu predlozaka
//Temelji se na prijasnjim programcicima(primjerima).
//Implementacija je slicna onoj iz primjera o nasljedjivanju,
//s neznatnim razlikama. Razlike su:
//(1) clanovi liste se ne identificiraju preko pokazivaca,
//    nego preko cijelog broja- prvi clan (onaj kojeg pokazuje 
//    glava) ima indeks 0.
//(2) Takodjer za izravan pristup pojedinom clanu liste dodan
//    je preoptereceni operator [].
//(3) Funkcijski clan KolikoSiDuga() pak vraca broj elementata
//    u listi-on nam svakako moze dobro doci kod ispisa svi elemenata
//    u for petlji kada indeks za dohvacanje pojedinih elemenata 
//    povecamo od nula do duljine liste.

#include <iostream>
#include <cstring>
using namespace std;
 
//definicija predloska razreda Lista
template <class Tip>
class Lista{
private:

	//definicija ugnjezdjenog razreda ElementListe
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
	     void StaviPrethodni(ElementListe *pret){
		       prethodni=pret;
		 }
	     void StaviSljedeci(ElementListe *sljed){
		       sljedeci=sljed;
		  }
	//konstruktor razreda ElemntListe
	      ElementListe(const Tip &elem){
	  	       prethodni=NULL;
		       sljedeci=NULL;
		       vrij=elem;
		  }
		  Tip &DajVrijednost(){
			  return vrij;
		  }
	};

    ElementListe *glava, *rep;
    int duljina;
public:
	Lista(){
		glava=NULL;
		rep=NULL;
		duljina=0;
	}
	ElementListe *AmoGlavu(){
		return glava;
	}
	ElementListe *AmoRep(){
		return rep;
	}
	void UgurajClan(Tip pok, int redBr=0);
	void GoniClan(int koga);
	Tip &operator[](int ind);
	int KolikoSiDuga(){
		return duljina;
	   
	}
};

//definicija funkcije UgurajClan
template <class Tip>
void Lista<Tip>::UgurajClan(Tip pok, int redBr){
	if(redBr > duljina)    //ako je indeks veci od dozvoljenog
		redBr=duljina;     //dodaj na kraj
	ElementListe *elt=new ElementListe(pok);
	ElementListe *izaKojeg=NULL;
	if (redBr){//moramo se pozicionirati na mejesto na koje  
		izaKojeg=glava; //ubacujemo novi el.(redBr)
		redBr--;
		while(redBr){
			izaKojeg=izaKojeg->Sljedeci();
			redBr--;
		}
	}
	//da li se dodaje na pocetak
    if(izaKojeg!=NULL){
	//ne dodaje se na pocetak.
	//dali se dodaje na kraj?
		if (izaKojeg->Sljedeci() != NULL)
			//ne dodaje se na krak
			izaKojeg->Sljedeci()->StaviPrethodni(elt);
		else
			//dodaje se na kraj;
		     rep=elt;
		elt->StaviSljedeci(izaKojeg->Sljedeci());
		izaKojeg->StaviSljedeci(elt);
	}
	else{
		//dodaje se na pocetak
		elt->StaviSljedeci(glava);
		if (glava !=NULL)
			//dali vec ima clanova u listi?
			glava->StaviPrethodni(elt);
		glava=elt;
	}
	elt->StaviPrethodni(izaKojeg);
	duljina++;
}

//definicija funkcije GoniClan
template <class Tip>
void Lista<Tip>::GoniClan(int koga){
	if(koga > duljina)      //ako je indeks veci 
	   return;			   //od dozvoljenog 
    ElementListe *pok=glava;
	while(koga){ //pozicioniramo se na el. kojeg trebamo izbaciti
		pok=pok->Sljedeci();
		koga--;
	}
	if(pok->Sljedeci() != NULL)
		pok->Sljedeci()->StaviPrethodni(pok->Prethodni());
	else
		rep=pok->Prethodni();
	if (pok->Prethodni() != NULL)
		//ne izbacujemo prvi element liste
		pok->Prethodni()->StaviSljedeci(pok->Sljedeci());
	else
		//izbacujemo prvi element liste
		glava=pok->Sljedeci();
	delete pok;
	duljina--;
}

template <class Tip>
Tip &Lista<Tip>::operator[](int ind){
	ElementListe *pok=glava;
	while(ind){
		pok=pok->Sljedeci();
		ind--;
	}
	return pok->DajVrijednost();
}
template <class Tip>
void Ispis(Lista<Tip> &list){
	cout<<endl;
	for(int i=0;i<list.KolikoSiDuga();i++)
		cout<<list[i]<<endl;
}

int main(){
	Lista<int> l1;
	l1.UgurajClan(1,0);
	Ispis(l1);
	l1.UgurajClan(3);
	Ispis(l1);
	l1.UgurajClan(7,0);
	Ispis(l1);
	l1.GoniClan(0);
	Ispis(l1);
	Lista<float> l2;
	int n,br;
	float el;
	cout<<"Koliko elemenata realne liste zelite unjeti:";
    cin>>n;
	for(int i=0;i<n;i++){
		cout<<"Unesi "<<i+1<<". element liste:";
		cin>>el;
		cout<<"Na koje mjesto u listi zelite unjeti element:";
		cin>>br;
		l2.UgurajClan(el,br);
	}
	cout<<endl<<"Uneseni elementi su:";
	Ispis(l2);
	return 0;
}




