//rad sa ocnst-om 

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	const float pi=3.14; //deklaracija nepromijenjivog objekta tipa float
	//pi=3.1415926; pogreška
	//float *pipok=&pi; pipok=3.1415926; takodjer pogresno
   
	//na simbolicke konstante se smiju usmjeravati samo pokazivaci koji 
	//su eksplicitno deklarirani tako da pokazuju nepromjenjive objekte
	//pa je dozvoljeno sljedeæe:
    cout<<pi<<endl;
	float const *pipok;
	pipok=&pi;
	cout<<*pipok<<endl;
   //pipok se smije i preusmjeravati 
	 float r=23.4;
	 pipok=&r;
   //zelimo promijenit vrijednost od r
	 r=45.2; //
   //*pipok=45.2; nije dozvoljeno jer pipok pokzjuje na nepromjenj. obj.
	 cout<<r<<endl;
	 
	 //moguce je i definirati nepromijenjivi pokazivac koji moze pokaziv.
     //samo na jedan objekt,on se mora incijelizirati te se kasnije ne
	 //moze prusmjeravati: evo primjera
 
     double nekiBroj=1989.1005;
	 double *const neMrdaj=&nekiBroj;

	 //objekt na koji pokzivac pokazuje moze se moze se po volji mijenj.
    
	 nekiBroj=1993.1009;      //izravno mijenjanje
     cout<<"nekiBroj="<<nekiBroj<<endl;
	 *neMrdaj=1993.1009;      // mijenjanje preko pokazivaca
	 cout<<"*neMrdaj="<<*neMrdaj<<endl;
	 
	 double nekiDrugiBroj=1205;
	 //pogresno je usmjeriti pokazivac neMrdaj na adresu ove varijable
	 //neMrdaj=&nekiDrugiBroj;
	 
    //Moguce je i deklarirati:NEPROMIJENJICI POKAZIVAC NA NEPROMIJENJIVI
	//OBJEKT sto pokazuje ovaj primjer:
	 
	 const float q=1.602e-19; //dekl. nepromj. objekta tipa float
	 const float *const nabojElektrona=&q;//dekl. i inicij. takvog pokaz.
	 cout<<"q="<<q<<endl;
	 cout<<"*nabojElektrona="<<*nabojElektrona<<endl;
	 cout<<"adresa og q je "<<nabojElektrona<<endl;
	 return 0;
}