//������
#include<iostream>
using namespace std;

class arrayQueue {
private:
	int* arr;
	int capacity;
	int frontIndex;
	int rearIndex;
	int size;

public:
	arrayQueue(int capacity) {
		this->capacity = capacity;
		arr = new int[capacity]; //���� ����
		frontIndex = rearIndex = 0;
		size = 0;
	}

	bool empty() {
		if (size == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	int Size() {
		return size;
	}

	int front() {
		if (empty()) {
			return -1;
		}
		return arr[frontIndex];
	} //ť�� ���Լ����̱⿡ rearIndex�� �����ϴ� �Լ��� ������ �ʾ���

	void enqueue(int data) {
		if (Size() == capacity) {
			return;
		}
		arr[rearIndex] = data;
		rearIndex = (rearIndex + 1) % capacity;
		size++;
	}

	void dequeue() {
		if (empty()) {
			return;
		}
		frontIndex = (frontIndex + 1) % capacity;
		size--;
	}
};

int main() {
	int T = 0, capacity = 0;
	cin >> T;
	cin >> capacity;
	arrayQueue Queue(capacity);
	string str;
	while (T--) {
		cin >> str;
		if (str == "emtpy") {
			if (Queue.empty()) {
				cout << "True" << endl;
			}
			else {
				cout << "False" << endl;
			}
		}

		else if (str == "size") {
			cout << Queue.Size() << endl;
		}

		else if (str == "front") {
			cout << Queue.front() << endl;
		}

		else if (str == "enqueue") {
			int data;
			cin >> data;
			Queue.enqueue(data);
		}

		else if (str == "dequeue") {
			Queue.dequeue();
		}
	}
	return 0;
}