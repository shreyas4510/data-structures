#include <iostream>
#include <unordered_map>
using namespace std;

int findElementWithMaxFrequency(int *arr, int n) {
	int element, count = 0;
	unordered_map<int, int> map;

	for (int i = 0; i < n; ++i) {
		map[arr[i]] = map[arr[i]] + 1;
		if (map[arr[i]] > count) {
			count = map[arr[i]];
			element = arr[i];
		}
	}
	return element;
}

int main() {
	int n;
	cin >> n;

	int *arr = new int[n];
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	cout << findElementWithMaxFrequency(arr, n) << endl;
	delete [] arr;
}