#include<iostream>
using namespace std;

struct node {
	int data; //node���� ������ ����
	node* prev; //���� ���
	node* next; //���� ���
};

class nodeList {
private:
	node* header;
	node* trailer;
	int n; //����Ʈ�� ũ��

public:
	nodeList() {
		header = new node(); //��� ����
		trailer = new node(); //Ʈ���Ϸ� ����
		header->next = trailer; //����� Ʈ���Ϸ� ����
		trailer->prev = header; //Ʈ���Ϸ��� ��� ����
		header->prev = trailer->next = NULL; //����� ����, Ʈ���Ϸ��� ���� �� ������ ����
		n = 0; //ũ�� 0
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

	node* begin() {
		return header->next; //������������ �̵�
	}

	node* end() {
		return trailer; //������ �̵�
	}

	void insert(node* pos, int data) {
		node* newNode = new node(); //�� ��� ����
		newNode->data = data; //������ �Ҵ�
		newNode->prev = pos->prev; //���ο� ��带 ����Ʈ�� ����
		newNode->next = pos;
		pos->prev->next = newNode; //���� ��� pos�� ���踦 ����
		pos->prev = newNode;
		n++; //������ ����
	}

	void insertfront(int data) {
		insert(begin(), data);
	}

	void insertBack(int data) {
		insert(end(), data);
	}

	void erase(node* pos) {
		if (empty() || pos == NULL) { //����Ʈ�� ����ְų� �Ҵ���� ��尡 �߸��� ���
			return;
		}
		pos->prev->next = pos->next; //���� ����� ����, ���� ����� ���� ����
		pos->next->prev = pos->prev;
		delete pos;
		n--;
	}

	void eraseFront() {
		erase(begin());
	}

	void eraseBack() {
		erase(end()->prev);
	}
};

int main() {
	nodeList list; //class ����
	node* p = list.begin(); //������ ����
	int T = 0;
	cin >> T;

	string str;
	while (T--) {
		cin >> str;
		if (str == "insert") {
			int data;
			cin >> data;

			list.insert(p, data);
		}

		else if (str == "erase") {
			list.erase(p);
			p = list.begin();
		}

		else if (str == "next") {
			if (p != list.end()) {
				p = p->next;
			}
		}

		else if (str == "prev") {
			if (p != list.begin()) {
				p = p->prev;
			}
		}
	}
}