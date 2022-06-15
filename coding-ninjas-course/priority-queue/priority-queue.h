#include <bits/stdc++.h>
using namespace std;

class priorityQueue {
	vector<int> queue;

	void swapElements( vector<int>& arr, int first, int second ) {
		int temp = arr.at(first);
		arr.at(first) = arr.at(second);
		arr.at(second) = temp;
	}

	public:
		bool isEmpty() {
			return queue.size() == 0;
		}

		int getMin() {
			if (isEmpty())
				return 0;

			return queue.at(0);
		}

		int getSize() {
			return queue.size();
		}

		void insert(int item) {
			queue.push_back(item);
			int size = queue.size();

			int i = size-1;
			while((queue.at( (i - 1) / 2 ) > queue.at(i)) && i > 0) {
				int temp = queue.at((i - 1) / 2);
				queue.at((i - 1) / 2) = queue.at(i);
				queue.at(i) = temp;
				i = (i - 1) / 2;
			}
		}

		void removeMin() {

			int size = queue.size();

			if (!size) {
				cout << "Queue is empty";
				return;
			}

			if (size == 1) {
				queue.pop_back();
				return;
			}

			swapElements(queue, 0, size-1);
			queue.pop_back();

			int i = 0, ri = 1, li = 2;
			size = queue.size();
			while( (ri < size && queue.at(i) > queue.at(ri)) || (li < size && queue.at(i) > queue.at(li)) ) {
				int ele = queue.at(i);
				if ( ri < size ) {
					if ( queue.at(ri) < queue.at(li) && queue.at(ri) < ele ) {
						swapElements(queue, i, ri);
						i = ri;
					} else if ( queue.at(li) < queue.at(ri) && queue.at(li) < ele ) {
						swapElements(queue, i, li);
						i = li;
					}
				} else if ( li < size ) {
					swapElements(queue, i, li);
					i = li;
				}

				ri = ( 2 * i ) + 1; 
				li = ( 2 * i ) + 2;
			}
		}

		void print() {
			
			int size = queue.size();
			
			if (!size) {
				cout << "Queue is empty!" << endl;
				return;
			}

			for (int i = 0; i < size; ++i) {
				cout << queue.at(i) << " : ";
				if ( ( 2*i+1 ) < size)
					cout << "LC : " << queue.at(2*i+1) << ", ";
				if ( ( 2*i+2 ) < size)
					cout << "RC : " << queue.at(2*i+2) << ", ";				
				cout << endl;
			}
		}
};

