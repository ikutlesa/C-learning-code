//Ilustracija dinamièkog alociranja memorije sa operatorom new

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  float nekiBroj;   //osiguranje mem. prostora na koji ce pokazivati
  float *pokazivacNaTajBroj = &nekiBroj;
  *pokazivacNaTajBroj=34.234;
  cout<< nekiBroj <<endl;
  
  //moguce je istodobno s deklaracijom pokazivaca za objekt cija ce 
  //vrijednost biti tamo upravo operatorom new-dinamicko alocir. memorije

  float *pokazivac = new float(); //rezervir. potrebnog mem. prostora za
  *pokazivac=10.5;				 //objekt tipa float
  cout<<*pokazivac<<endl;
  delete pokazivac; //potrbno je osloboditi mem.p. na heapu zauzet s new 
  
  //stvaranje objekta èija se vrijednost, nakon što je jednom inicijali
  //zirana tijekom izvodjenja progarama ne smije vise promijeniti

 // const double *elektron=new const double(1.602192e-19);
 // cout<<"elektron="<<elektron<<endl;
 // delete elektron;
  
  //moguce je i alocirati prostor za polje objekata

  int *sati=new int[12]; //new vraca pokazivac na pocetak polja
  *sati=12;
  cout<<*sati<<endl;
  delete [] sati;
  return 0;

}
  
