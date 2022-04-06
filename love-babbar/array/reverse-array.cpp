#include <iostream>
#include <string>
using namespace std;

string reverseWord(string str){
		if (!str.size())
			return "";
    	return reverseWord(str.substr(1, str.size())) + str[0];
}

int main() {
	string str;
	cin >> str;
	cout << reverseWord(str);
	return 0;
}