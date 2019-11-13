//Napisati genereicku funkciju koja pronalazi najveci element u 
//u STL listi . Funkcija je parametrizirana tipom elementa u 
//listi i komparatorom elemenata. Prototip funkcije je
//    template <class T, class Comp>
//    T max_in_list(std::list<T>& l, Comp cpm);

#include <list>
#include <iostream>
using namespace std;

template <class T,class Comp>
T max_in_list(std::list<T>& l,Comp cmp){
	std::list<T>::iterator i=l.begin();
	std::list<T>::iterator max=l.begin();
	for(  ;i!=l.end();i++)
		if (cmp(*max,*i))
			max=i;
     return *max;
}

int main(){
	list<int> l;
	l.push_front(1);
	l.push_front(2);
	l.push_front(3);
 	cout<<"Elementi su:"<<endl;
	std::list<int>::iterator i=l.begin();
	for(  ;i!=l.end();i++)
		cout<<*i<<endl;
	cout<<"Najveci u listi je "<<max_in_list(l,std::less<int>())<<endl;
	return 0;
}
	

