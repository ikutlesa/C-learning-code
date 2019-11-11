//program ilustrira rad sa virtualnim funkcijama
#include <iostream>
using namespace std;

class A{
public:
	    void func(){
		cout<<"A::func()"<<endl;
	}
};
	
//Èlanovi sa statickim pozivom osnovnog razreda kao u ovom slucaju
//funkcijski clan func() mogu biti redeklarirani kao virtualni u 
//izvedenom razredu. Odredjivanje dali se clan poziva virtualno ili
//staticki odnosi se na razred iz kojeg se poziva clan. Primjer za 
//takav slucaj je izvedeni razred B iz razreda A  
class B:public A{
public:
	virtual void func(){ //proglasavamo funkcijo func() virtualnom
		cout<<"B::func()"<<endl;
	}
};

class C:public B{
public:
	virtual void func(){ //izostavljanjem klj. rijeci virtual funkcija bi opet bila 
	                    //jer je vec ucinjena virtualnom u razredu B
						//a razred C je izveden iz razreda B	
		cout<<"C::func()"<<endl;
	}
};

int main(){
	C objc;
	A *pokA=&objc;
	B *pokB=&objc;
	pokA->func();    //ispisuje A::func() jer u razredu A f-ja func()
					 //nije deklarirana kao virtualna
	pokB->func();    //ispisuje C::func(),jer je func() u razredu B je redeklariran
					 //kao virtualni clan, pa se poziva preko virt. tablice
	objc.func();     //staticki poziv ne virtualni
	B objb;
	objb.A::func();//Mehanizam virtualnih funkcija moze se zaobici tako
					//da se operatorom za odredjivanje podrucja eksplicit.
					//navede razred iz kojeg se zeli pozvati funkc.clan
	B *pokB1=&objc;
	(*pokB1).func(); //medjutim ovo je opet virt. poziv
	pokB1->B::func();//ovo je staticki poziv
	//Neispravno je pomocu pokazivaca na neki razred pozivati funkc.
	//clan iz izvedenog razreda, sto ce reci da je sljededce neispravno
	//pokB->C::func();  
	return 0;
}

//Prvi poziv rezultira pozivom f-je a::func() zato jer se f-ja
//poziva preko pokazivaca na razred A. U tom razredu je func()
//definiran bez kljucne rijeci virtual pa se on poziva staticki,
//a to rezultira pozivom iz razreda A. U drugom slucaju clan se
//poziva preko pokazivaca na razred B. U tom razredu clan je
//redeklariran kao virtualni, pa se on poziva pomocu virtualne
//tablice. To rezultira pozivom funkcijskog clana samog objekta,
//a ne clana razreda B. Zato se ustvari poziva C::func()

//Takodjer brijwdi pravilo: Kada je neki funkcijski clan deklariran
//kao virtualan on je automatski virtualan i u svim nasljedjenim razredima
//Funkcijski clan koji je jednom deklariran virtualnim, ne moze se u
//izvedenom razredu pretvoriti u clan sa statickim pozivom	