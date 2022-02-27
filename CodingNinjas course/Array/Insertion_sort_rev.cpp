#include <iostream>
using namespace std;

int main() {
	int n = 7;
	int arr[7] = { 2, 13, 4, 1, 3, 6, 28 };

	for (int i = 1; i < n; i++)
	{
		int j=i;
		while( arr[j] < arr[j-1]) {
			int temp = arr[j];
			arr[j] = arr[j-1];
			arr[j-1] = temp;
			j--;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
}