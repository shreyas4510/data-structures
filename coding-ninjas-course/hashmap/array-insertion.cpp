#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> arrayInsertion( int n, int *arr, int n1, int *arr1 ) {
	vector<int> result;
	unordered_map<int, int> map;
	for (int i = 0; i < n; ++i) {
		map[arr[i]] = map[arr[i]] + 1;
	}

	for (int i = 0; i < n1; ++i) {
		if (map[arr1[i]]) {
			result.push_back(arr1[i]);
			map[arr[i]] = map[arr[i]] - 1;
		}
	}
	return result;
}


int main() {
	int n, n1;
	
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cin >> n1;
	int *arr1 = new int[n1];
	for (int i = 0; i < n1; i++)
		cin >> arr1[i];

	for (int item : arrayInsertion(n, arr, n1, arr1))
		cout << item << " ";
	cout << endl;

	delete [] arr;
	delete [] arr1;
}