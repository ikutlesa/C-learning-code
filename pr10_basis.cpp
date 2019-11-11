#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	char ch='C';
	char *pc;
	pc=&ch;
	cout<<"ch="<<ch<<endl;
	cout<<"*pc="<<pc<<endl;
	cout<<"adresa od ch="<<pc<<endl;
	char *Stroustrup="C++";
	cout <<*Stroustrup<<endl; //ispisuje prvi znak niza
	cout<<Stroustrup<<endl;  //ispisuje cijeli niz

	return 0;
}