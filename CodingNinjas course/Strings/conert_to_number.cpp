#include<iostream>
#include<string>
#include<typeinfo>
using namespace std;


// First Approach
//int convertToInteger( string s ) {
//	if ( s.length() == 1 ) {
//		return stoi(s);
//	}
//	
//	int number = s[0] - '0';
//	string numOfZeros( s.length()-1 , '0');
//	int cal = (number * stoi("1" + numOfZeros)) + convertToInteger(s.substr(1));
//	return cal;
//}

int convertToInteger( string s ) {
	if ( s.length() == 1 ) {
		return stoi(s);
	}
	
	int number = s[s.length() - 1] - '0';
	int cal = convertToInteger(s.substr(0, s.length() - 1)) * 10 + number;
	return cal;
}

int main() {
	string str = "12345686";
	cout << convertToInteger(str);
}
