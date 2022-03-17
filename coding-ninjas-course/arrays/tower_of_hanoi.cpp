#include<iostream>
using namespace std;

void printSteps( int n, char from_step, char to_step, char aux ) {
	if ( n == 0 ) {
		return;
	}
	
	printSteps( n-1, from_step, aux, to_step );
	cout << "Move disc " << n << " from " << from_step << " to " << to_step << endl;
	
	printSteps( n-1, aux, to_step, from_step);
}

int main() {
	int n = 4;
	printSteps(4, 'A', 'C', 'B');
}
