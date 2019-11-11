//Program ilustrira rad sa privatnim osnovnim razredom, izvodjenjem
//klase  Kompleksni iz klase Vektor. Privatni clanovi osnovnog razr
//nisu dostupni izvedenom razredu, dok javni i zasticeni clanovi osnovnog
//razreda postaju privatni clanovi izvedenog razreda

#include <iostream>
using namespace std;

class Vektor{
private:
	float ax,ay;
public:
	Vektor(float a=0,float b=0) : ax(a), ay(b){}
	void PostaviXY(float x,float y){
		ax=x;
		ay=y;
		}
	float DajX(){
		return ax;
		}
	float DajY(){
		return ay;
		}
    float MnoziSkalarnoSa(Vektor &vekt){
		float rez;
		rez=ax*vekt.ax+ay*vekt.ay;
		return rez;
		}
	};

class Kompleksni:private Vektor{ //da smo satvili tu public u gl.
//programu bi bilo dozvoljeno napraviti nesto tipa:
//Kompleksni z1,z2;
//z1.MnoziSkalarnoSa(z2); sto kao operacija nema smisla za kompl. brojeve

public:
	Kompleksni(float a=0,float b=0):Vektor(a,b) {}
	float Realni(){
		return DajX();
		}
	float Imaginarni(){
		return DajY();
		}
	void printk(){
         cout<<Realni()<<"+"<<Imaginarni()<<"i"<<endl;
		}
	void MnoziSa(Kompleksni &broj){
	     float rez_re,rez_im;
		 rez_re=Realni()*broj.Realni()-Imaginarni()*broj.Imaginarni();
		 rez_im=Realni()*broj.Imaginarni()+Imaginarni()*broj.Realni();
		 Kompleksni rez(rez_re,rez_im);		
	     rez.printk(); 
	}
    
};

int main(){
	float a1,b1;
	cout<<"Unesi realni dio imaginarnog broja:"<<endl;
	cin>>a1;
	cout<<"Unesi imaginarni dio kompleksnog broja:"<<endl;
	cin>>b1;
	Kompleksni z1(a1,b1);
	z1.printk();
	float a2,b2;
	cout<<"Unesi realni dio kompl. br. s kojim zelis mnoziti:"<<endl;
    cin>>a2;
	cout<<"Unesi imaginarni dio kompl. br. s kojim zelis mnoziti:"<<endl;
	cin>>b2;
	Kompleksni z2(a2,b2);
	cout<<"Rezultat je:";
	z1.MnoziSa(z2);
	cout<<endl;
	//vaznost s pokazivacima
	Kompleksni *pokKompl=new Kompleksni(4.0,6.0);
	//Vektor *pokVekt=pokKompl; //ne smije biti dozvoljeno!
    
	//pokVekt zapravo pokazuje na kompleksan broj
	//koji se moze mnoziti skalarno s vektorom
	//pokVekt->MnoziSkalarnoSa(Vektor(7.0,8.0)); //besmislica
	//dakle ako je neki razred privatno izvedene iz nekog baznog 
	//pokazivac na neki objekt baznog razreda nemozemo preusmjeriti na 
	//na objekt izvedebog razreda
	//no gornju pretvorbu moguce je provesti navodjenjem eksplicitne pretvorbe
	//pokVekt=static_cast<Vektor *>(pokKompl);
	cout<<pokKompl->Realni()<<endl;;
	return 0;
}