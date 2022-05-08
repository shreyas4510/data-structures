#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> removeDuplicates( int *arr, int size ) {
	vector<int> finalArr;
	unordered_map<int, bool> ourmap;
	for (int i = 0; i < size; i++ ) {
		if ( !ourmap.count(arr[i]) ) {
			ourmap[arr[i]] = true;
			finalArr.push_back(arr[i]);
		}
	}
	return finalArr;
}

int main() {
	int size;
	cin >> size;
	int *arr = new int[size];
	for( int i=0; i < size; i++ )
		cin >> arr[i];
 
	for (int item : removeDuplicates(arr, size) )
		cout << item << " ";
	delete [] arr;
}