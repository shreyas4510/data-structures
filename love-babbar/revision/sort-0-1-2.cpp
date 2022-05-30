#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	int arr[] = { 0, 2, 1, 2, 0 };
	int n = 5;

	int zeros = 0, ones = 0, twos = 0;
	for (int i = 0; i < n; ++i) {
		if(arr[i] == 0) 
			zeros++;
		else if ( arr[i] == 1)
			ones++;
		else
			twos++;
	}

	for (int i = 0; i < n; ++i) {
		if ( i < zeros )
			arr[i] = 0;
		else if ( i < (zeros + ones) )
			arr[i] = 1;
		else
			arr[i] = 2;
	}
}