#include <bits\stdc++.h>
using namespace std;

int main() {
	int arr[] = { 4, 5, 6, 7, 6 };
	int n = 5, k = 1, h = 6;

	for (int i = 0; i < n; i++) {
		if (arr[i] == h) {
			cout << i;
			break;
		}
	}
	cout << -1 << endl;
	return 0;
}