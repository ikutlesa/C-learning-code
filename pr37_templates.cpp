//Ovo je primjer predloska funkcije za bubble sort.
//Funkciji bubble_sort(), kao parametri se proslijedjujemo
//niz i duljinu tog niza. Unutar funkcije bubble_sort() 
//poziva se i funkcija zamjeni() koja provodi zamjenu dva 
//elementa tog niza.

#include <iostream>
using namespace std;

template <class Elem>
void zamijeni(Elem& a,Elem& b){
	Elem priv=a;
	a=b;
	b=priv;
}

template <class Elem>
void bubble_sort(Elem *niz,int brElem){
	for(int i=brElem-1;i>0;i--){
		bool zamjena=false;
		for(int j=0;j<i;j++)
			if(niz[j+1]<niz[j]){
				zamijeni(niz[j],niz[j+1]);
				zamjena =true;
			}
		if (zamjena == false)
				break;
	}
}

//nakon razvrstavanja rezultat ispisujemo funkcijom pisi_niz/()
//koju cemo takodjer realizirati predloskom.
template <class Elem>
void pisi_niz(Elem *niz,int brElem){
	cout<<"{";
	for(int i=0;i<brElem;i++){
		cout<<niz[i];
		//zarez s ne stampa nakon zadnjeg elementa:
		if(i < brElem-1) cout<<",";
	}
	cout<<"}"<<endl;
}

int main(){
	int niz1[]={4,5,2,7,1,0,9};
	double niz2[]={2.6, 7.9, 1.4, 8.9, 9.9, 3.3};
	bubble_sort(niz1,7);
	cout<<"Niz cijelih brojeva:"<<endl;
	pisi_niz(niz1,7);
	bubble_sort<double>(niz2,6);
	cout<<endl<<"Niz realnih brojeva:"<<endl;
	pisi_niz<double>(niz2,6);
	return 0;
}
