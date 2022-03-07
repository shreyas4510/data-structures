#include <iostream>
#include <stack>
using namespace std;

void reverseStack( stack<int> *s, stack<int> *s1 ) {
	if ( s -> size() == 1 ) {
		s1 -> push( s -> top() );
		s -> pop();
		return;
	}

	int temp = s -> top();
	s -> pop();
	reverseStack(s, s1);
	s1 -> push(temp);
}

int main()
{
	stack<int> *s = new stack<int>();
	stack<int> *s1 = new stack<int>();
	int n;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int temp;
		cin >> temp;
		s -> push(temp);
	}

	reverseStack(s, s1);

	while( !s1 -> empty() ) {
		s -> push(s1 -> top());
		s1 -> pop();
	}
	
	while( !s -> empty() ) {
		cout << s -> top() << " ";
		s -> pop();
	}

	return 0;
}