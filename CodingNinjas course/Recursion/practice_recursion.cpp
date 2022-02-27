#include<iostream>
using namespace std;

// Approach 1

//int printNaturalNumbers(int n) {
//	if(n == 0) {
//		return 0;
//	}
//	printNaturalNumbers(--n);
//	cout << ++n << endl;
//	return n;
//}

// Approach 2
int printNaturalNumbers(int n) {
	if(n <= 50) {
		cout << n << endl;
		printNaturalNumbers(n+1);
	}
}


int main() {
	int n=1;
	printNaturalNumbers(n);
}
