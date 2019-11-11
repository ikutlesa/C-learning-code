#include <iostream>
#include <climits>
#include <cfloat>
using namespace std;

int main()
{
	int a,b,c;
	typedef float broj;
	broj pi=3.14159;
	cout << pi << endl;
	cout << "Upisi prvi broj:"; 
	cin  >> a;
	cout << "Upisi drugi broj:";
	cin  >> b;
	c=a+b;
	cout << "Njihov zbroj je:"<< c << endl;
	cout << "Velicina cijelih brojeva: "<< sizeof(a) << endl;
	cout << "Velicina realnih brojeva: " << sizeof(float) <<endl;
	cout << "Najmanji int: "<< INT_MIN <<endl;
	cout << "Najveci int: " << INT_MAX <<endl;
	cout << (5 > 4) << endl;
	cout << ('A'>'a') << endl;
	cout << ~00100101 << endl;
	if (a < 0) cout<<"Broj je negativan!" << endl;
	else
		cout<<"Broj je pozitivan!"<< endl;
	b= (b < 0) ? -b : b;
	cout << b << endl;
	return 0;

}

