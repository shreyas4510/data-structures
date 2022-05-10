#include <iostream>
#include <unordered_map>
using namespace std;

bool hasArrayTwoCandidates(int arr[], int n, int x) {
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++) {
    	if( map.count(x - arr[i]) )
    		return true;
    	map[arr[i]] = 1;
    }
    return false;
}

int main() {
	int n, x;
	cin >> n >> x;
	int *arr = new int[n];
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	cout << hasArrayTwoCandidates(arr, n, x) << endl;
}