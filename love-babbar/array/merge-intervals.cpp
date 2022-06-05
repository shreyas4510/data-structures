#include <bits/stdc++.h>
using namespace std;

int main() {

	vector<vector<int>> intervals = {{1,3},{8,10},{15,18},{2,6}};
	vector<vector<int>> result;

	sort(intervals.begin(), intervals.end());
	result.push_back(intervals.front());

	for (auto i = intervals.begin()+1; i != intervals.end(); ++i) {
		vector<int> temp = result.back();

		cout << (*i)[0] << endl;
		cout << temp[0] << endl;

		if ( (*i)[0] > temp[1] ) {
			result.push_back(*i);
		} else {
			vector<int> newPair;
			newPair.push_back( temp[0] < (*i)[0] ? temp[0] : (*i)[0] );
			newPair.push_back( temp[1] > (*i)[1] ? temp[1] : (*i)[1] );
			result[result.size() - 1] = newPair;
		}
	}

	for (vector<int> i : result) {
		cout << "[ ";
		for(int j : i) 
			cout << j << " ";
		cout << " ]" << endl;
	}

}