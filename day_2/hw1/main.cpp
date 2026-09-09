#include <iostream>
#include <string>
#include "Vector.hpp"

using namespace std;

// 벡터 내용 출력
template <class T>
void print(lkh::Vector<T>& v) {
	cout << "[ ";
	for (typename lkh::Vector<T>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << "]  size = " << v.size() << " , capacity = " << v.capacity() << endl;
}

int main() {
	lkh::Vector<int> v;
	string cmd;

	// 명령어 안내 출력 부분은 정렬과 문구 정리를 위해 AI(Claude)의 도움을 받아 작성함
	cout << "============== lkh::Vector test ==============" << endl;
	cout << " push_back <n>        맨 뒤에 n 추가" << endl;
	cout << " at <i>               i 번째 원소 값 읽기" << endl;
	cout << " begin                첫 번째 원소" << endl;
	cout << " end                  끝 위치 확인" << endl;
	cout << " empty                비어있는지 확인" << endl;
	cout << " erase <i>            i 번째 원소 삭제" << endl;
	cout << " insert <i> <n>       i 번째 위치에 n 삽입" << endl;
	cout << " size                 원소 개수" << endl;
	cout << " operator[] <i> <n>   i 번째 원소를 n 으로 변경" << endl;
	cout << " operator=            다른 벡터에 복사 후 비교" << endl;
	cout << " clear                전체 삭제" << endl;
	cout << " print                현재 벡터 출력" << endl;
	cout << " exit                 종료" << endl;
	cout << "==============================================" << endl;

	// 명령어를 하나씩 받아서 처리하는 반복문
	while (true) {
		cout << endl << ">> ";
		cin >> cmd;

		if (cmd == "push_back") {
			int n;
			cin >> n;
			v.push_back(n);
			print(v);
		}
		else if (cmd == "at") {
			int i;
			cin >> i;
			cout << "v.at(" << i << ") = " << v.at(i) << endl;
		}
		else if (cmd == "begin") {
			if (v.empty()) cout << "empty vector" << endl;
			else cout << "*v.begin() = " << *v.begin() << endl;
		}
		else if (cmd == "end") {
			if (v.empty()) cout << "empty vector" << endl;
			else {
				cout << "*(v.end() - 1) = " << *(v.end() - 1) << endl;
				cout << "v.end() - v.begin() = " << v.end() - v.begin() << endl;
			}
		}
		else if (cmd == "empty") {
			cout << "v.empty() = " << v.empty() << endl;
		}
		else if (cmd == "erase") {
			int i;
			cin >> i;
			v.erase(v.begin() + i);
			print(v);
		}
		else if (cmd == "insert") {
			int i, n;
			cin >> i >> n;
			v.insert(v.begin() + i, n);
			print(v);
		}
		else if (cmd == "size") {
			cout << "v.size() = " << v.size() << endl;
		}
		else if (cmd == "operator[]") {
			int i, n;
			cin >> i >> n;
			v[i] = n;
			print(v);
		}
		else if (cmd == "operator=") {
			lkh::Vector<int> c;
			c = v;
			if (!c.empty()) c[0] = -1;
			cout << "original : ";
			print(v);
			cout << "copy     : ";
			print(c);
		}
		else if (cmd == "clear") {
			v.clear();
			print(v);
		}
		else if (cmd == "print") {
			print(v);
		}
		else if (cmd == "exit") {
			break;
		}
		else {
			cout << "unknown command" << endl;
		}
	}

	return 0;
}