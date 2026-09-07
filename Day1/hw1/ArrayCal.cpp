#include <iostream>
#include <cstdio>	// 평균을 소수점 6자리로 출력하기 위해 사용
#include "ArrayCal.h"

using namespace std;

// 생성자 : 객체가 생성될 때 자동으로 호출되어 멤버변수를 초기화함
ArrayCal::ArrayCal()
{
	this->num = 0;
	this->arr = NULL;
	this->i = 0;
	this->max = 0;
	this->min = 0;
	this->sum = 0;
	this->avg = 0;
}

// 소멸자 : 객체가 소멸될 때 자동으로 호출되어 동적할당 받은 메모리를 해제함
ArrayCal::~ArrayCal()
{
	delete[] this->arr;
}

// 원소의 개수를 입력받고, 그 개수만큼 배열을 동적할당 하는 함수
void ArrayCal::setNum()
{
	cout << "몇 개의 원소를 할당하겠습니까? : ";
	cin >> this->num;

	this->arr = new int[this->num];		// 입력받은 개수만큼 메모리 할당
}

// 할당한 배열에 정수형 데이터를 하나씩 입력받는 함수
void ArrayCal::inputData()
{
	for (this->i = 0; this->i < this->num; this->i++)
	{
		cout << "정수형 데이터 입력:";
		cin >> this->arr[this->i];
	}
}

// 최대값을 구하는 함수
// 처음 값을 최대값이라고 가정하고, 더 큰 값이 나오면 바꿔줌
void ArrayCal::calMax()
{
	this->max = this->arr[0];

	for (this->i = 1; this->i < this->num; this->i++)
	{
		if (this->arr[this->i] > this->max)
		{
			this->max = this->arr[this->i];
		}
	}
}

// 최소값을 구하는 함수
// 처음 값을 최소값이라고 가정하고, 더 작은 값이 나오면 바꿔줌
void ArrayCal::calMin()
{
	this->min = this->arr[0];

	for (this->i = 1; this->i < this->num; this->i++)
	{
		if (this->arr[this->i] < this->min)
		{
			this->min = this->arr[this->i];
		}
	}
}

// 배열의 값들을 모두 더해서 전체 합을 구하는 함수
void ArrayCal::calSum()
{
	this->sum = 0;

	for (this->i = 0; this->i < this->num; this->i++)
	{
		this->sum = this->sum + this->arr[this->i];
	}
}

// 평균을 구하는 함수 (전체 합 / 원소의 개수)
// sum과 num이 둘 다 int라서 그냥 나누면 소수점이 없어지기 때문에 double로 형변환 해줌
void ArrayCal::calAvg()
{
	this->avg = (double)this->sum / this->num;
}

// 구한 결과들을 화면에 출력하는 함수
void ArrayCal::printResult()
{
	cout << "최대값: " << this->max << endl;
	cout << "최소값: " << this->min << endl;
	cout << "전체합: " << this->sum << endl;
	printf("평 균: %lf\n", this->avg);
}