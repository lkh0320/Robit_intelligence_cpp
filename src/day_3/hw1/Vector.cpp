#include "Vector.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

namespace lkh {

	// 벡터를 빈 상태로 초기화
	template <class T>
	Vector<T>::Vector() {
		this->data_ = nullptr;
		this->size_ = 0;
		capacity_ = 0;
	}

	// 기존 벡터의 데이터를 복사하여 새로운 벡터 생성
	template <class T>
	Vector<T>::Vector(const Vector<T>& other) {
		this->data_ = nullptr;
		this->size_ = 0;
		capacity_ = 0;
		*this = other;
	}

	// 벡터가 사용하던 메모리 해제
	template <class T>
	Vector<T>::~Vector() {
		clear();
	}

	// 용량을 2배로 늘리고 기존 데이터를 새로운 배열로 복사
	template <class T>
	void Vector<T>::grow() {
		size_t new_capacity;

		if (capacity_ == 0) {
			new_capacity = 1;
		}
		else {
			new_capacity = capacity_ * 2;
		}

		// 새로운 용량만큼 메모리 할당
		T* new_data = new T[new_capacity];

		// 기존 배열의 데이터를 새로운 배열로 복사
		for (size_t i = 0; i < this->size_; i++) {
			new_data[i] = this->data_[i];
		}

		// 기존에 할당된 메모리 해제
		if (this->data_ != nullptr) {
			delete[] this->data_;
		}

		this->data_ = new_data;
		capacity_ = new_capacity;
	}

	// 벡터의 마지막에 새로운 원소 추가
	template <class T>
	void Vector<T>::push_back(const T& value) {
		// 저장 공간이 부족하면 메모리 확장
		if (this->size_ == capacity_) {
			grow();
		}

		this->data_[this->size_] = value;
		this->size_++;
	}

	// 지정한 인덱스의 원소를 반환
	template <class T>
	T& Vector<T>::at(int index) {
		// 인덱스가 벡터의 범위를 벗어났는지 확인
		if (index < 0 || index >= (int)this->size_) {
			cout << "index out of range" << endl;
			exit(1);
		}

		return this->data_[index];
	}

	// 벡터의 첫 번째 원소를 가리키는 iterator 반환
	template <class T>
	typename Vector<T>::iterator Vector<T>::begin() {
		return this->data_;
	}

	// 벡터의 마지막 원소 다음 위치를 가리키는 iterator 반환
	template <class T>
	typename Vector<T>::iterator Vector<T>::end() {
		return this->data_ + this->size_;
	}

	// 벡터가 비어있는지 확인
	template <class T>
	bool Vector<T>::empty() {
		return this->size_ == 0;
	}

	// 삭제한 원소의 뒤쪽 원소들을 한 칸씩 앞으로 이동
	template <class T>
	void Vector<T>::erase(iterator it) {
		// 삭제할 위치가 유효한지 확인
		if (this->size_ == 0 || it < begin() || it >= end()) {
			return;
		}

		// 삭제할 원소 뒤의 값들을 한 칸씩 앞으로 이동
		for (iterator p = it; p + 1 != end(); p++) {
			*p = *(p + 1);
		}

		this->size_--;
	}

	// 지정한 위치에 새로운 원소 삽입
	template <class T>
	void Vector<T>::insert(iterator it, const T& value) {
		// 삽입할 위치가 벡터의 범위 안에 있는지 확인
		if (it < begin() || it > end()) {
			return;
		}

		// iterator를 이용하여 삽입할 인덱스 계산
		size_t index = it - begin();

		// 저장 공간이 부족하면 메모리 확장
		if (this->size_ == capacity_) {
			grow();
		}

		// 삽입할 위치의 뒤쪽 원소들을 한 칸씩 뒤로 이동
		for (size_t i = this->size_; i > index; i--) {
			this->data_[i] = this->data_[i - 1];
		}

		// 빈 공간에 새로운 원소 삽입
		this->data_[index] = value;
		this->size_++;
	}

	// 지정한 인덱스의 원소를 참조로 반환
	template <class T>
	T& Vector<T>::operator[](int index) {
		return this->data_[index];
	}

	// 다른 벡터의 데이터를 복사하여 대입
	template <class T>
	Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
		// 자기 자신을 대입하는 경우 그대로 반환
		if (this == &other) {
			return *this;
		}

		// 기존에 사용하던 메모리 해제
		clear();

		capacity_ = other.capacity_;
		this->size_ = other.size_;

		// 다른 벡터와 같은 크기의 배열을 새로 할당
		if (capacity_ > 0) {
			this->data_ = new T[capacity_];

			// 원소를 하나씩 복사하여 깊은 복사 수행
			for (size_t i = 0; i < this->size_; i++) {
				this->data_[i] = other.data_[i];
			}
		}

		return *this;
	}

	// 다른 벡터의 원소를 현재 벡터 뒤에 추가
	template <class T>
	Vector<T>& Vector<T>::operator+=(const Vector<T>& other) {
		size_t n = other.size_;

		// other의 원소를 하나씩 현재 벡터에 추가
		for (size_t i = 0; i < n; i++) {
			T value = other.data_[i];
			push_back(value);
		}

		return *this;
	}

	// 값 하나를 현재 벡터의 마지막에 추가
	template <class T>
	Vector<T>& Vector<T>::operator+=(const T& value) {
		push_back(value);
		return *this;
	}

	// 두 벡터를 이어 붙인 새로운 벡터 반환
	template <class T>
	Vector<T> Vector<T>::operator+(const Vector<T>& other) {
		// 현재 벡터를 복사하여 새로운 벡터 생성
		Vector<T> result(*this);

		// other의 원소를 result 뒤에 추가
		result += other;

		return result;
	}

	// 기존 벡터에 값 하나를 추가한 새로운 벡터 반환
	template <class T>
	Vector<T> Vector<T>::operator+(const T& value) {
		// 현재 벡터를 복사하여 새로운 벡터 생성
		Vector<T> result(*this);

		// 새로운 벡터의 마지막에 값 추가
		result += value;

		return result;
	}

	// 현재 할당된 메모리 용량 반환
	template <class T>
	size_t Vector<T>::capacity() {
		return capacity_;
	}

	// 현재 저장된 원소의 개수 반환
	template <class T>
	size_t Vector<T>::size() {
		return this->size_;
	}

	// 사용 중인 메모리를 해제하고 벡터를 빈 상태로 초기화
	template <class T>
	void Vector<T>::clear() {
		// 할당된 배열이 있으면 메모리 해제
		if (this->data_ != nullptr) {
			delete[] this->data_;
			this->data_ = nullptr;
		}

		this->size_ = 0;
		capacity_ = 0;
	}

}

// 사용할 자료형을 미리 생성
template class lkh::Vector<int>;
template class lkh::Vector<double>;
template class lkh::Vector<string>;