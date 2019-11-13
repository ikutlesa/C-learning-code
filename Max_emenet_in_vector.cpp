//Napisati gemnericku funkciju za trazenje maksimalnog elementa u polju
//Prototip funkcije je
//        temlate<class T>
//        T field_max(T* field, int size);

#include <iostream>
using namespace std;

template <class T>
T field_max(T* field, int size){
	T* max=field;
	for(int i=0;i<size;i++){
		if(*field>*max)
			max=field;
		field++;
	}
	return *max;
}

int main(){
	int a[]={1,2,3};
	cout<<field_max(a,3)<<endl;
	return 0;
}
