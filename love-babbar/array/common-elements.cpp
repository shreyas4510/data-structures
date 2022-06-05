#include <bits/stdc++.h>
using namespace std;

int main() {
	int n1 = 6, n2 = 5, n3 = 8;
	int A[] = {1, 5, 10, 20, 40, 80}, B[] = {6, 7, 20, 80, 100}, C[] = {3, 4, 15, 20, 30, 70, 80, 120};

	int maxi = max({ n1, n2, n3 });

	map<int, bool> amap, bmap, cmap;
	for (int i = 0; i < maxi; ++i) {
		if (i < n1)
			amap[A[i]] = true;
		if (i < n2)
			bmap[B[i]] = true;
		if (i < n3)
			cmap[C[i]] = true;
	}

	for ( auto item : amap ) {
		if ( bmap[item.first] && cmap[item.first] ) {
			cout << item.first << " ";
		}
	}
	cout << endl;
	return 0;
}