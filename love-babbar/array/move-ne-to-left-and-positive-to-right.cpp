#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
	    void segregateElements(int arr[],int n) {
	    	int i=0, j=1;
	    	while( j < n ) {
	    		if ( arr[i] < 0 ) {
	    			i++;
	    			j++;
	    		}
	    		else if ( arr[j] > 0 ) {
	    			j++;
	    		}
	    		else if ( arr[i] > 0 && arr[j] < 0 ) {
	    			int temp = arr[i];
	    			arr[i] = arr[j];
	    			arr[j] = temp;
	    			i++;
	    			j++;
	    		}
	    	}
	    }
};

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		ob.segregateElements(a,n);
		
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
		cout<<endl;
	}
}