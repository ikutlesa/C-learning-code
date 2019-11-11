//PREDLOZAK RAZREDA complex (10.6.1. str 452)
//Standardna C++ biblioteka sadrzi predlozak razreda complex 
//koji omogucava jednostavno rukovanje i operacije s kompleksnim 
//brojevima. Predlozak razreda complex definiran je u istoimenom
//zaglavlju. Uz to definirane su i tri specjalizacije razreda
//za podatke  tipa float, double i long double; time je i
//ostvarena optimizacija koda za tri najcesce koristena tipa brojeva
//te sigurnije pretvorbe iz jednog tipa kompleksnih brojeva u 
//u drugi. Osim standardnih funkcijskih clanova kao sto su 
//pridruzivanje, preslikavanje i pretvorba, razred definira i
// sve aritmeticke operacije i transcedentne funkcije za 
//objekt tipa complex.

//Nas program ucitava dva kompleksna broja u pravokutnim
//koordinatama, ispisuje ih u polarnim koordinatama te ispisuje
//njihov zbroj, umnozak i rezultat koji se dobije kada se prvi
//potencira drugim.

#include <iostream>
#include <complex>
using namespace std;

int main(){
	//inicijaliziramo dva kompleksna broja
	complex<double> z1(3.0,4.0);
	complex<float> z2(1.0,2.0);

	//ispisimo ih:
	cout<<"z1: "<<z1<<endl;
	cout<<"z2: "<<z2<<endl;

	//Ispisimo ih u polarnim koordinatama:
	cout<<"z1: modul: "<<abs(z1)<<endl
	    <<"    faza: "<<arg(z1)<<endl;
    cout<<"z2: modul: "<<abs(z2)<<endl
		<<"    faza: "<<arg(z2)<<endl;

	//buduci da su operator+ i operator* te funkcija pow()
	//definirani samo za argumente istog tipa,
	//moramo stvoriti privremene objekte
	cout<<"zbroj z1 + z2: "
		<<z1 + complex<double>(z2.real(), z2.imag())
		<<endl;
	cout<<"umnozak z1 * z2: "
		<<z1 * complex<double>(z2.real(), z2.imag())
		<<endl;
	//Realni i imaginarni clanovi mogu se dohvacati pomocu 
	//globalnih funkcija imena kao i  real() i imag()
   complex<int> zint(30, 40);
   cout<<"zint= "<<real(zint)<<" + "
	   <<imag(zint)<<"i"<<endl;
   //Ako se konstruktoru ne navedeu pocetne vrijednosti,tada
   //ce on inicijalizirati realni i imaginarni dio na podrazumjevane
   //vrijednosti zadani tip. Ako se navede samo jedan argument
   //konstruktoru, njime ce inicijalizirati relni dio kompleksnog 
   complex<float> z3;            //z3=0 + 0i 
   cout<<z3<<endl; 
   complex<double> z4(5.);   //z4=5 + 0i
   cout<<z4<<endl;
   //Konstruktoru se mogu proslijediti i pocetne vrijednosti
   //u polarnim koordinatama kao npr.
   complex<float> z5(polar(5.0, 0.9273)); //z5=3 + 4i
   cout<<z5<<endl;
   
   return 0;
}

