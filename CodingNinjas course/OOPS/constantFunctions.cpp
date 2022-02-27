#include <iostream>
#include <string.h>
using namespace std;

class Student {
	int age = 10;
	string name = "Shreyas";

	public :

		Student() {}

		Student( string name, int age ) {
			this -> name = name;
			this -> age = age;
		}

		void display() const {
			cout << name << "  " << age << endl;
		}
};

int main() {
	Student *s1 = new Student( "Rahul", 24 );
	s1 -> display();

	const Student *s2 = new Student();
	s2 -> display();
}