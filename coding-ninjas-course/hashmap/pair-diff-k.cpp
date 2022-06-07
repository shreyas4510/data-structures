#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	
	int n;
	cin >> n;

	int *arr = new int[n];
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	int k;
	cin >> k;

	unordered_map<int, int> pairMap;
	int count = 0;
	for (int i = 0; i < n; ++i) {
		if ( pairMap[arr[i] - k] || pairMap[arr[i] + k] ) {
			count += (pairMap[arr[i] - k] ? pairMap[arr[i] - k] : pairMap[arr[i] + k]);
		}
		pairMap[arr[i]]++;
	}

	cout << count << endl;

	return 0;
}