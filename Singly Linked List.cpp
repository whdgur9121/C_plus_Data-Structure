//������
#include<iostream>
using namespace std;

struct node {
	int data; //������ �ʵ�
	node* next; //��ũ �ʵ�
};

class singlyLinkedList {
private:
	node* head; //����Ʈ�� ó��(������)
	node* tail; //����Ʈ�� ��(������)
	int listSize; //����Ʈ�� ũ��

public:
	singlyLinkedList() { //������
		head = NULL; //node�� ���� ������ ��� NULL
		tail = NULL;
		listSize = 0;
	}

	bool empty() { //����Ʈ�� node�� �����ϴ��� �ľ�
		if (listSize == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	void append(int data) { //�� ���� node�� �߰�
		node* newNode = new node; //�� ��� ���� �� ������ ����
		newNode->data = data;
		newNode->next = NULL;

		if (empty()) {
			head = tail = newNode; //node�� �����ٸ� ���ÿ� ���� ����
		}
		else {
			tail->next = newNode; //���� ������ �������� �� ��� �߰�
			tail = newNode; //�� ��尡 ������ �ȴ�
		}

		listSize++;
	}

	void insertion(int i, int data) {
		if (i < 0 || i > listSize) { //�������� �ʴ� ��� ����
			return;
		}

		else if (i == listSize) { //�� ���� �����ϴ� ��� �߰��� �ٸ� �� ����
			append(data);
		}

		else if (i == 0) { //ó���� �߰�
			node* newNode = new node;  //�� ��� ����
			newNode->data = data;
			newNode->next = head; //�� ��带 �� �տ� ����
			head = newNode; //�� ��尡 ��尡 ��
			listSize++;
		}

		else {
			node* newNode = new node; //�� ��� ����
			newNode->data = data;
			node* curNode = head; //���ϴ� ��ġ�� �����ϱ� ���� �ļ��� ����
			for (int k = 1; k < i; k++) {
				curNode = curNode->next; //���ϴ� ��ġ(���� ��ġ�� 1��° ��)�� �̵�
			}
			newNode->next = curNode->next; //���ϴ� ��ġ�� ���� ���� �� ��� ����
			curNode->next = newNode; //�� ��� ����
			listSize++;
		}
	}

	void deletion(int i) {
		if (empty() || i < 0 || i> listSize) { //�������� ����� ��� ����
			return;
		}
		node* curNode = head; //���ϴ� ��ġ�� �����ϱ� ���� �ļ��� ����
		if (i == 0) { //head�� �����ϴ� ���
			if (listSize == 1) { //size�� 1�ΰ�� ���� ������ �����ֱ⸸ �ϸ� ��
				head = tail = NULL;
			}
			else {
				head = head->next; //������� �ʴٸ� ��带 ���� ���� �ѱ�
			}
		}

		else {
			node* preNode = head; //���� ��带 ����
			for (int k = 0; k < i; k++) {
				preNode = curNode;
				curNode = curNode->next; //���ϴ� ��ġ���� �̵�
			}
			preNode->next = curNode->next; //���� ����� ���� ���� ���� ����� ���� ��带 ����
			if (curNode == tail) {
				tail = preNode; //���� ���� ��尡 �����̸� ������ ���� ���� �Ѱ���
			}
		}
		delete curNode; //��� ����
		listSize--;
	}

	void print() {
		if (empty()) {
			cout << "emtpy";
		}
		node* curNode = head; //ó������ ������ ����ϱ⿡ head���� ����
		while (curNode != NULL) {
			cout << curNode->data << " ";
			curNode = curNode->next;
		}
		cout << endl;
	}
};

int main() {
	int T = 0;
	cin >> T;

	singlyLinkedList List; //List ����
	string str;
	int index = 0;
	int data = 0;

	while (T--) {
		cin >> str;
		if (str == "empty") {
			if (List.empty()) {
				cout << "empty" << endl;
			}
			else {
				cout << "Not empty" << endl;
			}
		}

		else if (str == "append") {
			cin >> data;
			List.append(data);
		}

		else if (str == "insertion") {
			cin >> index >> data;
			List.insertion(index, data);
		}

		else if (str == "deletion") {
			cin >> index;
			List.deletion(index);
		}

		else if (str == "print") {
			List.print();
		}
	}

	return 0;
}