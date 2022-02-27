#include<iostream>
#include<string>
using namespace std;

void printAllCodes(string input, string output) {
	if( input.length() == 0 ) {
		cout << output << endl;
		return;
	}
	
	output +=(char)(96 + ((int)input[0] - '0'));
	printAllCodes(input.substr(1, input.size()), output);
	
	if ( input.length() > 1 && stoi(input.substr(0, 2)) < 27) {
		output = output.substr(0, output.size()-1) + (char)(96 + stoi(input.substr(0, 2)));
		printAllCodes(input.substr(2, input.size()), output);		
	}
}

int main() {
	string input = "1123";
	printAllCodes(input, "");
}
