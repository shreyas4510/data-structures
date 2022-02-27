#include<iostream>
using namespace std;

class Fraction {
	public:
		int numerator, denomenator;
		Fraction() {}

		Fraction( int numerator, int denomenator ) {
			this -> numerator = numerator;
			this -> denomenator = denomenator;
		}

		Fraction simplify( int num, int den ) {
			int smaller = num > den ? den : num;
			int larger = num > den ? num : den;

			while( (larger % smaller) > 0 ) {
				int temp = larger % smaller;
				larger = smaller;
				smaller = temp;
			}

			Fraction fNew(( num / smaller ), ( den / smaller ));
			return fNew;
		}

		// Operator Overloading
		void operator+ ( const Fraction &f ) {
			int num = ( this -> numerator * f.denomenator ) + ( f.numerator * this -> denomenator );
			int den = this -> denomenator * f.denomenator;
			Fraction fTemp = simplify( num, den );
			cout << "Addition operator overloaded : " << fTemp.numerator << " / " << fTemp.denomenator << endl;
		}

		void operator* ( Fraction f ) {
			int num = this -> numerator * f.numerator;
			int den = this -> denomenator * f.denomenator;
			Fraction fTemp = simplify( num, den );
			cout << "Multiplication operator overloaded : " << fTemp.numerator << " / " << fTemp.denomenator << endl;
		}

		Fraction& operator++() {
			 this -> numerator = this -> numerator + this -> denomenator;
			 *this = simplify( this -> numerator, this -> denomenator );
			 // cout << "Pre-increment operator overloaded : " << fTemp.numerator << " / " << fTemp.denomenator;
			 return *this;
		}

		Fraction operator++(int) {
			Fraction fTemp = simplify(this -> numerator, this -> denomenator);;

			this -> numerator = this -> numerator + this -> denomenator;
			*this = simplify( this -> numerator, this -> denomenator );
			 
			return fTemp;
		}

		Fraction& operator+=( Fraction f ) {
			this -> numerator = ( this -> numerator * f.denomenator ) + ( f.numerator * this -> denomenator );
			this -> denomenator = ( this -> denomenator * f.denomenator );
			*this = simplify( this -> numerator, this -> denomenator );
			return *this;
		}
};

int main() {
	Fraction f( 10, 2 );
	Fraction f1( 15, 4 );

	// Multiplication Operator Overloaded
	f * f1;

	// Addition Operator Overloaded
	f + f1;

	// Pre-increment Operator Overloaded
	Fraction PreInc = ++(++(++f));
	cout << "Pre-increment operator overloaded : " << PreInc.numerator << " / " << PreInc.denomenator << endl;
	cout << "Same Object Incremented : " << f.numerator << " / " << f.denomenator << endl;

	// Post-increment Operator Overloading
	cout << f++.numerator << " / " << f++.denomenator << endl;
	cout << f.numerator << " / " << f.denomenator << endl;

	(f+=f1)+=f1;
	cout << f.numerator << " / " << f.denomenator << endl;

}