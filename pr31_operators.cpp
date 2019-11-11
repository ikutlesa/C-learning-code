//redefiniranje operatora pridruzivanja kod Zznakovnog niza
#include <iostream>
#include <string>
using namespace std;

class ZnakovniNiz{
	char *pokNiz;
public:
	ZnakovniNiz(char *niz="");
	//operator pridruzivanja
		ZnakovniNiz& operator=(const ZnakovniNiz &desno);
	void print(){
			cout<<pokNiz<<endl;
		}
	~ZnakovniNiz(){
		cout<<"Unisten niz:"<<pokNiz<<endl;
		delete[]pokNiz;
	}
};

ZnakovniNiz::ZnakovniNiz(char *niz){
	pokNiz=new char[strlen(niz)+1];
	strcpy(pokNiz,niz);
    cout<<"Stvoren niz:"<<niz<<endl;
}
ZnakovniNiz& ZnakovniNiz::operator=(const ZnakovniNiz &desno){
    if(&desno != this){
		delete[] pokNiz;
		pokNiz=new char[strlen(desno.pokNiz)+1];
		strcpy(pokNiz,desno.pokNiz);
	}
	return *this;
}

int main(){
	ZnakovniNiz a="Niz a";
    a.print();
	ZnakovniNiz b;
	b.print();
	b=a;
	b.print();
	b=a="Copycat"; //zbog toga povratni tip operatora je referenca na objekt
	b.print();
	return 0; 
}