//Definirati genericku klasu koja opisuje LIFO stack . Klasa je
//parametrizirana tipom elemenata koji se stavljaju na stack i 
//ima dvije funkcije: push i pop.

#include <iostream.h>

template <typename T>
class stack {

	struct element {
		T data;
		element * next;
	};

	element * top;

	public:
		stack() {top = NULL;}

		void push(T data){
 			element * old_top = top;
			top = new element;
			top->data = data;
			top->next = old_top;
		}
			
		T pop() {	
			element * new_top = top->next;
			T temp=top->data;

			delete top;
			top = new_top;
			return temp;
		}

   
		~stack() {while(top) pop();}

		void ispisi_prvi(){	cout << top->data << '\n';}

};

int main (void)
{
	stack<int> s;
//	s.ispisi_prvi();

	s.push(1);
	s.ispisi_prvi();

	s.push(2);
	s.ispisi_prvi();

	s.pop();
	s.ispisi_prvi();

	s.pop();
//	s.ispisi_prvi();



	stack<double> p;
//	p.ispisi_prvi();

	p.push(1);
	p.ispisi_prvi();

	p.push(2);
	p.ispisi_prvi();

	p.pop();
	p.ispisi_prvi();

	p.pop();
//	p.ispisi_prvi();

	return 0;
}



