#include<iostream>
#include<vector>
using namespace std;


/////// Failed approach
int main()
{
	int n=5, q=3;
	vector<vector<int>> arr = {{ 1, 2, 100}, {2, 5, 100}, {3, 4, 100}};

	vector<int> ans(n, 0);
	for (int i = 0; i < q; i++)
	{
		for (int j = arr[i][0]-1; j < arr[i][1]; j++)
		{
			ans[j] += arr[i][2];
		}
	}

	int max = INT_MIN;
	for ( int i : ans )
	{
		if ( max < i )
		{
			max = i;
		}
	}

	cout << max;

	return 0;
}