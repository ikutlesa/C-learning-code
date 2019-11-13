//modificirani bubble_sort sa koristenjem funkcije i predlozaka unutar funkcije
#include <iostream.h>

template <class T> //kopira time za nas funkciju koliko puta trebamo za svaki tip
//generira se za svaki tip novi kod
//ne znci da je to klasa,moze ici i template<typename T>

void bsort(T *p,int n,int (*greater)(const T&,const T&)) {  
	for(int i=0;i<n;++i)
		for(int j=0;j<n-i-1;++j)
			if (greater(p[j],p[j+1])){
				T temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
}

template <class T>
int greater(const T& a1, const T& a2){
	return a1>a2;
}

template <class T>
void print(T* p,int n)
	{
	cout<<"sortirano polje je:"<<endl; 
	for(int i=0;i<n;i++)
	 {
		 cout<<*p<<" ";
		 p++;
	 }
	 cout<<endl;
	 return;
}
//ali sve template f-je moraju 

int main()
 {
	int a[]={3,2,1};//kompajler mora znati za ovo u trenutku prevodjenja
	bsort<int>(a,3,greater);
	print(a,3);
	double b[]={1.0,2.3,1.7};
	bsort<double>(b,3,greater<double>);
	print(b,3);
	return 0;
}
