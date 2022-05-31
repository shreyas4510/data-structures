#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> arr;
	int input;

	for (int i = 0; i < n; ++i) {
		cin >> input;
		arr.push_back(input);
	}

	int k;
	cin >> k;

	vector<int> temp;
	for (int i = 0; i < k; ++i) 
		temp.push_back(arr.at(i));

	for (int i = k; i < n; ++i)
		arr[i-k] = arr[i];

	for (int i = n-k; i < n; ++i)
		arr[i] = temp[i - n + k];

	for (int i : arr)
		cout << i << " ";
}