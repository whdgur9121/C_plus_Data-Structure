#include<iostream>
using namespace std;;

struct node {
	int data;
	node* next;
};

class listQueue {
private :
	node* frontNode;
	node* rearNode;
	int n;

public:
	listQueue() {
		frontNode = NULL;
		rearNode = NULL;
		n = 0;
	}

	bool empty() {
		if (n == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	int size() {
		return n;
	}

	int front() {
		if (empty()) {
			return -1;
		}
		return frontNode->data;
	}

	void enqueue(int data) {
		node* newNode = new node;
		newNode->data = data;
		newNode->next = NULL;
		if (empty()) {
			frontNode = rearNode = newNode;
		}
		else {
			rearNode->next = newNode;
			rearNode = newNode;
		}
		n++;
	}

	void dequeue() {
		if (empty()) {
			return;
		}
		node* curNode = frontNode;
		if (size() == 1) {
			frontNode = rearNode = NULL;
		}
		else {
			frontNode = frontNode->next;
		}
		delete curNode;
		n--;
	}
};

int main() {
	int T = 0, capacity = 0;
	cin >> T;
	listQueue Queue;
	string str;
	while (T--) {
		cin >> str;
		if (str == "empty") {
			if (Queue.empty()) {
				cout << "True" << endl;
			}
			else {
				cout << "False" << endl;
			}
		}

		else if (str == "size") {
			cout << Queue.size() << endl;
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