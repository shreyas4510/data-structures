#include <string>
using namespace std;

class Student
{
	private:
		int age;
		string name;
	
	public:

		~Student() {
			cout << "Destructor Called" << endl;
		}

		Student() {
			name = "testConstructor";
			age = 10; 
		}

		Student(int age) {
			name = "Parametrized Constructor";
			this -> age = age;
		}

		getAge() {
			return age;
		}

		string getName() {
			return name;
		}

		setAge( int age ) {
			this -> age = age;
		}

		setName( string name ) {
			this -> name = name;
		}

		display() {
			cout << "Name : " << this -> name << "Age : " << this -> age << endl;
		}
};