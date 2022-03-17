#include <iostream>
using namespace std;

int findGCD( int first_num, int second_num ) {
	if ( first_num % second_num == 0 ) {
		return second_num;
	}
	
	int temp = second_num;
	second_num = first_num % second_num;
	first_num = temp;
	int gcd = findGCD(first_num, second_num);
	return gcd;
}

int main() {
	int n1, n2;
	cin >> n1 >> n2;
	
	int min = n1 > n2 ? n2 : n1, max = n1 > n2 ? n1 : n2;
	cout << findGCD(max, min);
	
//	while ( max % min != 0 ) {
//		cout << min << " " << max << endl;
//		int temp = min;
//		min = max % min;
//		max = temp;
//	}
//	
//	cout << "Max : " << max << " Min : " << min << endl; 
}
