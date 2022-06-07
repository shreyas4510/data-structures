#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int n;
	cin >> n;

	vector<int> arr;
	for (int i = 0; i < n; ++i) {
		int input;
		cin >> input;
		arr.push_back(input);
	}

	int k;
	cin >> k;

	map<int, int> sortedElemets;
	for (int i = 0; i < arr.size(); ++i)
		sortedElemets[arr.at(i)]++;

	unordered_map<int, int> pairMap;
	int count = 0;
	for( auto i = sortedElemets.begin(); i != sortedElemets.end(); i++  ) {
		if (k == 0) {
			if ( i -> second >= 2 )
				count++;
		} else {
			if ( pairMap[i -> first - k] )
				count += pairMap[i -> first - k];
			pairMap[i -> first] = 1;
		}
	}

	cout << count << endl;

	return 0;
}