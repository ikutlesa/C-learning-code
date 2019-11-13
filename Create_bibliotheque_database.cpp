#include <iostream.h>
#include <string.h>
#include <list>
#include<limits.h>
#include<stdlib.h>

using namespace std;
class element{
	char*n;
	int id;
	int status;
	char *i;
	int godizd;
public:
	element(char*,int,int,char*,int);
	~element();
	virtual void ispis();
	void izdati();
	void vratiti();
	inline char* naslov(){return n;}
	inline int ident(){return id;}
};

class cd:public element{
	char *izv;
	int brpj;
	char *vrgl;
public:
	cd(char*,int,int,char*,int,char*,int,char*);
	~cd();
	void ispis();
};
class knjiga:public element{
	char *autor;
	int brizd;
public:
    knjiga(char*,int,int,char*,int,char*,int);
	~knjiga();
	void ispis();
};
class casopis:public element{
	char *tip;
	int broj;
public:
	casopis(char*,int,int,char*,int,char*,int);
	~casopis();
	void ispis();
};

class bibl{
typedef list <element*>  Lelem;
public:
	bibl(){};
	~bibl(){};
	void dodajelem();
	void izbacielem();
	void ispis();
};



casopis::casopis(char *p1,int a1,int a2,char *p2,int a3,char *p3,int a4):element(p1,a1,a2,p2,a3){
	tip=new char[strlen(p3)+1];
	strcpy(tip,p3);
	broj=a4;
}
casopis::~casopis(){
	delete [] tip;
}
void casopis::ispis(){
	cout << "\n\nOvo je casopis sa slijedecim karakteristikama:\n";
	element::ispis();
	cout << "\nTip casopisa je " << tip;
	cout << "\nBroj casopisa je " << broj;
}
knjiga::knjiga(char *p1,int a1,int a2,char *p2,int a3,char *p3,int a4):element(p1,a1,a2,p2,a3){
	autor=new char[strlen(p3)+1];
	strcpy(autor,p3);
	brizd=a4;
}
knjiga::~knjiga(){
	delete [] autor;
}
void knjiga::ispis(){
	cout << "\n\nOvo je knjiga sa slijedecim karakteristikama:\n";
    element::ispis();
	cout << "\nAutor je " << autor;
	cout << "\nOvo je izdanje broj " << brizd;
}

cd::cd(char *p1,int a1,int a2,char *p2,int a3,char *p3,int a4,char *p4):element(p1,a1,a2,p2,a3){
	izv=new char[strlen(p3)+1];
	vrgl=new char[strlen(p4)+1];
	strcpy(izv,p3);
	brpj=a4;
	strcpy(vrgl,p4);
}
cd::~cd(){
	delete [] izv; 
	delete [] vrgl;
}
void cd::ispis(){
	cout << "\n\nOvo je CD sa slijedecim karakteristikama:\n";
	element::ispis();
	cout << "\nIzvodjac je " << izv;
	cout << "\nBroj pjesama na CD-u  je " << brpj;
	cout << "\nVrsta glazbe je " << vrgl << endl;
}
element::element(char *p1,int a1,int a2,char *p2,int a3){
	n=new char[strlen(p1)+1];
	i=new char[strlen(p2)+1];
	strcpy(n,p1);
	id=a1;
	status=a2;
	strcpy(i,p2);
	godizd=a3;
}
element::~element(){
	delete [] n; 
	delete [] i;
}
void element::ispis(){
	cout << "\nNaslov je " << n;
	cout << "\nIdentifikacijski broj je " << id;
	if(status==0) cout << "\nNaslov nije izdat!";
		else cout << "\nNaslov je izdat!";
	cout << "\nIzdavac je " << i;
	cout << "\nGodina izdanja  je " << godizd;
}
void element::izdati(){
	if(status!=0) cout << "\n" << n <<" je  vec izdat!";
	else{
		status=1;
		cout << "\n" << n << " je izdat!";
	}
}
void element::vratiti(){
	if(status==0) cout << "\n" << n << " nije izdat!"; 
		else{
		status=0;
		cout << "\n" << n << " je vracen!";
	}
}
void main(){
	cd a("Ovo je cd",123,1,"Ovo je izdavac",2001,"Pero Kvrgic",12,"Rap");
	knjiga b("Ovo je knjiga",124,0,"Ovo je izdavac",2001,"Pero Kvrgic",2);
	casopis c("Ovo je casopis",125,0,"Ovo je izdavac",2001,"Pero Kvrgic",1);
	a.vratiti();
    Lelem bibl;
	b izdati;
	bibl.insert(bibl.end(), b);
}