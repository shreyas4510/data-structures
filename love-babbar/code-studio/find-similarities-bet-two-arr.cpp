#include <bits/stdc++.h>
using namespace std;

int main() {

	vector <int> arr1 = {1, 2}, arr2 = {3, 4};
	int n = 2, m = 2;
	map<int, int> ourmap;

	int count = 0;

	for (int i : arr1) {
		ourmap[i] = ourmap.count(i) ? ourmap[i] + 1 : 1;
	}

	for (int i : arr2) {
		if (ourmap.count(i)) {
			count++;
		}
		ourmap[i] = ourmap.count(i) ? ourmap[i] + 1 : 1;
	}

	cout << count << endl;
	cout << ourmap.size() << endl;
}