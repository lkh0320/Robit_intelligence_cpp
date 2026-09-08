#include "ArrayCal.h"

// main 함수에서는 객체를 1개만 만들고, 멤버함수를 순서대로 호출함
int main()
{
	ArrayCal hw1;		// 클래스 객체 생성 (생성자 자동 호출)

	hw1.setNum();		// 원소 개수 입력 + 동적할당
	hw1.inputData();	// 데이터 입력
	hw1.calMax();		// 최대값 계산
	hw1.calMin();		// 최소값 계산
	hw1.calSum();		// 전체 합 계산
	hw1.calAvg();		// 평균 계산
	hw1.printResult();	// 결과 출력

	return 0;			// main이 끝나면 소멸자가 자동 호출되어 메모리 해제
}