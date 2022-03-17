#include <iostream>
#include <string.h>
using namespace std;


class Student {
	private :
		int age;

	public:
		char *name;

		Student( const Student &s ) {
			this -> age = s.age;
			this -> name = new char[strlen( s.name )];
			strcpy(this -> name, s.name);
		}

		Student( int age, char *name ) {
			this -> age = age;

			// Shallow copy
			this -> name = name;

			// Deep Copy
			// this -> name = new char[ strlen(name) + 1 ];
			// strcpy( this -> name, name );
		}	

		void display() {
			cout << "Name : " << this -> name << "  Age : " << this -> age << endl; 
		}
};

int main()
{

	char name[] = "Shreyas";
	Student s1( 24, name );
	s1.display();

	// Shallow And Deep Copy
	// name[0] = 'R';
	// Student s2( 20, name );

	// s2.display();
	// s1.display();

	// CopyConstructors
	Student s2(s1);
	s2.name[0] = 'R';

	s2.display();
	s1.display();

	return 0;
}