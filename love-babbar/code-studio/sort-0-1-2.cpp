#include <bits/stdc++.h>
using namespace std;

int main() {
	int arr[] = { 1, 0, 0, 0, 1, 0, 1, 0, 0, 0 };
	int n = 10;

	// int i = 0, j = n-1;
	// while( i < j ) {
	// 	if ( arr[i] > arr[j] ) {
	//  		int temp = arr[i];
	//  		arr[i] = arr[j];
	//  		arr[j] = temp;
	//  	} else {
	//  		i++;
	//  	}

	//  	if ( arr[j] == 1 ) {
	//  		j--;
	// 	}

	// }

	// for (int i = 0; i < n; ++i) {
	// 	cout << arr[i] << " ";
	// }

	int cnt0 = 0, cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == 0 )
			cnt0++;
		else if ( arr[i] == 1 )
			cnt1++;
		else
			cnt2++;
	}

	for (int i = 0; i < n; ++i) {
		if (i < cnt0) 
			arr[i] = 0;
		else if ( i < (cnt0+cnt1) )
			arr[i] = 1;
		else 
			arr[i] = 2;
	}

	for (int i = 0; i < n; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}