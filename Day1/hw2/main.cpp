#include "PointDist.h"

// main 함수에서는 객체를 1개만 만들고, 멤버함수를 순서대로 호출함
int main()
{
	PointDist hw2;

	hw2.inputInfo();		// 점의 개수, 좌표 범위 입력 + 동적할당
	hw2.makeRandomPoint();	// 범위 안에서 점을 랜덤으로 생성
	hw2.findMinMax();		// 최소 거리, 최대 거리 찾기
	hw2.printResult();		// 결과 출력

	return 0;
}