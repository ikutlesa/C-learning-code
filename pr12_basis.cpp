//primjer rada sa funkcijama: funkcija ispisuje tablicu kvadrata

#include <iostream>
#include <iomanip>
using namespace std;

double kvadrat(float);   //deklaracija funkcije kvadrat
float apsolutno(float x)
	{
	return (x>0) ? x : -x;
	}
int main()
{	
	for(int i=1;i<=10;i++)
		cout<< setw(5) <<i<<setw(10)<<kvadrat(i)<<endl;
		
	float y;
	cout<<endl<<"Unsi broj ciju apsolutnu vrijednost zelis:";
    cin >>y;
	cout<<endl<<"aps("<<y<<")="<<apsolutno(y)<<endl;
	
	//moguæe je i sljedeæe
	float x=4;
	float xNaPetu=kvadrat(x) * kvadrat(x) * x;
	cout<<x<<"^5="<<xNaPetu<<endl;
    float a=3,b=2;
	cout<<kvadrat(3)+kvadrat(4)<<endl;
	return 0;
}

double kvadrat(float x)   //definicija funkcije izvan main-a
{ 
	return x*x;
}