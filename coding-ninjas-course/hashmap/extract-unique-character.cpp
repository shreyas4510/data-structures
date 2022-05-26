#include<iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	string input;
	cin >> input;
	map<char, bool> ourmap;

	for (int i = 0; i < input.size(); ++i) {
		ourmap[input[i]] = true;
	}

	map<char, bool> :: iterator it;
	for (it = ourmap.begin(); it != ourmap.end(); ++it) {
		cout << it -> first;
	}
	cout << endl;
}