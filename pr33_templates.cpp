//demonstracija upotrebe predlozaka kroz realizaciju funkcije koja
//odredjuje minimalni clan nekog niza. Funkcija ce biti realizirana 
//pomocu predloska parametriziranim tipom elementata koji cine niz.
//!!!Funkciji se preko parametra proslijedjuje pokazivac na pocetak 
//niza i duljina niza, a ona VRACA REFERENCU na objekt koji pronadjen 
//kao minimalni

#include <iostream>
using namespace std;

//Realizacija funkcije manji_u_nizu
template <class Elem> //deklaracija predloska, dozvoljeno je da se
                      //parametar korist samo kao povratni tip ili
					  //da se nigdje ne kroisti
Elem &manji_u_nizu(Elem *niz,int brElem){
	Elem *pokNajmanji;   //lokalna varijabla
	pokNajmanji=niz;
	for(int i=0;i<brElem;i++)
		if(niz[i]<*pokNajmanji)
			pokNajmanji=&niz[i];
    return *pokNajmanji;
}

int main(){
	int n1[]={4,3,2,1};
	cout<<manji_u_nizu(n1,4)<<endl;
    double n2[]={3.23,2.1,1.5};
    cout<<manji_u_nizu(n2,3)<<endl;
	char n3[]={'A','B','C'};
	cout<<manji_u_nizu(n3,3)<<endl;
	float polje[]={1.1,4.5,5.6};
	//dozvoljene je i specifikacija predloska manji_u_nizu
	//koja uzima polje float brojeva, i vraca float
	float min=manji_u_nizu<float>(polje,3); 
	cout<<min<<endl;
	return 0;
}
