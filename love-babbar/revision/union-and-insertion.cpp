#include <bits/stdc++.h>
using namespace std;

int main() {
	int n = 5, m = 3;
	int a[] = { 1, 3, 4, 5, 7 }, b[] = { 2, 3, 5, 6 };

	set<int> unionSet;
	for (int i = 0; i < ( n > m ? n : m ); ++i) {
		if ( i < n )
			unionSet.insert(a[i]);
		if ( i < m )
			unionSet.insert(b[i]);
	}

	for (auto i = unionSet.begin(); i != unionSet.end(); ++i) {
		cout << *i << "  ";	
	}
	cout << endl << unionSet.size() << endl;

	unordered_map<int, bool> intersectionSet;
	for (int i = 0; i < n; ++i) {
		intersectionSet[a[i]] = true;
	}

	for (int i = 0; i < m; ++i) {
		if (intersectionSet.count(b[i])) {
			cout << b[i] << "  ";
		}
	}
}