//progam demonstrira mogucnost preopterecenja predloska 
//funkcije kroz realizaciju funkcije Zbroji() koja zabarja
//objekte. Predlozak funkcije inace moze biti preopterecen
// proizvoljan broj put, ali pod uvjetom da se potpisi 
//funkcija razlikuju po tipu i/ili po broju argumenata.

//Pa definirajmo finkciju Zbroji() na razlicite nacine

#include <iostream>
using namespace std;

//zbrajanje dvaju objekata
template <class Tip>
Tip zbroji(Tip a,Tip b){
	return a+b;
}

//zbrajanje triju objekata
template<class Tip>
Tip zbroji(Tip a,Tip b,Tip c){
	return a+b+c;
}

//zbrajanje dvaju nizova
template <class Tip>
void zbroji(Tip *niza,Tip *nizb,Tip *rez,int brElem){
	for(int i=0;i<brElem;i++)
		rez[i]=niza[i]+nizb[i];
	return;
}
//ovdje smo imali razlikovanje po broju argumenata, a tip
//je  bio svugdje isti

int main(){
	int a,b,c;
	cout<<"Unesi tri cijela broja:";
	cin>>a; cin>>b; cin>>c;
	int r1=zbroji<int>(a,b);
	cout<<"Zbroj od "<<a<<" i "<<b<<" je "<<r1<<endl;
	int r2=zbroji<int>(a,b,c);
	cout<<"Zbroj od "<<a<<", "<<b<<" i "<<c<<" je "<<r2<<endl;
	const int n=5;
	int p1[n];
	cout<<"Unos elemenata prvog niza"<<endl;
	for(int i=0;i<n;i++){
		cout<<"Unesi "<<i+1<<". element prvog niza:";
		cin>>p1[i];
	}
	int p2[n];
	cout<<endl<<"Unos elemenata drugog niza"<<endl;
	for(int j=0;j<n;j++){
		cout<<"Unesi "<<j+1<<". element drugog niza:";
		cin>>p2[j];
	}
	
	int p3[n];
	zbroji<int>(p1,p2,p3,n);
	cout<<"Zbroj tih dvaju nizova je sljedeci niz:"<<endl;
	for(int k=0;k<n;k++)
		cout<<p3[k]<<endl;
	return 0;
}



