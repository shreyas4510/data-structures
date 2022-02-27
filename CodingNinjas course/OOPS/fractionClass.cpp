#include<iostream>
using namespace std;

class Fraction {

	private :
		int numerator, denomenator;

	public : 
		Fraction( int numerator, int denomenator ) {
			this -> numerator = numerator;
			this -> denomenator = denomenator;
		}

		void printFraction() {
			cout << this -> numerator << " / " << this -> denomenator << endl;
		}

		void simplify( int numerator, int denomenator ) {
			int smaller = ( numerator > denomenator ? denomenator : numerator );
			int large = ( numerator > denomenator ? numerator : denomenator );

			while((large % smaller) > 0 ) {
				int temp = smaller;
				smaller = large % temp;
				large = temp;
			}

			this -> numerator = numerator / smaller;
			this -> denomenator = denomenator / smaller;
		}

		void addFraction( Fraction *f2 ) {
			int commonDenominator = this -> denomenator * f2 -> denomenator;
			int commonNumerator = ( this -> numerator * f2 -> denomenator ) + ( f2 -> numerator * this -> denomenator );
			simplify(commonNumerator, commonDenominator);
			cout << "Addition of fraction is : " ;
		}

		void multiplyFraction( Fraction *f2 ) {
			int commonNumerator = this -> numerator * f2 -> numerator;
			int commonDenominator = this -> denomenator * f2 -> denomenator;
			simplify(commonNumerator, commonDenominator);
			cout << "Multiplication of fraction is : " ;
		}

		void resetValues( int numerator, int denomenator ) {
			this -> numerator = numerator;
			this -> denomenator = denomenator;
		}
};

int main() {
	Fraction *f1 = new Fraction(10, 5);
	Fraction *f2 = new Fraction(15, 20);

	f1 -> addFraction(f2);
	f1 -> printFraction();

	f1 -> resetValues(10, 5);
	f1 -> multiplyFraction(f2);
	f1 -> printFraction();

	delete f1;
	delete f2;
}