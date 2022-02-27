template <typename type>
class DynamicQueue {
	type *data;
	int size, fIndex, lIndex, capacity;

	public :
		DynamicQueue( int capacity ) {
			this -> fIndex = 0;
			this -> lIndex = 0;
			this -> size = 0;
			this -> capacity = capacity;
			this -> data = new type[capacity];
		}

		int getSize() {
			return this -> size;
		}

		int isEmpty() {
			return this -> size == 0;
		}

		type front() {
			if (this -> size == 0) {
				return 0;
			}
			return this -> data[ fIndex ];
		}

		void enqueue( type data ) {
			if (this -> size == capacity) {
				type *newData = new type[2 * capacity];
				for (int i = 0; i < capacity; ++i) {
					newData[i] = this -> data[fIndex];
					fIndex = (fIndex + 1) % capacity;
				}
				delete [] this -> data;
				this -> data = newData;
				fIndex = 0;
				lIndex = capacity;
				capacity = 2 * capacity;
			}

			this -> data[lIndex] = data;
			lIndex = (lIndex + 1) % capacity;
			size++;
		}

		void dequeue() {
			if (this -> size == 0) {
				std::cout << "Queue Empty" << std::endl;
				return;
			}
			fIndex = (fIndex + 1) % capacity;
			size--;
		}
};