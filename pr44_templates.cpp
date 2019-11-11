//UGNJEZDJENI PREDLOSCI (10.3.8 str 441)
//C++ podrzava ugnjezdjivanje predloska: moguce je definirati
//predlozak nekog razreda unutar razreda ili unutar predloska
//razreda: Npr:

#include <iostream>
using namespace std;

template <class T1>
class X{
public:
	template <class T2>
		class Y{
		void Funkcija(){
			cout<<Funkcija();
		}
		   T1 *pok;
	};
};

//Funkcijski clan Funkcija() je sada parametriziran s dva tipa:
//T1 i T2. Njegova definicija izvan razreda izgleda ovako:
template <T1> template <T2>
void X<T1>::Y<T2>::Funkcija(){
//   Npr
	cout<<"Funkcija()";
}
//Unutar definicuje razreda Y dozvoljeno je koristiti tip T1
//(to je i ucinjeno za clan pok).Stoga ce razred Y definitivno
//osim samo o T2, ovisiti i o T1. Zato je Y parametriziran s T1
int main(){
	
	
	return 0;
}


