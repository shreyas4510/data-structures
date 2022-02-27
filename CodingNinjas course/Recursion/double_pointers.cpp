#include<iostream>
using namespace std;

void increment(int** p) {
	p++;
}

void increment1(int** p) {
	(*p)++;
}

void increment2(int** p) {
	(**p)++;
}

int main() {
	int a = 10;
	int* p = &a;
	int** p1 = &p;
	
	cout << a << endl;
	cout << p << " " << *p << endl;
	cout << p1 << " " << *p1 << " " << **p1 << endl << endl;
	
//	increment(p1);
//	cout << p1 << " " << p << " " << a << endl;
//
//	increment1(p1);
//	cout << p1 << " " << p << " " << a << endl;

	increment2(p1);
	cout << p1 << " " << p << " " << a << endl;
}
