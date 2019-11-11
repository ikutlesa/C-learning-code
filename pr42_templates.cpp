//KOSTANTNI IZRAZI KAO PARAMETRI PREDLOZAKA(10.3.6 STR 438)
//Formalni parametar predloska, osim tipa moze biti i konstantni
//izraz, sto cemo vidjet na sljedecem primjeru razreda Spremnik
//Razred Spremnik definira memorijski medjuspremnik za cuvanje
//podataka prilikom komunikacije s uredjajima u racunalu, kao
//sto su disk ili komunikacijski prikljucak. Spremnik moze
//biti razlicitih duljina, pa cemo taj razred realizirati pomocu
//predloska koji ce kao parametar imati cjelobrojni izraz.
//Parametar predloska ce odredjivati duljinu spremnika:

template <int duljina>
class Spremnik {
private:
	char podrucje[duljina];
public:
	void Puni(char *pok,int dulj);
	void Citaj(char *pok,int dulji);
};

//Parametar duljina mora biti poznat prilikom prevodjenja. 
//To znaci da on mora biti sastavljen od samih konstanti.

int main(){
	Spremnik<20> s1;      //Spremnik<20>
	Spremnik<10+10> s2;   //Spremnik<20>
	Spremnik<10 * 2> s3;  //Spremnik<20>
	Spremnik<30> s4;      //Spremnik<30>
	//Ove instancije su ispravne. Generiraju se dva razreda
	//Spremnik<20> i Spremnik<30>. Prve tri deklaracije
	//rezulriraju instancijom samo jednog razreda, jer izrazi
	//u parametru imaju istu vrijednost. Posljednja deklaracija
	//stvara zasebni razred, jer izraz u parametru ima razlicitu
	//vrijednost od prva tri.
    //Sljedece instancija  je neispravno
	//int n=5;
	//Spremnik<n * 20> uzas;
	//Razlog: izraz koji se stavlja kao parametar nije poznat
	//prilikom prevodjenja, nego tek samo prilikom izvodjenja
    
	//Spremnik<6.7 * 6.4> bez_pretvorbe 
	//Ovo gore je pogresno, jer	nema pretvporbe iz realnog u cjelobrojni tip.
	//To se moze urediti pomocu eksplicitne dodjele tipa
	Spremnik<static_cast<int>(6.7 * 6.4)> sada_radi;
	return 0;
}
