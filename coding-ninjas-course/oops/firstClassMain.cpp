#include <iostream>
#include "firstClass.cpp"
using namespace std;

int main() {
	Student s;
	// s.age = 10;
	// s.name = "Shreyas";

	cout << "Name : " << s.getName() << "  Age : " << s.getAge() << endl;

	Student *s1 = new Student(15);
	// s1 -> name = "Rahul";
	// s1 -> age = 50;

	// cout << "Before Setters : " << endl;
	// cout << "Name : " << s1 -> getName() << " Age : " << s1 -> getAge() << endl;

	s1 -> display();

	s1 -> setAge(24);
	s1 -> setName("Shreyas");

	s1 -> display();

	// cout << "After Setters : " << endl;
	// cout << "Name : " << s1 -> getName() << " Age : " << s1 -> getAge() << endl;


	// Copy Constructor
	Student *s2 = new Student(s);
	cout << "\nCopy Constructor : ";
	s2 -> display();

	cout << endl;
	Student s3(s);
	s3.display();

	Student s4(*s1);
	s4.display();

	delete s1;
	delete s2;

}