//강종혁
#include<iostream>
using namespace std;

class arrayStack { //배열을 이용한 스택(LIFO)
private:
	int* arr; //동적할당을 위한 배열 생성
	int capacity; //배열 용량
	int topIndex; //접근할 수 있는 element

public:
	arrayStack(int capacity) {
		this->capacity = capacity; //배열 동적 생성
		arr = new int[capacity];
		topIndex = -1; //원소가 없기 때문에 상단 element를 나타내는 숫자는 -1;
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
		return topIndex + 1; //Index는 0부터 시작하기에 +1
	}

	int top() { //가장 상단의 data 리턴
		if (empty()) {
			return -1;
		}
		return arr[topIndex]; 
	}

	void push(int data) { //스택에 원소 삽입
		if (size() == capacity) {
			return;
		}
		arr[++topIndex] = data;
	}

	void pop() { //스택에서 원소 제거
		if (empty()) {
			return;
		}
		topIndex--; //값을 제거하지 않아도 topIndex를 줄인 순간 없어진 것이나 다름이 없다
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