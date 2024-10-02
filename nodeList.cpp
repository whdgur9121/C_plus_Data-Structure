#include<iostream>
using namespace std;

struct node {
	int data; //node에서 데이터 저장
	node* prev; //이전 노드
	node* next; //다음 노드
};

class nodeList {
private:
	node* header;
	node* trailer;
	int n; //리스트의 크기

public:
	nodeList() {
		header = new node(); //헤더 생성
		trailer = new node(); //트레일러 생성
		header->next = trailer; //헤더와 트레일러 연결
		trailer->prev = header; //트레일러와 헤드 연결
		header->prev = trailer->next = NULL; //헤드의 이전, 트레일러의 이후 빈 값으로 저장
		n = 0; //크기 0
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
		return header->next; //시작지점으로 이동
	}

	node* end() {
		return trailer; //끝으로 이동
	}

	void insert(node* pos, int data) {
		node* newNode = new node(); //새 노드 생성
		newNode->data = data; //데이터 할당
		newNode->prev = pos->prev; //새로운 노드를 리스트에 연결
		newNode->next = pos;
		pos->prev->next = newNode; //기존 노드 pos의 관계를 변경
		pos->prev = newNode;
		n++; //사이즈 증가
	}

	void insertfront(int data) {
		insert(begin(), data);
	}

	void insertBack(int data) {
		insert(end(), data);
	}

	void erase(node* pos) {
		if (empty() || pos == NULL) { //리스트가 비버있거나 할당받은 노드가 잘못된 경우
			return;
		}
		pos->prev->next = pos->next; //삭제 노드의 이전, 이후 노드의 관계 변경
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
	nodeList list; //class 생성
	node* p = list.begin(); //포인터 생성
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