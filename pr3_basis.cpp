//Program racuna n faktorijela za unešenu vrijednost n manju od 13

#include <iostream>
using namespace std;

int main()
{
	int n;
	cout <<"Upisi prirodni broj: "; //manji od 13!
	cin >> n;

	long int fjel = 1;
	for (int i=2; i<=n; i++)
		fjel *=i;
	
	cout << n << "!=" <<fjel << endl;
	return 0;
}