//강종혁
#include<iostream>
#include<vector>
using namespace std;

struct node {
	int data;  //데이터
	node* parent; //부모노드의 포인터 변수 저장
	vector<node*> childList; //자식을 관리하는 노드리스트 저장
	node(int data, node* parent) { //생성자, 부모를 지정하여 묶음
		this->data = data;
		this->parent = parent;
	}
};

class Tree {
private:
	node* root; //루트 저장
	vector<node*> nodeList; //트리 내의 노드 저장
	int find(int data, vector<node*>& List) { //전달 받은 데이터를 전달 받은 리스트에서 찾기
		for (int i = 0; i < List.size(); i++) {
			if (List[i]->data == data) {
				return i; //찾으면 index값 반환
			}
		}
		return -1; //찾지 못하면 -1 반환
	}


public:
	Tree(int data) { //생성자
		root = new node(data, NULL); //루트를 만들고
		nodeList.push_back(root); //루트를 노드리스트에 추가
	}

	void insertNode(int parData, int data) { //노드 삽입
		if (find(data, nodeList) != -1) {
			return; //data가 이미 존재하는 경우
		}

		int idx = find(parData, nodeList); //부모 노드의 존재 확인
		if (idx == -1) {
			return; //부모가 없으면 종료
		}

		node* parNode = nodeList[idx]; //부모 노드를 새 노드 생성시에 넣어야 하므로 부모 노드 할당
		node* newNode = new node(data, parNode); //새 노드 생성
		parNode->childList.push_back(newNode); //새 노드 부모 노드 자식 리스트 추가
		nodeList.push_back(newNode); //새 노드 노드리스트 추가
	}

	void deleteNode(int data) {
		int idx = find(data, nodeList); //원하는 인덱스 찾기
		if (idx == -1) {
			return; //없으면 종료
		}

		node* delNode = nodeList[idx]; //del노드에 삭제하려는 노드 저장
		if (delNode == root) {
			return; //만약 삭제하려는 노드가 루트일시 종료
		}

		node* parNode = delNode->parent; //삭제 노드 부모 할당
		for (int i = 0; i < delNode->childList.size(); i++) {
			parNode->childList.push_back(delNode->childList[i]);
			delNode->childList[i]->parent = parNode;
		} //삭제 노드의 자녀들을 사제 노드의 부모로 옮김. 부모에서 연결하고, 자녀에서 연결.

		vector<node*>& child = parNode->childList; //삭제 노드의 부모 노드 자식리스트 할당
		child.erase(child.begin() + find(data, child)); //삭제 노드만큼의 이동후 연결 끊기
		nodeList.erase(nodeList.begin() + idx); //노드 리스트에서 삭제
		delete delNode; //노드 삭제
	}

	void printParent(int data) {
		int idx = find(data, nodeList);
		if (idx <= 0) {
			return; //노드가 존재하지 않는 경우
		}

		node* curNode = nodeList[idx];
		cout << curNode->parent->data << endl; //부모 출력
	}

	void printChild(int data) {
		int idx = find(data, nodeList); //데이터로 인덱스 찾기
		if (idx == -1) {
			return;
		}

		vector<node*>& child = nodeList[idx]->childList; //원하는 노드의 자녀리스트 저장
		if (child.empty()) {
			return; // 자식노드 비어있으면 종료
		}

		for (int i = 0; i < child.size(); i++) {
			cout << child[i]->data << " "; //자녀들 모두 출력
		}
		cout << endl;
	}
};

int main() {
	int T = 0;
	cin >> T;

	int root;
	cin >> root;

	string str;

	Tree tree(root);

	while (T--) {
		cin >> str;

		if (str == "insertNode") {
			int parData, data;
			cin >> parData >> data;
			tree.insertNode(parData, data);
		}

		else if (str == "deleteNode") {
			int data;
			cin >> data;
			tree.deleteNode(data);
		}

		else if (str == "printParent") {
			int data;
			cin >> data;
			tree.printParent(data);
		}

		else if (str == "printChild") {
			int data;
			cin >> data;
			tree.printChild(data);
		}
	}

	return 0;
}