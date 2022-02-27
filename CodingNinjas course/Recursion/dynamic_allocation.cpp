#include <iostream>
using namespace std;

int main() {
	int* i = new int;
	*i=10;
	cout << *i << endl;
	delete i;
	
	
	int n;
	cin >> n;	
	int* arr = new int[n];
	*arr = 1;
	*(arr + 1) = 2;
	
	cout << arr[0] << " " << arr[1];
	delete [] arr;
}
