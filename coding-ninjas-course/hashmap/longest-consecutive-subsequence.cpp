#include <iostream>
#include <map>
#include <climits>
using namespace std;

class Pair {
	public:
		int start = INT_MIN, end = INT_MIN, maxCount = 0;
};

int main() {

	int n;
	cin >> n;

	int *arr = new int[n];
	for( int i=0; i<n; i++ ) {
		cin >> arr[i];
	}

	map<int, int> ourmap;
	for (int i = 0; i < n; ++i) {
		ourmap[arr[i]] = ourmap.count(arr[i]) ? ourmap.at(arr[i]) : i;
	}

	map<int, int> :: iterator it;
	Pair currentObj;
	Pair longestObj;

	for (it = ourmap.begin(); it != ourmap.end(); ++it) {
		if ( currentObj.start == INT_MIN ) {
			currentObj.start = it -> first;
			currentObj.end = it -> first;
			currentObj.maxCount = 1;
			continue;
		}

		if ( it -> first == currentObj.end + 1 ) {
			currentObj.maxCount++;
			currentObj.end = it -> first;
		} else {
			if ( 
				(longestObj.maxCount < currentObj.maxCount) ||
				(longestObj.maxCount == currentObj.maxCount && ourmap.at(longestObj.start) > ourmap.at(currentObj.start))
			) {
				longestObj.maxCount = currentObj.maxCount;
				longestObj.start = currentObj.start;
				longestObj.end = currentObj.end;
			}
			currentObj.start = it -> first;
			currentObj.end = it -> first;
			currentObj.maxCount = 1;
		}
	}

	cout << longestObj.start << " " << longestObj.end << endl;
}