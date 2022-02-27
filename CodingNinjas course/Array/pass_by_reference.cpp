#include <iostream>
using namespace std;

void increment(int& m) {
	m+=15;
}

int main() {
	int i=10;
	int& j = i;
	
	cout << ++j << endl;
	cout << i << endl; 
	
	cout << endl;
	increment(i);
	cout << i;
}
