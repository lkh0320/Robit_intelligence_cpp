#include <iostream>
#include <cstdlib>	// 랜덤값을 만드는 rand(), srand() 사용
#include <ctime>	// srand()에 넣을 현재 시간 time() 사용
#include <cmath>	// 제곱근 sqrt() 사용
#include "PointDist.h"

using namespace std;

// 생성자 : 객체가 생성될 때 자동으로 호출되어 멤버변수를 초기화함
PointDist::PointDist()
{
	this->num = 0;
	this->minCoor = 0;
	this->maxCoor = 0;
	this->p = 0;

	this->i = 0;
	this->j = 0;

	this->dist = 0;
	this->minDist = 0;
	this->maxDist = 0;

	this->minP1 = 0;
	this->minP2 = 0;
	this->maxP1 = 0;
	this->maxP2 = 0;
}

// 소멸자 : 객체가 소멸될 때 자동으로 호출되어 동적할당 받은 메모리를 해제함
PointDist::~PointDist()
{
	delete[] this->p;
}

// 점의 개수와 좌표의 범위를 cin으로 입력받고, 개수만큼 점 배열을 동적할당 하는 함수
void PointDist::inputInfo()
{
	cout << "======= HW 2 Point Distance Computation ========" << endl << endl;

	cout << "Please define the number of points: ";
	cin >> this->num;

	cout << "Please define minimum of coor. value: ";
	cin >> this->minCoor;

	cout << "Please define maximum of coor. value: ";
	cin >> this->maxCoor;

	this->p = new Point[this->num];		// 입력받은 개수만큼 메모리 할당
}

// 정해진 범위 안에서 점을 랜덤으로 생성하고 화면에 출력하는 함수
// rand()를 그냥 쓰면 실행할 때마다 같은 값이 나와서 srand()로 시간을 넣어줌
void PointDist::makeRandomPoint()
{
	srand((unsigned int)time(0));

	cout << endl << "Generate Random points" << endl;

	for (this->i = 0; this->i < this->num; this->i++)
	{
		// rand()를 범위의 크기로 나눈 나머지를 구하면 0 ~ (범위-1) 이 나오고,
		// 거기에 최소값을 더해주면 minCoor ~ maxCoor 사이의 값이 됨
		this->p[this->i].nX = rand() % (this->maxCoor - this->minCoor + 1) + this->minCoor;
		this->p[this->i].nY = rand() % (this->maxCoor - this->minCoor + 1) + this->minCoor;

		cout << "Point " << this->i + 1 << ". nX=" << this->p[this->i].nX
			 << " , nY=" << this->p[this->i].nY << endl;
	}
}

// a번 점과 b번 점 사이의 거리를 구해서 돌려주는 함수
// 피타고라스 정리 : 루트( (x1-x2)^2 + (y1-y2)^2 )
double PointDist::calDist(int a, int b)
{
	int dx;
	int dy;

	dx = this->p[a].nX - this->p[b].nX;
	dy = this->p[a].nY - this->p[b].nY;

	return sqrt((double)(dx * dx + dy * dy));
}

// 모든 두 점의 짝을 하나씩 비교해서 최소 거리와 최대 거리를 찾는 함수
// i번 점과 j번 점을 비교하는데, j는 i보다 뒤쪽 점만 보면 같은 짝을 두 번 안 셈
void PointDist::findMinMax()
{
	// 맨 처음 짝인 0번과 1번의 거리를 최소값이자 최대값이라고 일단 정해둠
	this->minDist = this->calDist(0, 1);
	this->maxDist = this->minDist;

	this->minP1 = 0;
	this->minP2 = 1;
	this->maxP1 = 0;
	this->maxP2 = 1;

	for (this->i = 0; this->i < this->num; this->i++)
	{
		for (this->j = this->i + 1; this->j < this->num; this->j++)
		{
			this->dist = this->calDist(this->i, this->j);

			if (this->dist < this->minDist)		// 더 가까운 짝이 나오면 바꿔줌
			{
				this->minDist = this->dist;
				this->minP1 = this->i;
				this->minP2 = this->j;
			}

			if (this->dist > this->maxDist)		// 더 먼 짝이 나오면 바꿔줌
			{
				this->maxDist = this->dist;
				this->maxP1 = this->i;
				this->maxP2 = this->j;
			}
		}
	}
}

// 찾은 결과들을 화면에 출력하는 함수
void PointDist::printResult()
{
	cout << endl << "-------- Result --------" << endl;

	cout << "MinDist :" << this->minDist << endl;
	cout << "Pair of Min Coor.(x,y): P1(" << this->p[this->minP1].nX << ","
		 << this->p[this->minP1].nY << ") & P2(" << this->p[this->minP2].nX << ","
		 << this->p[this->minP2].nY << ")" << endl << endl;

	cout << "MaxDist =" << this->maxDist << endl;
	cout << "Pair of Max Coor.(x,y): P1(" << this->p[this->maxP1].nX << ","
		 << this->p[this->maxP1].nY << ") & P2(" << this->p[this->maxP2].nX << ","
		 << this->p[this->maxP2].nY << ")" << endl << endl;

	cout << "========== Completed ==============" << endl;
}