#include "Vector.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

namespace lkh {

	// 빈 상태로 초기화
	template <class T>
	Vector<T>::Vector() {
		this->data_ = nullptr;
		this->size_ = 0;
		capacity_ = 0;
	}

	// 복사 생성자
	template <class T>
	Vector<T>::Vector(const Vector<T>& other) {
		this->data_ = nullptr;
		this->size_ = 0;
		capacity_ = 0;
		*this = other;
	}

	// 메모리 해제
	template <class T>
	Vector<T>::~Vector() {
		clear();
	}

	// 용량 2배 확장 후 기존 값 복사
	template <class T>
	void Vector<T>::grow() {
		size_t new_capacity;
		if (capacity_ == 0) {
			new_capacity = 1;
		}
		else {
			new_capacity = capacity_ * 2;
		}

		T* new_data = new T[new_capacity];

		for (size_t i = 0; i < this->size_; i++) {
			new_data[i] = this->data_[i];
		}

		if (this->data_ != nullptr) {
			delete[] this->data_;
		}

		this->data_ = new_data;
		capacity_ = new_capacity;
	}

	// 마지막에 원소 추가
	template <class T>
	void Vector<T>::push_back(const T& value) {
		if (this->size_ == capacity_) {
			grow();
		}
		this->data_[this->size_] = value;
		this->size_++;
	}

	// 인덱스 범위 체크 후 참조 리턴
	template <class T>
	T& Vector<T>::at(int index) {
		if (index < 0 || index >= (int)this->size_) {
			cout << "index out of range" << endl;
			exit(1);
		}
		return this->data_[index];
	}

	// 첫 원소 위치 리턴
	template <class T>
	typename Vector<T>::iterator Vector<T>::begin() {
		return this->data_;
	}

	// 마지막 원소 다음 위치 리턴
	template <class T>
	typename Vector<T>::iterator Vector<T>::end() {
		return this->data_ + this->size_;
	}

	// 비어있는지 확인
	template <class T>
	bool Vector<T>::empty() {
		return this->size_ == 0;
	}

	// 뒤쪽 원소를 앞으로 한 칸씩 당겨서 덮어쓰기
	template <class T>
	void Vector<T>::erase(iterator it) {
		if (this->size_ == 0 || it < begin() || it >= end()) {
			return;
		}

		for (iterator p = it; p + 1 != end(); p++) {
			*p = *(p + 1);
		}

		this->size_--;
	}

	// 뒤쪽 원소를 한 칸씩 밀고 그 자리에 값 삽입
	template <class T>
	void Vector<T>::insert(iterator it, const T& value) {
		if (it < begin() || it > end()) {
			return;
		}

		size_t index = it - begin();

		if (this->size_ == capacity_) {
			grow();
		}

		for (size_t i = this->size_; i > index; i--) {
			this->data_[i] = this->data_[i - 1];
		}

		this->data_[index] = value;
		this->size_++;
	}

	// 원소 참조 리턴
	template <class T>
	T& Vector<T>::operator[](int index) {
		return this->data_[index];
	}

	// 배열을 새로 잡아서 값 복사 (깊은 복사)
	template <class T>
	Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
		if (this == &other) {
			return *this;
		}

		clear();

		capacity_ = other.capacity_;
		this->size_ = other.size_;

		if (capacity_ > 0) {
			this->data_ = new T[capacity_];
			for (size_t i = 0; i < this->size_; i++) {
				this->data_[i] = other.data_[i];
			}
		}

		return *this;
	}

	// 현재 용량 리턴
	template <class T>
	size_t Vector<T>::capacity() {
		return capacity_;
	}

	// 원소 개수 리턴
	template <class T>
	size_t Vector<T>::size() {
		return this->size_;
	}

	// 배열 해제 후 초기 상태로
	template <class T>
	void Vector<T>::clear() {
		if (this->data_ != nullptr) {
			delete[] this->data_;
			this->data_ = nullptr;
		}
		this->size_ = 0;
		capacity_ = 0;
	}

}

// 사용할 자료형 미리 생성
template class lkh::Vector<int>;
template class lkh::Vector<double>;
template class lkh::Vector<string>;