// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define ll long long

pair<long long, long long> getMinMax(long long a[], int n) ;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        pair<ll, ll> pp = getMinMax(a, n);

        cout << pp.first << " " << pp.second << endl;
    }
    return 0;
}// } Driver Code Ends


pair<long long, long long> getMinMax(long long a[], int n) {
	if ( n == 0 ) {
		pair<ll, ll> pp;
		pp.first = INT_MAX;
		pp.second = INT_MIN;
		return pp;
	}

	pair<ll, ll> obj = getMinMax(a, n-1);
	if ( obj.first > a[n-1] )
		obj.first = a[n-1];

	if ( obj.second < a[n-1] )
		obj.second = a[n-1];
	
 	return obj;   
}