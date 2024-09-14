//������
#include<iostream>
using namespace std;

class Array {
private : 
	int* arr;    //�迭(�����Ҵ�)
	int arrSize; //�迭 ũ��

public:
	Array(int size) {                    //������
		this->arrSize = size;            //�迭 ũ�� �ʱ�ȭ
		this->arr = new int[arrSize];    //�迭 ����
		for (int i = 0; i < size; i++) { //�迭 0���� �� �ʱ�ȭ
			arr[i] = 0;
		}
	}

	int at(int index) {                  //�ش� index�� ��� ����
		return arr[index];
	}

	void add(int index, int value) {
		for (int i = arrSize - 2; i >= index; i--) { //��ĭ�� �б�
			arr[i + 1] = arr[i];
		}
		arr[index] = value; //���ϴ� �� ���ϴ� index�� �ֱ�
	}

	void set(int index, int value) { //���ϴ� ���� ���ϴ� index�� �ִ� �Լ�
		arr[index] = value;
	}

	void print() { //index 0���� ��� �迭�� element�� ���
		for (int i = 0; i < arrSize; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	void remove(int index) { //���� ������ �ʿ�� ����(��ܿ��� �װ� ���ŵǴ� ���̱� ������)
		for (int i = index + 1; i < arrSize; i++) { // ��ĭ�� ��ܿ���
			arr[i - 1] = arr[i];
		}
		arr[arrSize - 1] = 0; //����� ������ ĭ�� 0 �ֱ�
	}
};


int main() {
	int T = 0; //���� Ƚ��
	int size = 0; //�迭�� ũ��
	cin >> T >> size;
	Array array(size); //�迭 ����

	int index = 0;
	int value = 0;
	string str;

	while (T--) {
		cin >> str;
		if (str == "at") {
			cin >> index;
			array.at(index);
		}

		else if (str == "add") {
			cin >> index >> value;
			array.add(index, value);
		}

		else if (str == "set") {
			cin >> index >> value;
			array.set(index, value);
		}

		else if (str == "remove") {
			cin >> index;
			array.remove(index);
		}

		else if (str == "print") {
			array.print();
		}
	}

	return 0;
}