#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	int n = 6;
	int arr[] = { 7, 10, 4, 3, 20, 15 };

	set<int> ourset;
	for (int i = 0; i < n; ++i) 
		ourset.insert(arr[i]);

	int i = 1;
	set<int> :: iterator it = ourset.begin();
	// while( i < 3 ) {
	// 	i++;
	// 	it++;
	// }
	// cout << it -> first << endl;
	advance(it, 3);
	cout << *it << endl;
}