#include <bits/stdc++.h>
using namespace std;

int main() {
	int arr[] = {1,9,3,10,4,20,2};
	int n = 7;

	set<int> sortedElements;
	for(int i=0; i<n; i++)
		sortedElements.insert(arr[i]);

	int count = 1, currentMax = INT_MIN, prev = INT_MIN;
	for (auto item = sortedElements.begin(); item != sortedElements.end(); item++) {

		if (prev == INT_MIN) {
			prev = *item;
			continue;
		}

		if ( *item == prev+1 )
			++count;
		else
			count = 1;

		if (currentMax < count)
			currentMax = count;
		prev = *item;
	}
	cout << (currentMax == INT_MIN ? n : currentMax) << endl;
	cout << currentMax << endl;
}