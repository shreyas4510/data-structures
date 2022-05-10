#include <iostream>
#include <unordered_map>
using namespace std;

int getPairsCount(int arr[], int n, int k) {
	int count = 0;
	unordered_map<int, int> map;
	for (int i = 0; i < n; ++i)
		map[arr[i]] = map[arr[i]] + 1;

	unordered_map<int, int> :: iterator it = map.begin();
	while( it != map.end() ) {		
		if (map.count(k - (it -> first))) {
			if(map[it -> first] > 0) {
				if ( it -> first == (k - (it -> first))) {
					map[it -> first] -= 1;
					count += map[it -> first];
				} else {
					if( map[it -> first] > 1 && map[k - (it -> first)] > 1 )
						count += (map[it -> first] * map[k - (it -> first)]);
					else if ( map[it -> first] > map[k - (it -> first)] )
						count += map[it -> first];
					else
						count += map[k - (it -> first)];
					map[it -> first] = 0;
					map[k - (it -> first)] = 0;
					it++;
				}
			} else {
				it++;
			}
		} else {
			it++;
		}
	}
	return count;
}

int main() {
	int n, x;
	cin >> n >> x;
	int *arr = new int[n];
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	cout << getPairsCount(arr, n, x) << endl;
}
