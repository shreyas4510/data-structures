#include<iostream>
using namespace std;

int getKeypadCombinations( int number, string* combinations, string *keypad ) {
	if ( number == 0 || number == 1 ) {
		combinations[0] = "";
		return 1;
	}
	
	int size = getKeypadCombinations(number/10, combinations, keypad);
	
	string tempArr[size];
	for ( int i=0; i<size; i++ ) {
		tempArr[i] = combinations[i];
 	}
	
	for ( int i=0; i<(size * keypad[number%10].length()); i++ ) {
		combinations[i] = keypad[number%10][ i/size ] + tempArr[ i%size ];
	}
	return (size * keypad[number%10].length());
} 

int main() {
	string keypad[] = { "", "", "abc", "def", "ghi", "ijk", "mno", "pqrs", "tuv", "wxyz" };
	string combinations[1000];
	int size = getKeypadCombinations(72, combinations, keypad);
	for ( int i=0; i<size; i++ ) {
		cout << combinations[i] << endl;
	}
	
}
