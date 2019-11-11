//Parametre predloska moguce je eksplicitno navesti unutar 
// para zbakova <i>. Unutar tih znakova moguce je navesti 
//eventualne konstantne prametre koje predlozak moze imati.
// To svojstvo se najvise koristi prilikom specificiranja 
//parametra koji odredjuju povratni tip ili se uopce ne 
//spominju u deklaraciji.

//Npr: 
//template <class lokalniPodaci>
//int Usporedi(char *niz1,char *niz2);

//Predstojeci program, uz koristenje predlozka generira
//funkciju za racunanje prosjeka elemenata nekog niza   

#include <iostream>
using namespace std;

template <class Preciznost,class Tip>
Preciznost Prosjek(Tip *polje,int brElem){
	Tip suma=0;
	Preciznost prosj;
	for(int i=0;i<brElem;i++)
		suma=suma+polje[i];
    prosj=suma/brElem;
	return prosj;
}

int main(){
	const int n=5;
	float polje[n];
	for(int i=0;i<n;i++){
		cout<<"Unesi "<<i+1<<". element polja:";
		cin>>polje[i];
	}
	//Sljedeci poziv predloska je moguc, uz eksplicitno
	//navodjenje vrijednosti oba dva parametra
	double pros1=Prosjek<double,float>(polje,n);
	cout<<"Prosjek je "<<pros1<<endl;
	
	//Predlozak se moze pozvati tako da se eksplicitno 
	//navede samo vrijednost parametra Preciznost, dok ce
	//se vrijednost parametra Tip zakljuciti iz poziva

	double pros2=Prosjek<double>(polje,n);
	cout<<"Prosjek je "<<pros2<<endl;
	
	//No nije moguce,npr., izostaviti prvi parametar i
	//ocekuvati da ce on biti zakljucen iz poziva, a 
	//drugi specificirati eksplicitno. Npr ako imamo:
	//duble pros=Prosjek<float>(polje,n);
	
	return 0;
}
