#include <bits/stdc++.h>
using namespace std;

class maxHeap {
	vector<int> maxHeap;
	
	void swapElements( vector<int>& v, int fi, int si ) {
		int temp = v.at(fi);
		v.at(fi) = v.at(si);
		v.at(si) = temp;
	}

	public:
		int getSize() {
			return maxHeap.size();
		}

		bool isEmpty() {
			return !maxHeap.size();
		}

		int getMax() {
			if (isEmpty()) {
				cout << "Queue is empty" << endl;
				return 0;
			}
			return maxHeap.at(0);
		}

		void insert( int element ) {
			maxHeap.push_back(element);
			int size = getSize();
			int n = size-1;
			while( n > 0 ) {
				int index = ( n-1 )/2;
				if (maxHeap.at(n) > maxHeap.at(index)) {
					swapElements(maxHeap, n, index);
					n = index;
				} else {
					break;
				}
			}
		}

		int remove() {

			if (isEmpty())
				return 0;

			int ans = maxHeap.at(0);

			if (getSize() == 1) {
				maxHeap.pop_back();
				return ans;
			}

			swapElements(maxHeap, 0, getSize()-1);
			maxHeap.pop_back();

			int size = getSize();
			int i = 0;
			while( i < size ) {
				int li = (2*i+1), ri = (2*i+2);
				if (ri < size && maxHeap.at(ri) > maxHeap.at(i) && maxHeap.at(ri) > maxHeap.at(li)) {
					swapElements(maxHeap, i, ri);
					i=ri;
				} else if ( 
					(  ri < size && maxHeap.at(li) > maxHeap.at(i) && maxHeap.at(li) > maxHeap.at(ri) ) ||
					( li < size && maxHeap.at(li) > maxHeap.at(i) )
				) {
					swapElements(maxHeap, i, li);
					i=li;
				} else {
					break;
				}
			}
			return ans;
		}

		void print() {
			int size = getSize();
			for (int i = 0; i < size; ++i) {
				cout << maxHeap.at(i) << " : ";

				int li = (2*i+1), ri = (2*i+2);
				if (li < size) 
					cout << " LC : " << maxHeap.at(li) << " ";
				if (ri < size)
					cout << " RC : " << maxHeap.at(ri);
				cout << endl;
			}
		}
};