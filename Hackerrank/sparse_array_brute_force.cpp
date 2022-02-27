#include<iostream>
using namespace std;

int main()
{
	vector<string> strings = { "aba", "baba", "aba", "xzxb"};
	vector<string> queries = { "aba", "xzxb", "ab" };
	

	vector<int> ans;

	for (int i = 0; i < queries.size(); i++)
	{
		int count = 0;
		for (int j = 0; j < strings.size() ; i++)
		{
			if ( queries[i] == strings[j] )
			{
				count++;
			}
		}
		ans.push_back(count);
	}

	return 0;
}