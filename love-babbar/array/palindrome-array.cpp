#include <bits/stdc++.h>
using namespace std;

int PalinArray(int a[], int n) {
	for (int i = 0; i < n; ++i) {
		string s = to_string(a[i]);
		for (int j = 0; j < (s.length() / 2); ++j) {
		 	if(s[j] != s[s.length()-1-j]) {
		 		return 0;
		 	}
		} 
	}
	return 1;
}

int main() {
	int a[] = { 121, 131, 20 };
	int n = 3;
	cout << PalinArray(a, n) << endl;
}