template <typename type>
class Node {
	public :
		type data;
		Node *next;

		Node( type data ) {
			this -> data = data;
			this -> next = NULL;
		}
};

template <typename type>
class Queue {
	Node<type> *head, *tail;
	int size;

	public :
		Queue() {
			this -> head = NULL;
			this -> tail = NULL;
			this -> size = 0;
		}

		int getSize() {
			return size;
		}

		bool isEmpty() {
			return size == 0;
		}

		type front() {
			if (size == 0) {
				std :: cout << "Queue Empty" << std :: endl;
				return 0;
			}
			return head -> data;
		}

		enqueue( type data ) {
			Node<type> *n = new Node<type>( data );
			if (head == NULL) {
				head = n;
				tail = n;
			}
			else {
				tail -> next = n;
				tail = tail -> next;
			}
			size++;
		}

		void dequeue() {
			if (size == 0) {
				std :: cout << "Queue Empty" << std :: endl;
				return;
			}
			Node<type> *temp = head;
			head = head -> next;
			delete temp;
			size--;
		}
};