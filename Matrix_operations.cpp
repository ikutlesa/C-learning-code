#include <iostream.h>
#include <stdlib.h>
class modgr{
	int a[4];
public:
	modgr(){};
	modgr(int,int,int);
	modgr operator *(modgr&);
	modgr operator /(modgr&);
	modgr inverz();
	friend ostream& operator <<(ostream&,modgr&);
	void inicijalizacija();
};
modgr modgr::inverz(){
	modgr temp;
	temp.a[0]=a[3]/(a[0]*a[3]-a[1]*a[2]);
    temp.a[1]=a[1]/(a[1]*a[2]-a[0]*a[3]);
	temp.a[2]=a[2]/(a[1]*a[2]-a[0]*a[3]);
    temp.a[3]=a[0]/(a[0]*a[3]-a[1]*a[2]);
	return temp;
}
ostream& operator <<(ostream& s,modgr& m){
	return s << "\nTrazena matrica je \n" << m.a[0] << "  " << m.a[1] << "\n" << m.a[2] << "  " << m.a[3] << "\n";
}
void modgr::inicijalizacija(){
	int x=1,y,z;
	y=rand();
	z=rand();
    long int w=y*z+1;
	a[0]=x;a[1]=y;a[2]=z;a[3]=w;
}
modgr::modgr(int x,int y,int z){
	int w=(1+y*z)/x;
	if((x*w-y*z)!=1){
		cerr << "\nMatrica s tim brojevima ne postoji!\n";
		exit(1);
	}
    a[0]=x;a[1]=y;a[2]=z;a[3]=w;

}
modgr modgr::operator /(modgr &m){
	modgr temp;
	temp=(*this)*(m.inverz());
	return temp;
}
modgr modgr::operator *(modgr &m){
	modgr temp;
	temp.a[0]=a[0]*m.a[0]+a[1]*m.a[2];
	temp.a[1]=a[0]*m.a[1]+a[1]*m.a[3];
    temp.a[2]=a[2]*m.a[0]+a[3]*m.a[2];
	temp.a[3]=a[2]*m.a[1]+a[3]*m.a[3];
	return temp;
}
void main(){
modgr m2(1,2,3),m3(2,3,5),m1,m4,m5,m6;
m6.inicijalizacija();
m1=m6.inverz();
m4=m1*m6;
m5=m4/m1;
cout << m1;
cout << m2;
cout << m3;
cout << m4;
cout << m5;
cout << m6;
}