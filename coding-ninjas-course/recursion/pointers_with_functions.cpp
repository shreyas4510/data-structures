#include <iostream>
using namespace std;

void pointerFunction(int* m) {
	cout << m << " " << *m << endl;
	m++;
	cout << (*m) << endl;
	
	(*m)++;
}

void arrayPointers(int* a) {
	cout << a << endl;
	cout << *a << endl;
	a++;
	
	cout << a << endl;
	cout << *a << endl;
}

void fun(int a[]) {
    cout << a[0] << " ";
}

int main(){
	
//	Int pointers in function
//	int a = 10;
//	int* p = &a;
//	cout << p << " " << *p << " " << a << endl;
//	pointerFunction(p);
//	cout << a;


// 	Array with pointers

//	int a[] = { 1, 7, 3, 4, 5 };
//	cout << a << endl;
//	cout << a[0] << endl;
//	arrayPointers(a);

	
    int a[] = {1, 2, 3, 4};
    fun(a + 1);
    cout << a[0];
}
