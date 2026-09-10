#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstddef>

// 벡터와 같은 데이터 구조의 기본 형태를 정의하는 클래스
template<class T>
class DataFrame {
protected:
	T* data_;
	size_t size_;

public:
	// 데이터를 가리키는 포인터를 비어있는 상태로 초기화
	DataFrame() :data_(nullptr)
	{
	}

	// 할당된 메모리 해제
	~DataFrame()
	{
		if (data_ != nullptr)
		{
			delete[] data_;
		}
	}

	// 데이터의 크기를 반환하는 순수 가상 함수
	virtual size_t size() = 0;

	// 데이터를 초기화하는 순수 가상 함수
	virtual void clear() = 0;
};

namespace lkh {

	template <class T>
	class Vector : public DataFrame<T> {
	public:
		// iterator를 원소를 가리키는 포인터로 정의
		typedef T* iterator;

	private:
		// 현재 할당되어 있는 배열의 전체 크기
		size_t capacity_;

		// 저장 공간이 부족할 때 용량을 확장하는 함수
		void grow();

	public:
		// 기본 생성자
		Vector();

		// 다른 벡터의 데이터를 복사하여 생성
		Vector(const Vector<T>& other);

		// 소멸자
		~Vector();

		// 벡터의 마지막에 원소 추가
		void push_back(const T& value);

		// 인덱스의 범위를 확인한 후 원소 반환
		T& at(int index);

		// 첫 번째 원소의 위치 반환
		iterator begin();

		// 마지막 원소 다음 위치 반환
		iterator end();

		// 벡터가 비어있는지 확인
		bool empty();

		// 지정한 위치의 원소 삭제
		void erase(iterator it);

		// 지정한 위치에 새로운 원소 삽입
		void insert(iterator it, const T& value);

		// 인덱스를 이용하여 원소에 접근
		T& operator[](int index);

		// 다른 벡터의 데이터를 현재 벡터에 복사
		Vector<T>& operator=(const Vector<T>& other);

		// 다른 벡터의 원소를 현재 벡터 뒤에 이어 붙임
		Vector<T>& operator+=(const Vector<T>& other);

		// 값 하나를 현재 벡터의 마지막에 추가
		Vector<T>& operator+=(const T& value);

		// 두 벡터를 이어 붙인 새로운 벡터 반환
		Vector<T> operator+(const Vector<T>& other);

		// 값 하나를 추가한 새로운 벡터 반환
		Vector<T> operator+(const T& value);

		// 현재 할당된 메모리의 용량 반환
		size_t capacity();

		// 현재 저장된 원소의 개수 반환
		// DataFrame의 순수 가상 함수를 재정의
		size_t size();

		// 벡터의 데이터와 크기를 초기화
		// DataFrame의 순수 가상 함수를 재정의
		void clear();
	};

}

#endif