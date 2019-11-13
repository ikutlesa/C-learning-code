//Napisati funkciju koja ispisuje kolinearnost (linearnu zavisnost)
//dva STL vektora. Prototip funkcije je 
//     template <class T>
//     bool linear_dep(std::vector<T>& v, std::vector<T>& w); 

#include <iostream>
#include <vector>
using namespace std;

template <class T>
bool linear_dep(std::vector<T>& v, std::vector<T>& w){
	if (v.size()!=w.size()){
		cout<<"Nisu jednake dimenzije"<<endl;
		return false;
	}
	else{
		std::vector<T>::iterator i=v.begin();
		std::vector<T>::iterator j=w.begin();
		bool kolinear=true;
		float alpha=static_cast<float>(*i) /static_cast<float>(*j);
			for(  ; (i!=v.end())&&(kolinear!=false); i++){
			if (static_cast<float>(*i) /static_cast<float>( *j)!=alpha)
				kolinear=false;
			j++;
			}
		return kolinear;
	}
}

int main(){
	vector<int> v;
	vector<int> w;
	v.push_back(4);
	v.push_back(2);
	w.push_back(2);
	w.push_back(1);
	bool dep=linear_dep(w,v);
	if(dep)
		cout<<"vektori su linearno zavisni"<<endl;
		else
			cout<<"vektori su linearno nezavisni"<<endl;

    return 0;
}





