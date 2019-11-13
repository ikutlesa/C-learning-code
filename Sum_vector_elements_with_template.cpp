//Napisati genericku funkciju koja izracunava izraze oblika 
//f(a[1])+f(a[2])+...+f(a[n]). Funkcija je parametrizirana
//tipom elementa u polju i funkcijskim objektom f.
//template <class T, class Fun)
//T sum(T* field, int n, Fun fun);

#include <iostream>
using namespace std;

template <class T,class Fun>
T sum(T *field,int n,Fun fun){
	T sum=fun(field[0]);
	for(int i=1;i<n;i++)
		sum=sum+fun(field[i]);
	return sum;
}

template <class T>
struct Fun{
	T operator()(const T& a){
		return a+a;
	}
};

int produkt(const int& a){
	return a*a;
}

int main(){
	Fun<int> f;
	cout<<f(1)<<endl;
	int a[]={1,1,1};
	Fun<int> fun1;
	cout<<"suma sa funkcijom zbroj je "<<sum<int>(a,3,fun1)<<endl;
	cout<<"Suma sa funkcijom produkt je "<<sum<int>(a,3,produkt)<<endl;
	return 0;
}