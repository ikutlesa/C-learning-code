//Upotreba operatora za odredjivanje podrucja je obvezna kako 
//bi se jednoznacno odredio clan kojem se pristupa
#include <iostream>
using namespace std;

class A{
public:
	void Opis(){
		cout<<"Ovo je razred A"<<endl;
		}
};

class B{
public:
	void Opis(){
		cout<<"Ovo je razred B"<<endl;
	}
};

//i ovdije je moguce definirati istoimeni funkcijski clan 
class D:public A,public B{
public:
	void Opis(){
		cout<<"Ovo je razred D"<<endl;
	}
};

int main(){
D obj;
//obj.Opis(); je dvosmislen poziv
//Objekt D u biti posjeduje dva funkcijska clana Opis, jedan u A
//dijelu, a drugi u Bdijelu. Prilikom poziva neophodno je eksplicitno
//odredit kojem se clanu pristupa

obj.A::Opis();   //ispisuje 'Ovo je razred A'
obj.B::Opis();   //ispisuje 'Ovo je razred B'
obj.Opis();      //ispisuje 'Ovo je razred D'
return 0;
}
