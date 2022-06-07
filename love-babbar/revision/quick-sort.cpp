#include <bits/stdc++.h>
using namespace std;

void quickSort( vector<int>& nums, int start, int end ) {
	if (start >= end)
		return;

	int count = 0;
	for( int i=start; i < end; ++i ) {
		if (nums.at(i) <= nums.at(end) )
			count++;
	}

	int temp = nums.at(start + count);
	nums.at(start + count) = nums.at(end);
	nums.at(end) = temp;

	int i=start, j=start+count+1;
	while( i< start+count && j<=end ) {
		if ( nums.at(i) < nums.at(start+count) )
			i++;
		else if ( nums.at(j) > nums.at(start+count) )
			j++;
		else {
			int temp = nums.at(i);
			nums.at(i) = nums.at(j);
			nums.at(j) = temp;
		}
	}

	quickSort( nums, start, start+count-1 );
	quickSort( nums, start+count+1, end );
}

int main() {
	vector<int> nums = { 5,1,1,2,0,0 };
	quickSort(nums, 0, nums.size() - 1);

	for (int i : nums)
		cout << i << " ";
	cout << endl;
}