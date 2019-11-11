//program ilustrira pristup nasljedjenim clanovima
//Èlan i u izvedenom razredu skriva istoimeni clan u 
//osnovnom razredu.
//èlanu osnovnog razreda moze se pristupiti navo-
//deci podrucje kojem clan pripada pomocu opera-
//tora za odredjivanje podrucja

#include <iostream>
using namespace std;

class Osnovna {
public:
	int i;
	void Var(){ 
		cout<<"Osnovna::"<<i<<endl;
		}
};

class Izvedena : public Osnovna{
public:
	int i;
	void Int(){          //prekriva Osnovna::i!!!
		cout<<"Izvedena::"<<i<<endl;
	}
};

int main(){
	Izvedena izv;
	izv.i=9;	      //pristupa se Izveedena::i
	izv.Osnovna::i=20;//pristupa se Osnovna::i
	izv.Var();        //ispisuje 'Osnovna::i 20'
    izv.Int();        //ispisuje 'Izvedena::i 9'
	return 0;
}