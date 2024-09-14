//강종혁
#include<iostream>
using namespace std;

struct node {
	int data; //데이터 필드
	node* next; //링크 필드
};

class singlyLinkedList {
private:
	node* head; //리스트의 처음(포인터)
	node* tail; //리스트의 끝(포인터)
	int listSize; //리스트의 크기

public:
	singlyLinkedList() { //생성자
		head = NULL; //node가 없기 때문에 모두 NULL
		tail = NULL;
		listSize = 0;
	}

	bool empty() { //리스트의 node가 존재하는지 파악
		if (listSize == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	void append(int data) { //맨 끝에 node를 추가
		node* newNode = new node; //새 노드 생성 및 데이터 저장
		newNode->data = data;
		newNode->next = NULL;

		if (empty()) {
			head = tail = newNode; //node가 없었다면 동시에 헤드와 테일
		}
		else {
			tail->next = newNode; //기존 테일의 다음으로 새 노드 추가
			tail = newNode; //새 노드가 테일이 된다
		}

		listSize++;
	}

	void insertion(int i, int data) {
		if (i < 0 || i > listSize) { //성립하지 않는 경우 리턴
			return;
		}

		else if (i == listSize) { //맨 끝에 삽입하는 경우 추가랑 다를 게 없음
			append(data);
		}

		else if (i == 0) { //처음에 추가
			node* newNode = new node;  //새 노드 생성
			newNode->data = data;
			newNode->next = head; //새 노드를 맨 앞에 연결
			head = newNode; //새 노드가 헤드가 됨
			listSize++;
		}

		else {
			node* newNode = new node; //새 노드 생성
			newNode->data = data;
			node* curNode = head; //원하는 위치에 도달하기 위해 파수꾼 생성
			for (int k = 1; k < i; k++) {
				curNode = curNode->next; //원하는 위치(삽입 위치의 1번째 전)로 이동
			}
			newNode->next = curNode->next; //원하는 위치의 다음 노드와 새 노드 연결
			curNode->next = newNode; //새 노드 삽입
			listSize++;
		}
	}

	void deletion(int i) {
		if (empty() || i < 0 || i> listSize) { //범위에서 벗어나는 경우 리턴
			return;
		}
		node* curNode = head; //원하는 위치에 도달하기 위한 파수꾼 생성
		if (i == 0) { //head를 삭제하는 경우
			if (listSize == 1) { //size가 1인경우 헤드와 테일을 없애주기만 하면 됨
				head = tail = NULL;
			}
			else {
				head = head->next; //비어있지 않다면 헤드를 다음 노드로 넘김
			}
		}

		else {
			node* preNode = head; //이전 노드를 저장
			for (int k = 0; k < i; k++) {
				preNode = curNode;
				curNode = curNode->next; //원하는 위치까지 이동
			}
			preNode->next = curNode->next; //삭제 노드의 이전 노드와 삭제 노드의 다음 노드를 연결
			if (curNode == tail) {
				tail = preNode; //만약 삭제 노드가 테일이면 테일을 이전 노드로 넘겨줌
			}
		}
		delete curNode; //노드 삭제
		listSize--;
	}

	void print() {
		if (empty()) {
			cout << "emtpy";
		}
		node* curNode = head; //처음부터 끝까지 출력하기에 head부터 시작
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

	singlyLinkedList List; //List 생성
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