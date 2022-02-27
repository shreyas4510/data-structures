#include<iostream>
#include<string.h>
using namespace std;

class CopyConstructor {
	private :
		char *name;
		int age;

	public :
		CopyConstructor( char *name, int age ) {
			this -> name = name;
			this -> age = age;
		}

		// void setName( string name ) {
		// 	this -> name = name;
		// }

		// void setAge( int age ) {
		// 	this -> age = age;
		// }

		// string getName() {
		// 	return this -> name;
		// }

		// int getAge() {
		// 	return this -> age;
		// }

		showDetails() { 
			cout << this -> name << " " << this -> age << endl;
		}
};

int main()
{

	char name[] = "Shreyas";
	CopyConstructor cc(name, 24);
	// cc.setName( "Shreyas" );
	// cc.setAge(24);
	// cout << "First Object : " << cc.getName() << "  " << cc.getAge() << endl;

	cout << "//////   Shallow Copy ///////" << endl;

	cc.showDetails();
	name[0] = 'R';
	CopyConstructor cc1(name, 50);

	cc1.showDetails();
	cc.showDetails();

	// CopyConstructor cc1 = cc;
	// cc1.setName("Rahul");
	// cc1.setAge(50);

	// cout << "Second Object : " << cc1.getName() << "  " << cc1.getAge() << endl;
	// cout << "Shallow Copy : " << cc.getName() << "  " << cc.getAge() << endl;

	cout << "////// Deep Copy ///////" << endl;



	return 0;
}