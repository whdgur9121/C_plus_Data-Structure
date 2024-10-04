//������
#include<iostream>
#include<vector>
using namespace std;

struct node {
	int data;  //������
	node* parent; //�θ����� ������ ���� ����
	vector<node*> childList; //�ڽ��� �����ϴ� ��帮��Ʈ ����
	node(int data, node* parent) { //������, �θ� �����Ͽ� ����
		this->data = data;
		this->parent = parent;
	}
};

class Tree {
private:
	node* root; //��Ʈ ����
	vector<node*> nodeList; //Ʈ�� ���� ��� ����
	int find(int data, vector<node*>& List) { //���� ���� �����͸� ���� ���� ����Ʈ���� ã��
		for (int i = 0; i < List.size(); i++) {
			if (List[i]->data == data) {
				return i; //ã���� index�� ��ȯ
			}
		}
		return -1; //ã�� ���ϸ� -1 ��ȯ
	}


public:
	Tree(int data) { //������
		root = new node(data, NULL); //��Ʈ�� �����
		nodeList.push_back(root); //��Ʈ�� ��帮��Ʈ�� �߰�
	}

	void insertNode(int parData, int data) { //��� ����
		if (find(data, nodeList) != -1) {
			return; //data�� �̹� �����ϴ� ���
		}

		int idx = find(parData, nodeList); //�θ� ����� ���� Ȯ��
		if (idx == -1) {
			return; //�θ� ������ ����
		}

		node* parNode = nodeList[idx]; //�θ� ��带 �� ��� �����ÿ� �־�� �ϹǷ� �θ� ��� �Ҵ�
		node* newNode = new node(data, parNode); //�� ��� ����
		parNode->childList.push_back(newNode); //�� ��� �θ� ��� �ڽ� ����Ʈ �߰�
		nodeList.push_back(newNode); //�� ��� ��帮��Ʈ �߰�
	}

	void deleteNode(int data) {
		int idx = find(data, nodeList); //���ϴ� �ε��� ã��
		if (idx == -1) {
			return; //������ ����
		}

		node* delNode = nodeList[idx]; //del��忡 �����Ϸ��� ��� ����
		if (delNode == root) {
			return; //���� �����Ϸ��� ��尡 ��Ʈ�Ͻ� ����
		}

		node* parNode = delNode->parent; //���� ��� �θ� �Ҵ�
		for (int i = 0; i < delNode->childList.size(); i++) {
			parNode->childList.push_back(delNode->childList[i]);
			delNode->childList[i]->parent = parNode;
		} //���� ����� �ڳ���� ���� ����� �θ�� �ű�. �θ𿡼� �����ϰ�, �ڳ࿡�� ����.

		vector<node*>& child = parNode->childList; //���� ����� �θ� ��� �ڽĸ���Ʈ �Ҵ�
		child.erase(child.begin() + find(data, child)); //���� ��常ŭ�� �̵��� ���� ����
		nodeList.erase(nodeList.begin() + idx); //��� ����Ʈ���� ����
		delete delNode; //��� ����
	}

	void printParent(int data) {
		int idx = find(data, nodeList);
		if (idx <= 0) {
			return; //��尡 �������� �ʴ� ���
		}

		node* curNode = nodeList[idx];
		cout << curNode->parent->data << endl; //�θ� ���
	}

	void printChild(int data) {
		int idx = find(data, nodeList); //�����ͷ� �ε��� ã��
		if (idx == -1) {
			return;
		}

		vector<node*>& child = nodeList[idx]->childList; //���ϴ� ����� �ڳฮ��Ʈ ����
		if (child.empty()) {
			return; // �ڽĳ�� ��������� ����
		}

		for (int i = 0; i < child.size(); i++) {
			cout << child[i]->data << " "; //�ڳ�� ��� ���
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