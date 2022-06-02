#include <bits/stdc++.h>
using namespace std;

int minJumps(int arr[], int n){

	if (n == 0)
		return 0;

	if (n == 1) {
		if (arr[0] == 0)
			return -1;
		else
			return 0;
	}
		
	int steps = arr[0], maxReach = arr[0], jumps = 1;
	for (int i = 1; i < n-1; i++) {
		if (maxReach < i + arr[i])
			maxReach = i + arr[i];

		steps--;
		if (steps == 0) {
			jumps++;
			if ( maxReach <= i )
				return -1;
			steps = maxReach - i;
		}
	}
	return jumps;
}

int main() {
	int arr[] = {2, 3, 1, 1, 2, 4, 2, 0, 1, 1};
	int n = 10;
	cout << minJumps( arr, n ) << endl;
}