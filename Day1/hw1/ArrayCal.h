#ifndef ARRAYCAL_H
#define ARRAYCAL_H

// 배열의 최대, 최소, 합, 평균을 구하는 클래스 선언부
class ArrayCal
{
private:
	int num;		// 할당할 원소의 개수
	int *arr;		// 동적할당으로 만들 배열의 시작 주소
	int i;			// 반복문에서 사용할 변수 (멤버변수로 선언)
	int max;		// 최대값
	int min;		// 최소값
	int sum;		// 전체 합
	double avg;		// 평균

public:
	ArrayCal();		// 생성자 (멤버변수 초기화)
	~ArrayCal();	// 소멸자 (동적할당 받은 메모리 해제)

	void setNum();		// 원소의 개수를 입력받고 그 개수만큼 동적할당
	void inputData();	// 배열에 정수형 데이터를 입력받는 함수
	void calMax();		// 최대값을 구하는 함수
	void calMin();		// 최소값을 구하는 함수
	void calSum();		// 전체 합을 구하는 함수
	void calAvg();		// 평균을 구하는 함수
	void printResult();	// 결과를 출력하는 함수
};

#endif