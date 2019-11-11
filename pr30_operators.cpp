//ilustracija preopterecenja operatora u radu s kompleksnim brojevima
#include <iostream>
using namespace std;

class Kompleksni{
//	friend Kompleksni operator-(const Kompleksni &l,const Kompleksni &d);
private:
	float real,imag;
	
public:
	Kompleksni(float r=0,float i=0){
		real=r;
		imag=i;
	}
   
	Kompleksni operator+(const Kompleksni &d);
	Kompleksni operator*(const Kompleksni &d);
	void	print(){
		cout<<real<<"+"<<imag<<"i"<<endl;
	}
};
	
Kompleksni Kompleksni::operator+(const Kompleksni &d){
		Kompleksni res;
		res.real=real+d.real;
		res.imag=imag+d.imag;
		return res;
	}

//Kompleksni operator-(const Kompleksni &l,const Kompleksni &d){
//	Kompleksni res;
//	res.real=l.real+d.real;
//	res.imag=l.imag+d.imag;
//	return res;
//}

Kompleksni Kompleksni::operator*(const Kompleksni &d){
	Kompleksni res;
	res.real=real*d.real-d.real*d.imag;
	res.imag=real*d.imag+imag*d.real;
    return res;
}

int main(){
	Kompleksni a,b,c;
	b=a+5;
	b.print();
	//b=5+a; ne stima jer se 5 ne pretvori u kompleksni,jer je 
	//operator + definiran kao funkcijski clan i samo radi sa objektom a
	c=a*5;
	c.print();
	return 0;
}