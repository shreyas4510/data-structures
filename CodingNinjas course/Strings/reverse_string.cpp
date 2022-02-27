#include <iostream>
#include <string>
using namespace std;

string reverseString(string str, int i, int j) {
	if ( i > j ) {
		return str;
	}
	
	char temp = str[i];
	str[i] = str[j];
	str[j] = temp;
	str = reverseString(str, ++i, --j);
	return str;
}

int main() {
	string str;
	cin >> str;
	
	int i=0, j=str.length()-1;
	cout << reverseString(str, 0, str.length() - 1);
	
//	while ( i < j ) {
//		char temp = str[i];
//		str[i] = str[j];
//		str[j] = temp;
//		
//		i++;
//		j--;
//	}
//	
//	cout << str << " " << str.length();
}
