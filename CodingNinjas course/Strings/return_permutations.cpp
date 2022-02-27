#include<iostream>
#include<string>
#include<vector>
using namespace std;

void returnPermutations(string input, string placeholder, vector<string>& output) {
	if(input.length() == 1) {
		output.push_back(placeholder + input);
		return;
	}
	
	for ( int i=0; i<input.length(); i++ ) {
		string temp = placeholder + input[i], tempInput = input;
		tempInput = tempInput.erase(i,1);
		returnPermutations(tempInput, temp, output);
	}
}

int main(){
	string str = "abc";
	vector<string> output;
	returnPermutations(str, "", output);
	for (int i=0; i<output.size(); i++) {
		cout << output[i] << endl;
	}
}
