#include<bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> sortedArr;
    int i = 0, j = 0;

    while( i < nums1.size() || j < nums2.size() ) {
    	if (i >= nums1.size()) {
    		sortedArr.push_back(nums2.at(j));
    		j++;
    	} else if (j >= nums2.size()) {
    		sortedArr.push_back(nums1.at(i));
    		i++;
    	} else if ( nums1.at(i) < nums2.at(j) ) {
    		sortedArr.push_back(nums1.at(i));
    		i++;
    	} else {
    		sortedArr.push_back(nums2.at(j));
    		j++;
    	}
    }

    int size = sortedArr.size();
    double divider = 2.00000;
    double multiplier = 1.00000;

    if (size % 2 == 0) {
    	int temp = size/2;
    	double ans = (double)sortedArr.at(temp-1) + (double)sortedArr.at(temp); 
    	return ans / (double) divider; 
    } else {
    	return sortedArr.at(size/2) * multiplier;
    }
}

int main() {
	vector<int> nums1 = { 1,2 }, nums2 = { 3,4 };
	cout << findMedianSortedArrays(nums1, nums2) << endl; 
}