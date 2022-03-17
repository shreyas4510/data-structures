#include<iostream>
#include<string>
using namespace std;

void returnPermutations(string input, string placeholder) {
	if(input.length() == 1) {
		cout << placeholder + input << endl;
		return;
	}
	
	for ( int i=0; i<input.length(); i++ ) {
		string temp = placeholder + input[i], tempInput = input;
		tempInput = tempInput.erase(i,1);
		returnPermutations(tempInput, temp);
	}
}

int main(){
	string str = "adg";
	returnPermutations(str, "");
}
