#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    long long maxSubarraySum(int arr[], int n){
        long long max = LONG_MIN, contiguousSum = 0, tempSum = 0, tempMax = LONG_MIN;
        for (int i = 0; i < n; ++i) {
            if (tempMax < arr[i])
                tempMax = arr[i];

            tempSum += arr[i];
            if ( contiguousSum > contiguousSum + arr[i] )
                tempSum = 0;

            contiguousSum += arr[i];
            
            if (contiguousSum < tempSum)
                contiguousSum = tempSum;

            if ( max < contiguousSum )
                max = contiguousSum;
        }        
        if (tempMax < 0)
            max = tempMax;
        return max;
    }
};

int main() {
    int t,n;
    cin>>t;
    while(t--) {
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;       
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}