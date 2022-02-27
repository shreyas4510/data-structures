#include<iostream>
using namespace std;

class ComplexNumber {

	private :
		int real;
		int imaginary;

	public :
		ComplexNumber( int real, int imaginary ) {
			this -> real = real;
			this -> imaginary = imaginary;
		}

		void print() {
			cout << this -> real << " + i" << this -> imaginary << endl;
		}

		void add( ComplexNumber *c2 ) {
			this -> real = this -> real + c2 -> real;
			this -> imaginary = this -> imaginary + c2 -> imaginary;
		}

		void multiply( ComplexNumber *c2 ) {
			int real = ( this -> real * c2 -> real ) - ( this -> imaginary * c2 -> imaginary );
			int imaginary = ( this -> real * c2 -> imaginary ) + ( this -> imaginary * c2 -> real );
			this -> real = real;
			this -> imaginary = imaginary;
		}
};


int main()
{
	ComplexNumber *c1 = new ComplexNumber(4, 5);
	ComplexNumber *c2 = new ComplexNumber(6, -7);
	
	// c1 -> add(c2);
	c1 -> multiply(c2);
	c1 -> print();
	return 0;
}