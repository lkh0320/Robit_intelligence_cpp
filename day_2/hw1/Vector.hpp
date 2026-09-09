#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstddef>
#include "DataFrame.hpp"

namespace lkh {

	template <class T>
	class Vector : public DataFrame<T> {
	public:
		typedef T* iterator;    // 원소를 가리키는 포인터

	private:
		size_t capacity_;       // 할당해 놓은 칸 수

		void grow();            // 용량 2배 확장

	public:
		Vector();
		Vector(const Vector<T>& other);   // 복사 생성자
		~Vector();

		void push_back(const T& value);              // 마지막에 원소 추가
		T& at(int index);                            // 범위 검사 후 원소 참조 리턴
		iterator begin();                            // 첫 원소 위치
		iterator end();                              // 마지막 원소 다음 위치
		bool empty();                                // 비어있는지 확인
		void erase(iterator it);                     // it 위치 원소 삭제
		void insert(iterator it, const T& value);    // it 위치에 원소 삽입
		T& operator[](int index);                    // 원소 참조 리턴
		Vector<T>& operator=(const Vector<T>& other);// 다른 벡터 복사

		size_t capacity();                           // 현재 용량

		size_t size();                               // DataFrame 순수 가상 함수 재정의
		void clear();                                // DataFrame 순수 가상 함수 재정의
	};

}

#endif