//ilustriranje prenosenja vrijednostipodataka po vrijednosti i adresi
//èinjenica:formalni argument zivi samo unutar funkcije,te je njegova 
//vrijednost izlaskom iz funkcije izgubljena, ne mjenja vrij. u main-u

#include <iostream>
#include <iomanip>
using namespace std;

int DodajSto(int i)
	{
	  i+=100;
	  return i;
	}

void zamijeni(int prvi,int drugi ) //pogresno
	{
	  int segrt;   //pomocna varijabla

	  segrt=prvi;
	  prvi=drugi;
	  drugi=segrt;
	}

//zamijena vrijednosti preko pokazivaca 
void zamijeniPok(int *prvi, int*drugi)
	{
	  int segrt=*prvi;
	  *prvi=*drugi;
	  *drugi=segrt;
	}

//zamijena vrijednosti preko reference
void zamijeniRef(int &prvi,int &drugi)
	{
	 int segrt=prvi;
	 prvi=drugi;
	 drugi=segrt;
	}

int main()
	{
	 int n=1;
	 DodajSto(n);
	 cout<< "Radio "<<n<<endl;   //ispisuje 1 zobog prijenosa po vrijed
	 n=DodajSto(n);
	 cout<<"Radio "<< n << endl; //sad ispisuje 101;
	 int a=2, b=3;
	 cout<<"Prije zamjene a="<<a<<" b="<<b<<endl;
	 zamijeni(a,b);
	 cout<<"Nakon zamjene a="<<a<<" b="<<b<<endl<<"Ocito isto"<<endl;
	 zamijeniPok(&a,&b);
	 cout<<"Nakon zamjene preko  pokazivaca:"<<"a="<<a<<" b="<<b<<endl;
	 zamijeniRef(a,b); //nije potrebno komplicirati op. &
	 cout<<"Nakon zamijene preko reference:"<<"a="<<a<<" b="<<b<<endl;
	 return 0;
}
