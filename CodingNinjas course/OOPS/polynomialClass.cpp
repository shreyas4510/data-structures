#include<iostream>
using namespace std;

class Polynomial {
	int *coefficient;
	int size, capacity;

	public :
		Polynomial() {
			coefficient = new int[10]{ 0 };
			size = 0;
			capacity = 10;
		}

		takeInput( int count ) {
			int *temp = new int[count];
			for (int i = 0; i < count; ++i) {
				cin >> temp[i];
			}

			for (int i = 0; i < count; ++i) {
				if ( temp[i] > this -> capacity ) {
					int *newTemp = new int[temp[i]+1];
					for (int j = 0; j < this -> size; ++j) {
						newTemp[j] = this -> coefficient[j];
					}
					this -> coefficient = newTemp;
				}

				cin >> this -> coefficient[temp[i]];
				this -> size = temp[i]+1;
			}			
		}

		void operator+ ( Polynomial p ) {
			int largerSize = this -> size > p.size ? this -> size : p.size;
			for (int i = 0; i < largerSize; ++i) {
				int coff = 0;
				if ( i <= this -> size && i <= p.size ) {
					coff = this -> coefficient[i] + p.coefficient[i];
				}
				else if ( i <= this -> size && i > p.size ) {
					coff = this -> coefficient[i];
				}
				else if ( i > this -> size && i <= p.size ) {
					coff = p.coefficient[i];
				}

				if ( coff != 0 ) {
					cout << coff << "x" << i << " ";
				}
			}
			cout << endl;
		}

		void operator- ( Polynomial p ) {
			int largerSize = this -> size > p.size ? this -> size : p.size;
			for (int i = 0; i < largerSize; ++i) {
				int coff = 0;
				if ( i <= this -> size && i <= p.size ) {
					coff = this -> coefficient[i] - p.coefficient[i];
				}
				else if ( i <= this -> size && i > p.size ) {
					coff = this -> coefficient[i];
				}
				else if ( i > this -> size && i <= p.size ) {
					coff = -p.coefficient[i];
				}

				if ( coff != 0 ) {
					cout << coff << "x" << i << " ";
				}
			}
			cout << endl;
		}

		void operator* ( Polynomial p ) {
			int largerSize = this -> size > p.size ? this -> size : p.size;
			int *temp = new int[largerSize+1]{ 0 };
			int max = largerSize+1;
			for (int i = 0; i < this -> size; ++i) {
				for (int j = 0; j < p.size; ++j) {
					if ( this -> coefficient[i] != 0 && p.coefficient[j] != 0 )
					{
						int power = i+j;
						if ( power > largerSize+1 ) {
							int *newTemp = new int[power+1]{ 0 };
							for (int j = 0; j <= largerSize+1; ++j) {
								newTemp[j] = temp[j];
							}
							temp = newTemp;
							max = power+1;
						}

						int coff = this -> coefficient[i] * p.coefficient[j];
						temp[power] = temp[power] + coff;
					}
				}
			}
			
			for (int i = 0; i < max; ++i) {
				if ( temp[i] != 0 ) {
					cout << temp[i] << "x" << i << " ";
				}
			}
		}

		void operator= ( Polynomial p ) {
			int *temp = new int[p.size]{ 0 };
			for (int i = 0; i <= p.size; ++i) {
				temp[i] = p.coefficient[i];
			}
			this -> coefficient = temp;
			
			for (int i = 0; i < p.size; ++i) {
				if ( this -> coefficient[i] != 0 ) {
					cout << this -> coefficient[i] << "x" << i << " ";
				}
			}
		}
};

int main()
{
	
	int in1;
	cin >> in1;
	Polynomial *p = new Polynomial();
	p -> takeInput(in1);

	cin >> in1;
	Polynomial *p1 = new Polynomial();
	p1 -> takeInput(in1);

	int c;
	cin >> c;

	switch( c ) {
		case 1:
			*p + *p1;
			break;
		case 2:
			*p - *p1;
			break;
		case 3:
			(*p) * (*p1);
			break;
		case 4:
			*p = *p1;
			break;
		default:
			break;
	}

	return 0;
}