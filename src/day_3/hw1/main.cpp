#include <iostream>
#include "Vector.hpp"

using namespace std;

// 벡터의 크기와 저장된 원소를 출력하는 함수
template <class T>
void print(const char* name, lkh::Vector<T>& v) {
	cout << name << " : size " << v.size() << endl;

	// iterator를 이용하여 벡터의 처음부터 끝까지 원소 출력
	for (typename lkh::Vector<T>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl << endl;
}

int main() {
	// int형 벡터 2개 생성
	lkh::Vector<int> v1;
	lkh::Vector<int> v2;

	// v1에 원소 추가
	v1.push_back(11);
	v1.push_back(12);

	// v2에 원소 추가
	v2.push_back(13);
	v2.push_back(14);
	v2.push_back(20);

	// v1과 v2의 현재 상태 출력
	print("v1", v1);
	print("v2", v2);

	// 두 벡터를 이어 붙여 새로운 벡터 생성
	lkh::Vector<int> v3 = v1 + v2;
	print("v3 = v1 + v2", v3);

	// v3의 뒤에 v1의 모든 원소 추가
	v3 += v1;
	print("v3 += v1", v3);

	// v3에 100을 추가한 새로운 벡터 생성
	// 기존 v3의 내용은 변경되지 않음
	lkh::Vector<int> tmp = v3 + 100;
	print("v3 + 100", tmp);

	// v3의 마지막에 80 추가
	v3 += 80;
	print("v3 += 80", v3);

	return 0;
}