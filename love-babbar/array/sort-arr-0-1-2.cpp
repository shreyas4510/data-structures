#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        // TLE solution
        // void sort012(int a[], int n) {
        //     int i=0, j=n-1;
        //     while( i < j ) {
        //         if ( a[i] > a[j] ) {
        //             int temp = a[i];
        //             a[i] = a[j];
        //             a[j] = temp;
        //             i++;
        //             j=n-1;
        //         }
        //         else {
        //             if (a[i] == 0 || a[i] < a[j-1])
        //                 i++;
        //             else
        //                 j--;
        //         }
        //     }
        // }

        void sort012(int a[], int n) {
            int zero=0, one=0, two=0;
            for (int i = 0; i < n; ++i) {
                if (a[i] == 0)
                    zero++;
                else if ( a[i] == 1 )
                    one++;
                else
                    two++;
            }

            for (int i = 0; i < n; ++i) {
                if ( i < zero )
                    a[i] = 0;
                else if ( i < (zero+one) )
                    a[i] = 1;
                else
                    a[i] = 2; 
            }
        }
};

int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

// { 1, 0, 2, 0, 1, 2 }