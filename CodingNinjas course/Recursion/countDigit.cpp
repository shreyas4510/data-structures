#include <iostream>
using namespace std;

int countDigit(int n) {
	if((n / 10) == 0 ) {
		return 1;
	}
	int k = countDigit(n / 10);
	
	cout << "K is : " << k << endl;
	return k+1;
}

int main(){ 
	int n;
	cin >> n;
	cout << countDigit(n);
}
