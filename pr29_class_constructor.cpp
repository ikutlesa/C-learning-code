//Program je nadogradnja na pr21, uz koristenje konstruktora=funkcijski
//clan koji se automatski poziva prilikom stvaranja objekta u svrhu 
//njegove inicijalizacije, imena je kao i razred te nema povratni tip

#include <iostream>
using namespace std;

class Vektor
{
//dodajemo funkciju operator+ za zbrajanje dva objekta tipa vektor
//u ovom sluèaju koristenjem friend
friend Vektor operator +(Vektor &a, Vektor &b);
private:
	float ax,ay;
public:
	//deklarirana su dva konstruktora
	Vektor(float x=0,float y=0){  //inicijalizira novostvoreni vektor na nul-vektor
	     ax=x;
		 ay=y;
	}
		   
	void PostaviXY(float x,float y)	{
		 ax=x;
		 ay=y;
		}
	
	float DajX() const{
		 return ax;
		}
	
	float DajY() const{
		  return ay;
		 }
	void MnoziSkalarom(float skalar);
};

inline void Vektor::MnoziSkalarom(float skalar){
	ax*=skalar;
	ay*=skalar;
}

Vektor operator+(Vektor &a,Vektor &b){
	return Vektor(a.ax+b.ax,a.ay+b.ay);
}


int main()
	{
	  Vektor mojInicijaliziraniVektor(3.0,-7.0);
	  cout<<"Projekcija inicijaliziranog vektora na x os je:"
		  <<mojInicijaliziraniVektor.DajX()<<endl; 
	  Vektor bezParametara;
	  cout<<"Projekcija nul vektora na y os je:"
		  <<bezParametara.DajY()<<endl;
	  //operator + se moze koristiti na sljedeci nacin
	  Vektor a(12.0,3.0), b(-3.0,-6.0), c;
	  c=a+b;  //poziva se operator za zbarajanje
	  cout<< c.DajX()<<" "<<c.DajY()<<endl;
	  return 0;
}
