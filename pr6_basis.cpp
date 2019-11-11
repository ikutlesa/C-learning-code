//Ilustracija aritmetièkih operacija s pokazivaèima

#include <iostream>
#include  <iomanip>
using namespace std;

int main()
{
  int a;
  int *poka=&a;
  cout << poka <<endl;
  cout << poka-3 <<endl; //rezultat je pok. na mem. lokaciju koja je za 
						 //3*sizeof(int) manja od poèetne
  
  float x[10]={1,2,5,6,7,9,12,31,23,14};
  float *px=&x[3];
  float x2= *(px-1);      //x[2] - prethodni èlan polja
  float x5= *(px+1);     // x[4] - sljedeæi èlan polja
  cout <<"x1 = "<< x2 <<endl;
  cout <<"x2 = "<< x5 <<endl;
  float *prviClanUNizu = x;
  float *zadnjiClanUNizu = &x[9];
  int razmak=zadnjiClanUNizu - prviClanUNizu; // = 9 
  cout<<"razmak="<<razmak<<endl;
  razmak=prviClanUNizu - zadnjiClanUNizu;     // =-9     
  cout<<razmak<<endl;
  if (prviClanUNizu >= zadnjiClanUNizu)
	  cout <<"Frka!"<<endl;
  return 0;
}