#include <iostream>
using namespace std;

template< typename temp >

class Pair {
	temp x, y;

	public :
		setX( temp value ) {
			this -> x = value;
		}

		setY( temp value ) {
			this -> y = value;
		}

		temp getX() {
			return this -> x;			
		}

		temp getY() {
			return this -> y;
		}
};

int main()
{
	Pair<int> obj;
	obj.setX(1);
	obj.setY(2);
	cout << obj.getX() << endl;
	cout << obj.getY() << endl;

	Pair<int> *obj1 = new Pair<int>();
	obj1 -> setX(3);
	obj1 -> setY(4);
	cout << obj1 -> getX() << endl;
	cout << obj1 -> getY() << endl;

	return 0;
}