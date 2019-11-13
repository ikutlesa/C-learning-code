#include<iostream.h>
#include<math.h>
#include<stdlib.h>
template<class P>
class polinom{
	P *p;
	int stupanj;
public:
	polinom(){p=0;};
	polinom(int);
	void init();
	void ispis();
	polinom operator +(polinom&);
	polinom operator -(polinom&);
	polinom operator -();
	P operator [](int);
	P operator ()(P);
	polinom operator *(polinom&);
	polinom operator /(polinom&);
};
template<class P>
P polinom<P>::operator [](int n){
	P temp;
	if((n>stupanj)||(n<0)){
		cerr << "\nZadani parametar nije dobar";
		exit(1);
	}
	temp=p[n];
	return temp;
}
template<class P>
P polinom<P>::operator ()(P t){
	P temp=0,te=1;
	for(int i=0;i<=stupanj;i++){
		te=1;
		if(i!=0){
			for(int j=1;j<=i;j++)te=te*t;
		}
		temp=temp+(p[i]*te);
	}
	return temp;
}
template<class P>
polinom<P> polinom<P>::operator /(polinom<P>& b){
	int m=stupanj;
    int n=b.stupanj;
	if(m<n)cout << "\nDijeljenje nije moguce!";
    polinom<P> k(m);
	polinom<P> temp(m-n);
    for(int f=0;f<=m;f++)k.p[f]=p[f];
	for(int l=0;l<=(m-n);l++)temp.p[l]=0;
	for(int i=(m-n);i>=0;i--){
		temp.p[i]=(k.p[i+n]/b.p[n]);
		for(int j=0;j<=n;j++)
			k.p[j+i]=(k.p[j+i]-(b.p[j]*temp.p[i]));
	}
	return temp;
}
template<class P>
polinom<P> polinom<P>::operator *(polinom<P>& q){
	int m=stupanj;
    int n=q.stupanj;
	polinom<P> temp(m+n);
	for(int l=0;l<=(m+n);l++)temp.p[l]=0;
	for(int i=0;i<=(m+n);i++)
		for(int j=0;j<=m;j++)
			for(int k=0;k<=n;k++)
				if(i==(j+k))
					temp.p[i]=((temp.p[i])+p[j]*q.p[k]);
	return temp;
}
template<class P>
polinom<P> polinom<P>::operator -(){
	polinom<P> temp(stupanj);
	for(int i=0;i<=stupanj;i++)
		temp.p[i]=-p[i];
	return temp;
}
template<class P>
polinom<P> polinom<P>::operator -(polinom<P> &q){
	int n=(stupanj>=q.stupanj)?stupanj:q.stupanj;
    int m=(stupanj<q.stupanj)?stupanj:q.stupanj;
	polinom<P> temp(n);
	for(int i=0;i<=n;i++){
		if(i<=m)temp.p[i]=p[i]-q.p[i];
			else{
			if(stupanj>q.stupanj)temp.p[i]=p[i];
            if(stupanj<q.stupanj)temp.p[i]=-q.p[i];
		}
	}
	return temp;
}
template<class P>
polinom<P> polinom<P>::operator +(polinom<P> &q){
	int n=(stupanj>=q.stupanj)?stupanj:q.stupanj;
    int m=(stupanj<q.stupanj)?stupanj:q.stupanj;
	polinom<P> temp(n);
	for(int i=0;i<=n;i++){
		if(i<=m)temp.p[i]=p[i]+q.p[i];
			else{
			if(stupanj>q.stupanj)temp.p[i]=p[i];
            if(stupanj<q.stupanj)temp.p[i]=q.p[i];
		}
	}
	return temp;
}
template<class P>
polinom<P>::polinom(int n){
	stupanj=n;
	p=new P[stupanj+1];
}
template<class P>
void polinom<P>::init(){
	for(int i=0;i<=stupanj;i++){
		cout << "\nUnesi koeficijent uz " << i << ". potenciju:";
		cin >> p[i];
	}
}
template<class P>
void polinom<P>::ispis(){
	cout << endl;
	for(int i=0;i<=stupanj;i++){
	  if(p[i]!=0){
		switch(i){
		case 0:cout << p[i];break;
		case 1:if(p[i]<0)cout << "-";else cout << "+";
			if(fabs(p[i])==1)cout << "x";
			else
				if(fabs(p[i])!=1)cout << fabs(p[i]) << "x";break;
		default:if(p[i]<0)cout << "-";else cout << "+";
			if(fabs(p[i])==1)cout << "x^" << i;
			else
				if(fabs(p[i])!=1)cout << fabs(p[i])  << "x^" << i;
				break;
		}
	  }
	}
	cout << endl;
}
void main(){
	polinom<int> p1(1),p2(3),p3,p4,p5,p6,p7,p8;
	p1.init();p2.init();
	p8=p2/p1;
	p3=p1+p2;
	p4=p1-p2;
	p5=p2-p1;
	p6=-p2;
	p7=p1*p2;
    p1.ispis();p2.ispis();p3.ispis();
	p4.ispis();p5.ispis();p6.ispis();
	p7.ispis();p8.ispis();
	cout << p1(10) << endl << p1[1] << endl;
}