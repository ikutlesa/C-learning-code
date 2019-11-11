//VEKTOR (16.4.1. Sstr. 609)
//Spremnici su  objekti namjenjeni pohranjivanju drugih tipova
//objekata. Jedan od spremnika je vektor.
//Vektor je sekvencijalna struktura koja se obicno podrazumjevano
//Ona je ekvivalentna jednodimenzionalnim poljima- omogucava 
//dohvacanje clanova izravno preko njihovog indeksa. Dodavanje 
//i izbacivanje elementa iz vektora iziskuje pomicanje svih 
//clanova ispred ili iza clana koji se dodaje/izbacuje. 
//Za koristenje vektora, u kod programa moramo ukljuciti zaglavlje
//<vector>. Ovaj program ce deklarirati vektor koji ce sadrzavati
//objekte tipa string.

#include <vector>   //spremnik ce biti vector
#include <string>   //u spremniku ce biti string
#include <iostream>
using namespace std;

int main(){
	vector<string> sveMojeLjubavi;
	//vektoru se clanovi pri krajevima brzo dodaju/odbacuju
	
	//Kao sto vidimo, prilikom deklaracije vektora ne treba 
	//navesti njegovu duljinu-vektor ima svojstvo da moze sam
	//sebi  po potrebi povecati duljinu, tijekom izvodjenja 
	//programa tj. pri dodavanju clanova.
	//Napunimo vektor sveMojeLjubavi vrijednostima.
	//Razred vektor sadrzi nekoliko funkcijskih clanova za
	//umetanje novih clanova. Ti clanovi sami alociraju potreban
	//prostor i po potrebi prosiruju sam vektor.
	//Tako clan push_back()  dodaje element na kraj vektora

	sveMojeLjubavi.push_back(string("The Beatles"));
	sveMojeLjubavi.push_back(string("Tangerine Dream"));
    sveMojeLjubavi.push_back(string("U2"));
	
	//ispisimo elemente vektora 
	for(int i=0;i<sveMojeLjubavi.size();i++){
		cout<<sveMojeLjubavi[i]<<endl;
	}
	//clan size() ovdje vraca duljinu(tj. broj clanova) vektora
	//umjesto sveMojeLjubavi[i],moze i SveMojeLjubavi.at(i) 
   
    //Koliko clanova moze stati u trenutnoj alokaciji u vektor
	//mozemo saznati pomcu fukcijskog clana capacity(); broj kojeg
	//vraca je uvijek veci ili jednak broju sto ga vraca size()
    
	cout<<"Sadrzim "<<sveMojeLjubavi.size()
		<<" clanova, ali bi bez problema mogao primiti "
		<<sveMojeLjubavi.capacity()<<" clanova!"<<endl;
	//cout<<"Molim samo ne vise od "
	//	<<sveMojeLjubavi.size_max()<<" ljubavi!"<<endl;
	
	//Prvi i zadnji clan mogu se dohvatiti funkcijskim clanovima 
	//front() i back()
	
	string prvaLjubav=sveMojeLjubavi.front();
	cout<<prvaLjubav<<endl;
	string zadnjaLjubav=sveMojeLjubavi.back();
	cout<<zadnjaLjubav<<endl;
	
	//Funkcijski clan pop_back() radi upravo suprotno od clana
	//push_back()-dohvaca zadnji clan i brise ga iz vektora.
	//ode moja zadnja ljubav
	sveMojeLjubavi.pop_back();
	for(i=0;i<sveMojeLjubavi.size();i++)
		cout<<sveMojeLjubavi[i]<<endl;

	return 0;
}


