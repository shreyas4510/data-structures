#include "./max-heap.h"
using namespace std;

int main() {
	maxHeap mHobj;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int input;
		cin >> input;
		mHobj.insert( input );
	}

	mHobj.print();
	cout << "Is Empty : " << mHobj.isEmpty() << endl; 
	cout << "Size : " << mHobj.getSize() << endl; 
	cout << "Max : " << mHobj.getMax() << endl; 

	cout << mHobj.remove() << endl;
	cout << mHobj.remove() << endl;
	mHobj.print();
}