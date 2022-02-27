#include<iostream>
using namespace std;

bool checkString( string str ){
	if (str.length() == 0) {
		return true;
	}
	
	if (str[0] != 'a' && str[0] != 'b'){
		return false;
	}
	
	if (str[0] == 'a' && str[1] == 'b' && str[1] != str[2]) {
		return false;
	}
				
	bool status = checkString(str.substr(1));
	return status;	
}

int main(){
	string str;
	cin >> str;

	if( str[0] == 'a' ) {
		cout << (checkString(str) ? "true" : "false");
	}
	else {
		cout << "false";
	}
}
