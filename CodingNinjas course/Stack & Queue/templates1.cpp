#include <iostream>
#include <string>
using namespace std;

template < typename temp, typename temp1 >
class Pair {
	temp x;
	temp1 y;

	public :
		setX( temp x ) {
			this -> x = x;
		}

		setY( temp1 y ) {
			this -> y = y;
		}

		temp getX() {
			return this -> x;
		}
		
		temp1 getY() {
			return this -> y;
		}
};

int main()
{
	Pair<int, int> *obj = new Pair<int, int>();
	obj -> setX(1);
	obj -> setY(2);
	cout << obj -> getX() << endl;
	cout << obj -> getY() << endl;
	cout << endl;

	Pair<string, int> *obj1 = new Pair<string, int>();
	obj1 -> setX("Shreyas");
	obj1 -> setY(24);
	cout << obj1 -> getX() << endl;
	cout << obj1 -> getY() << endl;
	cout << endl;

	Pair<Pair<string, int>, Pair<string, int>> *obj2 = new Pair<Pair<string, int>, Pair<string, int>>();

	Pair<string, int> p1;
	p1.setX("Shreyas");
	p1.setY(24);
	obj2 -> setX(p1);

	p1.setX("Rahul");
	p1.setY(25);
	obj2 -> setY(p1);

	cout << (obj2 -> getX()).getX() << endl;
	cout << (obj2 -> getX()).getY() << endl;
	cout << (obj2 -> getY()).getX() << endl;
	cout << (obj2 -> getY()).getY() << endl;

	return 0;
}