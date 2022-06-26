#include <bits/stdc++.h>
using namespace std;

int findMedian( vector<int> v ) {
	sort(v.begin(), v.end());
	int size = v.size();
	if ( size % 2 == 0 ) {
		int temp = size/2;
		return ( (v.at(temp-1) + v.at(temp)) / 2 );
	} else {
		return v.at(size/2);
	}
}

int main() {
	vector<int> v = { 56, 67, 30, 79 };
	cout << findMedian(v) << endl;
}