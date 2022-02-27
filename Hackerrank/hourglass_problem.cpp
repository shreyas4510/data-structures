#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<vector<int>> arr;

	for ( int i=0; i<6; i++ ) {
		vector<int> temp;
		for( int j=0; j<6; j++ ) {
			int input;
			cin >> input;
			temp.push_back(input);
		}
		arr.push_back(temp);
	}
	
	cout << endl;
	int max = INT_MIN;
	for ( int i=0; i<4; i++ ) {
		for ( int j=0; j<4; j++ ) {
			int sum = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+1] + arr[i+2][j+0] + arr[i+2][j+1] + arr[i+2][j+2]; 
			if ( max < sum ) {
				max = sum;
			}
		}	
	}
	cout << max;
}
