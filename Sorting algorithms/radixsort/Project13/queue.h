#ifndef QUEUE_H
#define QUEUE_H
#define SIZE 100000
using namespace std;

class queue {
	int array[SIZE]{};
	int first = 0;
	int last = -1;
	int queueSize = 0;

public:

	void push(int x) {
		if (first == -1) {
			first++;
			last++;
			array[last] = x;
			++queueSize;
		}
		else if (queueSize == SIZE) {
			cout << "Queue is FULL" << endl;
		}
		else {
			last++;
			array[last] = x;
			++queueSize;
		}
	}
	int front() {
		if (queueSize != 0)
			return array[first];
	}
	int pop() {
		int toDelete = -1;
		if (queueSize == 0) {
			cout << "Queue is EMPTY" << endl;
		}
		else {
			toDelete = array[first];
			first++;
			--queueSize;
		}
		return toDelete;
	}
	bool isEmpty() {
		return (queueSize == 0);
	}
	int size() {
		return queueSize;
	}
	queue& operator=(const queue *newQueue) {
		for (int i = 0; i < newQueue->queueSize; i++) {
			array[i] = newQueue->array[i];
		}
		first = newQueue->first;
		last = newQueue->last;
		queueSize = newQueue->queueSize;
		return *this;
	}
};
#endif
