#include<iostream>
#include<string>
using namespace std;

class Student {
	const int age;
	const string name;

	public :

		Student( string name, int age ) : age(age), name(name) {}

		void display() {
			cout << this -> name << " " << this -> age << endl;
		}
};

int main()
{
	Student *s = new Student("Shreyas", 15);
	s -> display();
	return 0;
}