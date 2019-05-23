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

	bool dequeue(int &elem) {
		if(head == tail) {
			cout << "no elem!" << endl;
			return false;
		}
		elem =  m_array[head];
		head++;
		cout << "dequeue: " << elem << endl;
	}

	void create_loop_queue(int size) {
		loop_array = new int[size];
		loop_head = 0;
		loop_tail = 0;
		loop_capacity = size;
	}

	void destroy_loop_queue() {
		delete[] loop_array;
	}

	bool loop_enqueue(int elem) {
		if((loop_tail + 1) % loop_capacity == loop_head) {
			cout << "loop queue is full!" << endl;
			return false;
		}
		loop_array[loop_tail] = elem;
		loop_tail = (loop_tail + 1) % loop_capacity;
		return true;
	}

	bool loop_dequeue(int &elem) {
		if(loop_head == loop_tail) {
			cout << "loop queue is empty!" << endl;
			return false;
		}
		elem = loop_array[loop_head];
		loop_head = (loop_head + 1) % loop_capacity;
		return true;
	}

private:
	int *m_array;
	int head;
	int tail;
	int capacity;

	int *loop_array;
	int loop_head;
	int loop_tail;
	int loop_capacity;
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

	int devalue = 0;
	aq.dequeue(devalue);
	aq.dequeue(devalue);
	aq.dequeue(devalue);
	aq.dequeue(devalue);
	aq.dequeue(devalue);
	aq.dequeue(devalue);

	aq.enqueue(5);
	aq.dequeue(devalue);

	aq.create_loop_queue(6);
	aq.loop_enqueue(1);
	aq.loop_enqueue(2);
	//aq.loop_enqueue(3);
	aq.loop_dequeue(devalue);
	cout << "loop:" << devalue << endl;
	aq.loop_dequeue(devalue);
	cout << "loop:" << devalue << endl;
	aq.loop_dequeue(devalue);
	cout << "loop:" << devalue << endl;
}
#endif
