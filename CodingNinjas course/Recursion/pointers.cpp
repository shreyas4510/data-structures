#include <iostream>
using namespace std;

int main() {
	int i = 10;
	int *p = &i;
	
	cout << i << endl << p << endl << *p << endl;
	
	i++;
	cout << "\nValue Increment" << endl;
	cout << i << endl << p << endl << *p << endl;
	
//	p++;
//	cout << "\nP inncremented" << endl;
//	cout << i << endl << p << endl << *p << endl;
	
	(*p)++;
	cout << "\n*P inncremented" << endl;
	cout << i << endl << p << endl << *p << endl;

	int* q = p;
	cout << "\nQ introduced" << endl;
	cout << i << endl << p << endl << *p << endl << q << endl << *q << endl;
	
	int f = 22;
	int *ptr=0;
	cout << "\nNew Pointer" << endl;
//	*ptr = f;
	cout << f << endl << ptr << endl << *ptr;
}
