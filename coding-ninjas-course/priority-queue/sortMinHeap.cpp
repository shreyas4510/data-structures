#include <bits/stdc++.h>
using namespace std;

void swap( vector<int>& v, int si, int ei ) {
	int temp = v.at(si);
	v.at(si) = v.at(ei);
	v.at(ei) = temp;
}

void insert(vector<int>& v, int e) {
	v.push_back(e);
	int ci = v.size()-1; 
	while( ci > 0 ) {
		int pi = (ci-1)/2;
		if ( v.at(ci) < v.at(pi) ) {
			swap(v, ci, pi);
			ci = pi;
		} else {
			break;
		}
	} 
}

void sort(vector<int>& v, int end) {
	if (v.size() <= 1)
		return;

	int i=0, n = end-1;
	swap(v, i, n);

	while(i < n) {
		int li = ( 2*i+1 ), ri = ( 2*i+2 );
		if ( ri < n && v.at(ri) < v.at(i) && v.at(ri) < v.at(li) ) {
			swap( v, ri, i );
			i = ri;
		} else if ( 
			(li < n && v.at(li) < v.at(i) && v.at(li) < v.at(ri)) ||
			(li < n && ri >= n && v.at(li) < v.at(i))
		) {
			swap( v, li, i );
			i = li;
		} else {
			break;
		}
	}
}

int main() {
	vector<int> heap;
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int input;
		cin >> input;
		insert(heap, input);
	}

	for (int i = 0; i < n; ++i) {
		sort(heap, heap.size()-i);
	}

	for (int i : heap)
		cout << i << " ";
	cout << endl;


}