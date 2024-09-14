//������
#include<iostream>
using namespace std;

class arrayStack { //�迭�� �̿��� ����(LIFO)
private:
	int* arr; //�����Ҵ��� ���� �迭 ����
	int capacity; //�迭 �뷮
	int topIndex; //������ �� �ִ� element

public:
	arrayStack(int capacity) {
		this->capacity = capacity; //�迭 ���� ����
		arr = new int[capacity];
		topIndex = -1; //���Ұ� ���� ������ ��� element�� ��Ÿ���� ���ڴ� -1;
	}

	bool empty() {
		if (topIndex == -1) {
			return true;
		}
		else {
			return false;
		}
	}

	int size() {
		return topIndex + 1; //Index�� 0���� �����ϱ⿡ +1
	}

	int top() { //���� ����� data ����
		if (empty()) {
			return -1;
		}
		return arr[topIndex]; 
	}

	void push(int data) { //���ÿ� ���� ����
		if (size() == capacity) {
			return;
		}
		arr[++topIndex] = data;
	}

	void pop() { //���ÿ��� ���� ����
		if (empty()) {
			return;
		}
		topIndex--; //���� �������� �ʾƵ� topIndex�� ���� ���� ������ ���̳� �ٸ��� ����
	}

	void print() {
		if (empty()) {
			cout << "empty" << endl;
		}
		else {
			for (int i = 0; i <= topIndex; i++) {
				cout << arr[i] << " ";
			}
			cout << endl;
		}
	}
};

int main() {
	int T = 0;
	cin >> T;

	int Capacity;
	cin >> Capacity;
	arrayStack stack(Capacity);

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
			int data;
			cin >> data;
			stack.push(data);
		}

		else if (str == "pop") {
			stack.pop();
		}

		else if (str == "print") {
			stack.print();
		}
	}
	return 0;
}