#include<iostream>
using namespace std;

class arrayVector {
private:
	int capacity; //arr�� �ִ� ũ��
	int n; //���� arr�� ũ��
	int* arr;
	void reserve(int size) {  //������ ũ�⸦ size�� �ʱ�ȭ
		if (size <= capacity) { //size�� �뷮���� ������ �뷮�� Ű�� ������ ����
			return;
		}
		int* arrTemp = new int[size]; //arr�� ������ ���� �迭 ����
		for (int i = 0; i < n; i++) {
			arrTemp[i] = arr[i];
		} //arr�� ������ �ű��

		if (arr != NULL) {
			delete[] arr;
		}
		arr = arrTemp; //�����صξ��� data �Ҵ�
		capacity = size;
	}

public:
	arrayVector() { //�����ڸ� ���� ���� �ʱ�ȭ
		capacity = 1;
		arr = new int[1];
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

	int at(int idx) { //idx�� �ִ� data�� ����
		if (idx < 0 || n <= idx) { //idx�� 0 ���ϰ� �� �� ���� �迭�� ���� ũ�⺸�� Ŭ �� ����
			return -1;
		}
		return arr[idx];
	}

	void set(int idx, int data) { //idx�� �ִ� data�� ����
		if (idx < 0 || n <= idx) {
			return;
		}

		arr[idx] = data;
	}

	void erase(int idx) { //idx�� �ִ� data�� ����
		if (idx < 0 || n <= idx) {
			return;
		}

		for (int i = idx + 1; i < n; i++) { //��������� �ȵǱ� ������ 1ĭ�� ����ֱ�
			arr[i - 1] = arr[i];
		}
		n--;
	}

	void insert(int idx, int data) {
		if (idx < 0 || n <= idx) {
			return;
		}
		if (n == capacity) { //�ִ�ũ�⿡ ������ ��� capacity�� 2�踸ŭ �迭 Ȯ��
			reserve(2 * capacity);
		}
		for (int i = n - 1; i >= idx; i--) {
			arr[i + 1] = arr[i]; //idx�� data�� �ֱ� ���� idx ������ data�� ��ĭ�� �ڷ� �б�
		}
		arr[idx] = data;
		n++;
	}
};

int main() {
	int T = 0;
	cin >> T;

	arrayVector Vector;
	string str;

	while (T--) {
		cin >> str;

		if (str == "empty") {
			if (Vector.empty()) {
				cout << "True" << endl;
			}
			else {
				cout << "False" << endl;
			}
		}

		else if (str == "size") {
			cout << Vector.size() << endl;
		}

		else if (str == "at") {
			int idx;
			cin >> idx;
			cout << Vector.at(idx) << endl;
		}

		else if (str == "set") {
			int idx, data;
			cin >> idx >> data;
			Vector.set(idx, data);
		}

		else if (str == "erase") {
			int idx;
			cin >> idx;
			Vector.erase(idx);
		}

		else if (str == "insert") {
			int idx, data;
			cin >> idx >> data;
			Vector.insert(idx, data);
		}
	}
	return 0;
}