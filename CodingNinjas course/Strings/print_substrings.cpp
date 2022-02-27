#include<iostream>
using namespace std;

void printSubstrings(string input, string output) {
	if ( input == "" ) {
		cout << output << endl;
		return;
	}
	
	printSubstrings(input.substr(1), output);
	printSubstrings(input.substr(1), output + input[0] );	
}

int main() {
	string str = "abcd";
	printSubstrings(str, "");
}
