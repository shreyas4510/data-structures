#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int> v = { 10, 20, 30, 1 };
	int i=0;
	for( ; v[i] < v[i+1]; i++ ) {}
	
	if ( i == v.size()-1 ) {
		cout << 0;
	}
	else {
		cout << i+1;
	}
}
