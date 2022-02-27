#include<iostream>
using namespace std;

int main() {
	
	int len = 7;
	int arr[len] = { 2, 13, 4, 1, 3, 6, 28 };

	for (int i = 0; i < len; ++i)
	{
		for (int j = 0; j < len-i-1; ++j)
		{
			if (arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}

	for (int i = 0; i < len; ++i)
	{
		cout << arr[i] << " ";
	}

}