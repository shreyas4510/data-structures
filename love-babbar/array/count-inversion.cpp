#include <bits/stdc++.h>
using namespace std;

int main() {
	int n = 5;
	int arr[] = { 2, 4, 1, 3, 5 };


	// O( N^2 )
	int count = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i+1; j < n; ++j) {
			if ( arr[i] > arr[j] ) {
				count++;
			}
		}
	}
	cout << count << endl;



}