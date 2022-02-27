#include <iostream>
using namespace std;

int countZeros( int num ) {
	if( num / 10 == 0 ) {
		return num == 0 ? 1 : 0;
	}
	
	int count = countZeros( num / 10 );
	if ( num % 10 == 0 ) {
		count = count + 1;
	}
	return count;
}

int main() {
	int num;
	cin >> num;
	cout << countZeros(num);
}
