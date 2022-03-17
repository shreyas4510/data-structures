#include<iostream>
#include<vector>
using namespace std;

int main() {
	int target;
	vector<int> v;
	vector<vector<int>> ans;
	
	for ( int i=0; i<8; i++ ) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	cin >> target;
	
	for (int i=0; i<v.size(); i++) {
 		for ( int j=i+1; j<v.size(); j++ ) {
 			vector<int> temp;
 			if ( v[i] + v[j] == target ) {
 				temp.push_back(v[i]);
 				temp.push_back(v[j]);
 				
 				ans.push_back(temp);
 				temp.clear();
			}	
		}
	}	

	for ( int i=0; i<ans.size(); i++ ) {
		cout << "[ " << ans[i][0] << ", " << ans[i][1] << " ]" << endl;
	}
}
