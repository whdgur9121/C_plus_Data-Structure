#include<iostream>
using namespace std;

class arrayVector {
private:
	int capacity; //arr의 최대 크기
	int n; //현재 arr의 크기
	int* arr;
	void reserve(int size) {  //벡터의 크기를 size로 초기화
		if (size <= capacity) { //size가 용량보다 작으면 용량을 키울 이유가 없음
			return;
		}
		int* arrTemp = new int[size]; //arr에 덮어씌우기 위한 배열 생성
		for (int i = 0; i < n; i++) {
			arrTemp[i] = arr[i];
		} //arr의 데이터 옮기기

		if (arr != NULL) {
			delete[] arr;
		}
		arr = arrTemp; //복사해두었던 data 할당
		capacity = size;
	}

public:
	arrayVector() { //생성자를 통해 변수 초기화
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

	int at(int idx) { //idx에 있는 data를 리턴
		if (idx < 0 || n <= idx) { //idx는 0 이하가 될 수 없고 배열의 현재 크기보다 클 수 없음
			return -1;
		}
		return arr[idx];
	}

	void set(int idx, int data) { //idx에 있는 data를 변경
		if (idx < 0 || n <= idx) {
			return;
		}

		arr[idx] = data;
	}

	void erase(int idx) { //idx에 있는 data를 삭제
		if (idx < 0 || n <= idx) {
			return;
		}

		for (int i = idx + 1; i < n; i++) { //비어있으면 안되기 때문에 1칸씩 당겨주기
			arr[i - 1] = arr[i];
		}
		n--;
	}

	void insert(int idx, int data) {
		if (idx < 0 || n <= idx) {
			return;
		}
		if (n == capacity) { //최대크기에 도달한 경우 capacity의 2배만큼 배열 확장
			reserve(2 * capacity);
		}
		for (int i = n - 1; i >= idx; i--) {
			arr[i + 1] = arr[i]; //idx에 data를 넣기 위해 idx 이후의 data를 한칸씩 뒤로 밀기
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