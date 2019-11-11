
//Program sortira niz cijelih brojeva algoritmom bubble sort

#include <iostream.h>
#include <iomanip>
using namespace std;

int main()
{
	const int nmax=100;
	float x[nmax];
	int n;
	
	do
	   {
		cout <<"Unesi broj elemenata niza:";
		cin>>n;
		if(n>nmax) cout<<"Previse elemenata,pokusaj ponovo!"<<endl;
	   }
	while(n>nmax);
	cout<<endl;
	
	for(int i=0;i<n;i++)
		{
		  cout<<"Upisi "<<i+1<<" element niza:";
		  cin>>x[i];
		 }
	
	for(i=n-1;i>0;i--)
		{
		 bool zamjena=false;
	     for(int j=0;j<i;j++)
			{
			  if(x[j+1]<x[j])
				{
				  float priv=x[j];
				  x[j]=x[j+1];
				  x[j+1]=priv;
				  zamjena=true;
				}
			}
		if(zamjena==false)//ako nije bilo zamjene 
		   break;		  //prekini petljanje
	}
    cout<<endl;
	cout<<"Brojevi slozeni po velicini:"<<endl;
	for(i=0;i<n;i++)
		cout<<x[i]<<endl;
	return 0;
}


