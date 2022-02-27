#include<iostream>
using namespace std;

class DynamicArray {
	int *data;
	int nextIntex;
	int capacity;

	public:
		DynamicArray() {
			data = new int[5];
			nextIntex = 0;
			capacity = 5;
		}

		DynamicArray( const DynamicArray &d ) {
			this -> nextIntex = d.nextIntex;
			this -> capacity = d.capacity;

			this -> data = new int[ d.capacity ];
			for (int i = 0; i < d.nextIntex; i++){
				this -> data[i] = d.data[i];
			}
		}

		void operator=(DynamicArray d) {
			this -> nextIntex = d.nextIntex;
			this -> capacity = d.capacity;

			this -> data = new int[ d.capacity ];
			for (int i = 0; i < d.nextIntex; i++){
				this -> data[i] = d.data[i];
			}	
		}

		push_back( int item ) {
			if ( nextIntex == capacity ) {
				
				int *tempArr = new int[2 * capacity];
				for (int i = 0; i < nextIntex; i++)
				{
					tempArr[i] = data[i];
				}
				capacity *= 2;
			}
			data[ nextIntex ] = item;
			nextIntex++;
		}

		print() {
			cout << "[ ";
			for (int i = 0; i < this -> nextIntex; ++i) {
				cout << this -> data[i] << " ";
			}
			cout << "]" << endl;
		}

		void add( int index, int item ) {
			if ( index < nextIntex ) {
				data[index] = item;
			}
			else if ( index == nextIntex ) {
				push_back(item);
			}
			else {
				return;
			}
		}
};

int main() {
	DynamicArray da;
	da.push_back(1);
	da.push_back(2);
	da.push_back(3);
	da.push_back(4);
	da.push_back(5);
	da.push_back(6);
	da.push_back(7);
	da.push_back(8);
	da.push_back(9);

	da.add( 0, 10 );
	da.add( 9, 15 );

	da.print();

	DynamicArray da1(da);
	da1.print();

	DynamicArray da2;
	da2 = da;
	da.add(9, 12);
	da2.print();
}