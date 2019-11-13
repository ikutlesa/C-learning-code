#include <iostream.h>
int n;
int a[100];
int b[100];


void hendikepi(){
	for(int i=0;i<n;i++){
		cout << "\nUnesi hendikep " << (i+1) << ". konja(1-100):";
		cin >> a[i]; 
		if ((a[i]<1)||(a[i]>100)){
			cout << "\nHendikep pogresan,probaj ponovo!";
			i--;
		}
	}
}

void rezultat(){
	int m=0;
	do{
		m=0;
		for(int i=0;i<n;i++){
			cout << "\nUnesite koji konj ce biti na " 
			<< (i+1)<< ". mjestu!";
			cin >> b[i];b[i]--;
			if ((b[i]<0)||(b[i]>(n-1))){
			cout << "\nTaj konj ne postoji,probaj ponovo!";
			i--;
		}
		}
		for(int l=1;l<n;l++){
			for(int j=0;j<l;j++){
				if(b[j]==b[l])m=1;
		}
		}
		if(m==1) cout << "\n\nNe moze jedan konj biti na dvije pozicije,probaj ponovo!\n";
	}
	while(m==1);
}

void vjerojatnost(){
	for(int i=0;i<n;i++){
		cout << "\nKonj sa startnim brojem " << (i+1) << " ima hendikep " << a[i] << ".";
	}
	cout << "\n\nVjerojatnost za poredak:\n";
	for(int j=0;j<n;j++){
		cout << "\nNa " << (j+1) << ". mjestu ce biti konj sa startnim brojem " << b[j]+1 << ".";
	}
	double vj=1;
	double sum;
	for(int g=0;g<n;g++){
		sum=0;
		for(int h=g;h<n;h++)sum=sum+a[b[h]];
		vj=vj*(a[b[g]]/sum);
	}
		cout << "\n\nje    " << vj << " \n\n";
}
void main(){
	cout << "\nUnesi broj konja:";cin >> n;
	hendikepi();
	rezultat();
	vjerojatnost();
}