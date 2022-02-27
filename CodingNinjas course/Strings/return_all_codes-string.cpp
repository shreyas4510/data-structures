#include<iostream>
#include<string>
#include<vector>
using namespace std;

void returnAllCodes(string input, vector<string>& output, string temp) {
	if ( input.size() == 0 ) {
		output.push_back(temp);
		return;
	}
	
	temp += (char)(96 + ((int)input[0] - '0'));
	returnAllCodes(input.substr(1,input.size()), output, temp);

	if ( input.size() > 1 && stoi(input.substr(0,2)) < 27) {
		temp = temp.substr(0, temp.size()-1) + (char)(96 + stoi(input.substr(0,2)));
		returnAllCodes(input.substr(2,input.size()), output, temp);	
	}
}

int main() {
	string input = "1123";
	vector<string> output;
	returnAllCodes(input, output, "");
	for ( int i=0; i<output.size(); i++ ) {
		cout << output[i] << endl;
	}
}
