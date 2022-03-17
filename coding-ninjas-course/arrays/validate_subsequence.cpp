#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int> array = { 5, 1, 22, 25, 6, -1, 8, 10 }, sequence = { 1, 6, -1, 10 };
	int j=0;
	for ( int i=0; i<array.size(); i++ ) {
		if( sequence[j] == array[i] ) {
			j++;
		}
	}
	
	if ( j == sequence.size() ) {
		cout << "true";
	}
	else {
		cout << "false";
	}
}
