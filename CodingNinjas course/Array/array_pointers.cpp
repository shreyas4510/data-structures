#include <iostream>
using namespace std;

int main() {
	int a[6] = {1, 2, 3};
	cout << (a + 2);
	
	int i=0;
	int* p = &i;
	
	cout << *p;
}
