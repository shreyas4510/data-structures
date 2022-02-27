#include <iostream>
using namespace std;

int main() {
	int **arr = new int*[3];
	
	for ( int i=0; i<3; i++ ) {
		*(arr + i) = new int[3];
		for( int j=0; j<3; j++ ) {
			cin >> *(*(arr + i) + j);
		}
	}
	
	cout << endl;
	for ( int i=0; i<3; i++ ) {
		for( int j=0; j<3; j++ ) {
			cout << *(*(arr + j) + i) << " ";
		}
		cout << endl;
	}
	
	for ( int i=0; i<3; i++ ) {
		delete [] *( arr + i );
	}
	delete [] arr;
}
