#include <bits/stdc++.h>
using namespace std;

// incorrect solution

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        for (int i = 0; i < n; i++) {
            if ((arr[i]-k) > 0 )
                arr[i] -= k;
            else
                arr[i] += k;
        }
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
        sort(arr, arr+n);
        return arr[n-1] - arr[0];
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}