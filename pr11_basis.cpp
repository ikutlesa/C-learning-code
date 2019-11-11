//rad sa referencama
//referanca=drugo ime za objekt odredjenog tipa

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int i=5;       //varijabla na koju cemo zadati referencu iref
	int &iref=i;  //referenca na varijablu i
    cout<<"i="<<i<<" iref="<<iref<<endl;

	//promjenom reference mijenja se izvorna varijabla
	iref=75;
	cout<<"i="<<i<<" iref="<<iref<<endl;

	//buduci da postoje konstantni objekti pstoje i ref. na nepromj. obj.
	const float korjen2=1.41;
	const float &refkor2=korjen2; //refkor2=referenca na nepr. korijen 2
	cout<<"korjen2="<<korjen2<<" refkor2="<<refkor2<<endl;
    
   //refernca na const objekt moze se vezati i na promijenjivi objekt

   double x=3.14;
   const float &xref=x;
   cout<<"xref="<<xref<<endl;
   return 0;
}