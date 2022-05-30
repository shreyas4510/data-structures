#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = { 1,3,4,2,2 };
    unordered_map<int, bool> ourmap;
    for( int i = 0; i < nums.size(); i++ ) {
        if (ourmap.count(nums[i])) {
            cout << nums[i];
            break;
        } else {
            ourmap[nums[i]] = true;
        }
    }
}