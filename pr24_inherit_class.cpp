//program kreira listu objekta razreda LVektor koji je 
//nasljedjen iz razreda atom i Vektor

#include <iostream>
using namespace std;

//deklariramo razred Atom koji ce opisivati objekt u listi 
//Taj razred ce sadrzavati :
//(1) u privatnom djelu pokazivac na prethodni i pokazivac 
//na sljedeci clan u listi
//(2) funkcijske clanove za postavljanje i citanje pokazivaca

class Atom{
private:
	Atom *pokSljedeci;
	Atom *pokPrethodni;
public:
	Atom *Sljedeci(){
		return pokSljedeci;
	}
	Atom *Prethodni(){
		return pokPrethodni;
	}
	void StaviSljedeci(Atom *pok){
		pokSljedeci=pok;
	}
	void StaviPrethodni(Atom *pok){
		pokPrethodni=pok;
	}
};

//Sad imamo listu takvih objekata. Lista ce biti razred koji
//ce sadrzavati funkcijske clanove za umetanje i brisanje clanova
//Alokaciju memorije mora uciniti vanjski program pomocu operatora new
//Funkcijskim clanovima razreda lista se tada samo proslijedjuje 
//pokazivac na taj clan

class Lista{
private:
	//podatkovni clanovi
	Atom *glava;
	Atom *rep;
public:
	//konstruktor
	Lista(){
		glava=NULL;
		rep=NULL;
	}
	Atom *AmoGlavu(){
		return glava;
	}
	Atom *AmoRep(){
		return rep;
	}
	void UgurajClan(Atom *pok,Atom *izaKojeg=NULL);
	void GoniClan(Atom *pok);
};

void Lista::UgurajClan(Atom *pok,Atom *izaKojeg){
	//dali se dodaje na pocetak?
	if (izaKojeg!=NULL){
		//ne dodaje se na pocetak
		//dali se dodaje na kraj?
		if(izaKojeg->Sljedeci()!=NULL)
			//ne dodaje se na kraj
			izaKojeg->Sljedeci()->StaviPrethodni(pok);
	    else
			//dodaje se na kraj
			rep=pok;
		pok->StaviSljedeci(izaKojeg->Sljedeci());
		izaKojeg->StaviSljedeci(pok);
	}
	else{
		//dodaje se na pocetak
		pok->StaviSljedeci(glava);
		if (glava!=NULL)
			//dali vec ima clanova u listi
			glava->StaviPrethodni(pok);
		glava=pok;
	}
	pok->StaviPrethodni(izaKojeg);
}

void Lista::GoniClan(Atom *pok){
	if(pok->Sljedeci()!=NULL)
		pok->Sljedeci()->StaviPrethodni(pok->Prethodni());
	else
		rep=pok->Prethodni();
	if(pok->Prethodni()!=NULL)
		pok->Prethodni()->StaviSljedeci(pok->Sljedeci());
	else
		glava=pok->Sljedeci();
}

//definiramo novi razred LVektor koji ce sadrzavati podobjekt Atom
//koji sadrzi sve sto je neophodno da bi se objekt mogao 
//pohraniti u listu,opcenito razredi cije objekte zelimo smjestit 
//u listu moraju nasljediti razred Atom. Razred LVektor ce definirati 
//ojekt vektor koji se upravo zbog toga moze smjestit u listu

class LVektor:public Atom{
private:
	float ax;
	float ay;
public:
	LVektor(float a,float b){
		ax=a;
		ay=b;
	}
	
	float DajX(){
		return ax;
	}
	float DajY(){
		return ay;
	}
};

int main(){
	Lista list1;
	//punjenje liste
	list1.UgurajClan(new LVektor(10.0,20.0));
    list1.UgurajClan(new LVektor(-5.0,-6.0));
	//citanje liste
	LVektor *pok=static_cast<LVektor *>(list1.AmoGlavu());
	while (pok){
		//obrada vektora, na primjer ispis:
		cout<<"("<<pok->DajX()<<","<<pok->DajY()<<")"<<endl;
		pok=static_cast<LVektor *>(pok->Sljedeci());
	}
	return 0;
}



