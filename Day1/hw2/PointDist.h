#ifndef POINTDIST_H
#define POINTDIST_H

// 2차원 좌표를 표현하기 위한 구조체
struct Point
{
	int nX;		// x 좌표
	int nY;		// y 좌표
};

// 점들 사이의 거리 중 최소값, 최대값과 그 두 점을 찾는 클래스 선언부
class PointDist
{
private:
	int num;			// 점의 개수
	int minCoor;		// 좌표의 범위 (최소값)
	int maxCoor;		// 좌표의 범위 (최대값)
	Point *p;			// 점들을 저장할 배열 (동적할당)

	int i;				// 반복문에서 사용할 변수
	int j;				// 반복문에서 사용할 변수 (두 번째 점을 고를 때)

	double dist;		// 두 점 사이의 거리를 잠깐 담아두는 변수
	double minDist;		// 거리의 최소값
	double maxDist;		// 거리의 최대값

	int minP1, minP2;	// 최소 거리를 가지는 두 점의 번호
	int maxP1, maxP2;	// 최대 거리를 가지는 두 점의 번호

public:
	PointDist();		// 생성자 (멤버변수 초기화)
	~PointDist();		// 소멸자 (동적할당 받은 메모리 해제)

	void inputInfo();				// 점의 개수와 좌표 범위를 cin으로 입력받고 동적할당
	void makeRandomPoint();			// 정해진 범위 안에서 점을 랜덤으로 생성하고 출력
	double calDist(int a, int b);	// a번 점과 b번 점 사이의 거리를 구해서 돌려주는 함수
	void findMinMax();				// 모든 점의 짝을 비교해서 최소/최대 거리를 찾는 함수
	void printResult();				// 결과를 출력하는 함수
};

#endif