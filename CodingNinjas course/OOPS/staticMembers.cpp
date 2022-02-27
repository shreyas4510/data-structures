#include <iostream>
#include <string>
using namespace std;

class Student {

	public:
		string name;
		int rollNumber, age;
		static int totalStudents;

		Student( string name, int age, int rollNumber ) {
			this -> name = name;
			this -> age = age;
			this -> rollNumber = rollNumber;

			totalStudents ++;
		}

		display() {
			cout << this -> name << " " << this -> age << " " << this -> rollNumber << endl;
		}

		static getTotalStudents() {
			return totalStudents;
		}
};
int Student :: totalStudents = 0;

int main()
{
	Student s( "Shreyas", 24, 1 );
	s.display();

	Student s1( "Rahul", 20, 2 );
	s1.display();

	cout << Student :: getTotalStudents(); 
	return 0;
}