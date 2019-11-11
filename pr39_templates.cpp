//Posebnu paznju potrebno je obratiti na instanciju predlozaka
//koji imaju IZRAZR KAO PARAMETRE. Promotrimo to na primjeru
//razreda OgranicenaLista koji moze sadrzavati samo neki odredjeni
//maksimalni broj clanova. Takva lista moze biti deklarirana 
//predloskom sto cemo i vidjeti 

#include <iostream>
using namespace std;

template <class Tip,int maxElem>
class OgranicenaLista{
private:
	Tip lista[maxElem];
	int elem_u_listi;
public:
	OgranicenaLista(){
		elem_u_listi=0;
	}
};


//Isti ucinak moze se postici tako da se broj elementa proslijedi
//konstruktoru-deklaracija bi onda izgledala ovako

template <class Tip>
class OgrLista{
private:
	Tip *Lista;
	int elem_u_listi;
	int maxElem;
public:
	OgrLista(int maxel){
		lista=new Tip[maxel];
		maxElem=maxel;
		elem_u_listi=0;
	}
    ~OgrLista(){
		delete list;
	}
};

int main(){
	//Predlosci instanciraju tako da se identifikatori parametara
	//zamijene stvarnim parametrina po PRETRAZI-i-ZAMIJENI
	//principu te svaki te svaki put dobivamo zasebni razred.
	//To znaci da ce sljedece instancije definirati dva 
	//odvojena razreda
	OgranicenaLista<int, 5> ogrLi5;
	OgranicenaLista<int, 6> ogrLi6;
    return 0; 
}
    


