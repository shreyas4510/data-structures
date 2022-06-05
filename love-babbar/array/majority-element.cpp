#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {
    sort( nums.begin(), nums.end() );
    int max_count = 0, max_ele = nums.at(0), current_count = 0, current_ele = nums.at(0);
    for( int i=1; i < nums.size(); i++ ) {
        if( nums.at(i) == current_ele ) {
            current_count++;
        } else {
            current_count = 0;
            current_ele = nums.at(i);
        }
        
        if( current_count > max_count ) {
            max_count = current_count;
            max_ele = nums.at(i);
        }
    }
    return max_ele;
}

int main() {
	vector<int> arr = { 2,2,1,1,1,2,2 };
	cout << majorityElement(arr) << endl;
}