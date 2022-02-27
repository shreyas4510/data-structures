#include<iostream>
using namespace std;

void printKeypadPatterns( int num, string output, string keypad[] ) {
	if ( num == 0 ) {
		cout << output << endl;
		return;
	}
	
	for ( int i=0; i< keypad[num%10].length() ; i++) {
		printKeypadPatterns(num/10, keypad[num%10][i] + output, keypad);
	}
	
}

int main() {
	string keypad[] = { "", "", "abc", "def", "ghi", "ijk", "mno", "pqrs", "tuv", "wxyz" };
	int number = 27;
	printKeypadPatterns( number, "", keypad );
}
