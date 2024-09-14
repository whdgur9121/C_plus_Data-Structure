//강종혁
#include<iostream>
using namespace std;

struct node {
	int data;
	node* next;
};

class ListStack {
private:
	node* topNode;
	int listSize;

public:
	ListStack() { //생성자
		topNode = NULL;
		listSize = 0;
	}

	bool empty() {
		if (listSize == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	int size() {
		return listSize;
	}

	int top() {
		if (empty()) {
			return -1;
		}
		return topNode->data;
	}

	void push(int data) {
		node* newNode = new node(); //새 노드 생성
		newNode->data = data;
		newNode->next = topNode;
		topNode = newNode; //새 노드가 리시트의 가장 앞에 오게 됨
		listSize++;
	}

	void pop() {
		if (empty()) {
			return;
		}

		node* curNode = topNode;
		topNode = topNode->next; //탑 노드가 가장 앞에 있으므로 다음 노드로 탑 노드를 이전
		delete curNode;
		listSize--;
	}
};

int main() {
	int T = 0;
	cin >> T;

	ListStack stack;

	string str;
	while (T--) {
		cin >> str;
		if (str == "empty") {
			if (stack.empty()) {
				cout << "empty" << endl;
			}
			else {
				cout << "Not empty" << endl;
			}
		}

		else if (str == "size") {
			cout << stack.size() << endl;
		}

		else if (str == "top") {
			cout << stack.top() << endl;
		}

		else if (str == "push") {
			int data = 0;
			cin >> data;
			stack.push(data);
		}
		
		else if (str == "pop") {
			stack.pop();
		}
	}

	return 0;
}