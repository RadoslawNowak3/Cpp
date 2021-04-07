#ifndef QUEUE_H
#define QUEUE_H
#define SIZE 100000
using namespace std;

class queue {
	int array[SIZE]{};
	int first, last = -1;
	int size = 0;

public:

	void push(int x) {
		if (first == -1) {
			first++;
			last++;
			array[last] = x;
			++size;
		}
		else if (size == SIZE) {
			std::cout << "Queue is FULL" << endl;
		}
		else {
			last++;
			array[last] = x;
			++size;
		}
	}
	int front() {
		if (size != 0)
			return array[first];
	}
	int pop() {
		int toDelete = -1;
		if (size == 0) {
			cout << "Queue is EMPTY" << endl;
		}
		else {
			toDelete = array[first];
			first++;
			--size;
		}
		return toDelete;
	}
	bool isEmpty() {
		return (size == 0);
	}
	int size() {
		return size;
	}
	queue& operator=(const queue *newQueue) {
		for (int i = 0; i < newQueue->size; i++) {
			array[i] = newQueue->array[i];
		}
		first = newQueue->first;
		last = newQueue->last;
		size = newQueue->size;
		return *this;
	}
};
#endif 
