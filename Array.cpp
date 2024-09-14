//강종혁
#include<iostream>
using namespace std;

class Array {
private : 
	int* arr;    //배열(동적할당)
	int arrSize; //배열 크기

public:
	Array(int size) {                    //생성자
		this->arrSize = size;            //배열 크기 초기화
		this->arr = new int[arrSize];    //배열 생성
		for (int i = 0; i < size; i++) { //배열 0으로 값 초기화
			arr[i] = 0;
		}
	}

	int at(int index) {                  //해당 index의 출력 리턴
		return arr[index];
	}

	void add(int index, int value) {
		for (int i = arrSize - 2; i >= index; i--) { //한칸씩 밀기
			arr[i + 1] = arr[i];
		}
		arr[index] = value; //원하는 값 원하는 index에 넣기
	}

	void set(int index, int value) { //원하는 값을 원하는 index에 넣는 함수
		arr[index] = value;
	}

	void print() { //index 0부터 모든 배열의 element를 출력
		for (int i = 0; i < arrSize; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	void remove(int index) { //값을 제거할 필요는 없음(당겨오면 그게 제거되는 것이기 때문에)
		for (int i = index + 1; i < arrSize; i++) { // 한칸씩 당겨오기
			arr[i - 1] = arr[i];
		}
		arr[arrSize - 1] = 0; //비워진 마지막 칸에 0 넣기
	}
};


int main() {
	int T = 0; //실행 횟수
	int size = 0; //배열의 크기
	cin >> T >> size;
	Array array(size); //배열 생성

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