#include <iostream>
#include "debug.h"

using namespace std;
class ArrayQueue {

public:
	ArrayQueue(int size) {
		m_array = new int[size];
		head = 0;
		tail = 0;
		capacity = size;
	}
	
	~ArrayQueue() {
		delete[] m_array;
	}
	
	bool enqueue(int elem) {
		//if(tail == capacity) {
		//	cout << "full!" << endl;
		//	return false;
		//}
		if(tail == capacity) {
			if(head == 0) {
				//queue is really full
				return false;
			}
			// or copy the data
			cout << "lets move data!!!" << endl;
			for(int i=head;head<tail;i++) {
				m_array[i-head] = m_array[i];
			}
			tail = tail-head;
			head = 0;
		}
		cout << "enqueue: " << elem << endl;
		m_array[tail] = elem;
		tail++;
		return true;
	}
	
	int dequeue() {
		if(head == tail) {
			cout << "no elem!" << endl;
			return -1;
		}
		int temp =  m_array[head];
		head++;
		cout << "dequeue: " << temp << endl;
		return temp;
	}
	
private:
	int *m_array;
	int head;
	int tail;
	int capacity;
};

#if ARRAY_QUEUE
int main() {
	ArrayQueue aq(6);
	aq.enqueue(1);
	aq.enqueue(2);
	aq.enqueue(3);
	aq.enqueue(4);
	aq.enqueue(5);
	aq.enqueue(6);
	
	aq.dequeue();
	aq.dequeue();
	aq.dequeue();
	aq.dequeue();
	aq.dequeue();
	aq.dequeue();
	
	aq.enqueue(5);
	aq.dequeue();
}
#endif
