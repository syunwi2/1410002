#include "schedule.h"

/*
* GetTimeT(int year, int mon, int day, int hour, int min) {
* 년, 월, 일, 시간, 분을 정수로 받아
* time_t 타입으로 변환
*/
time_t GetTimeT(int year, int mon, int day, int hour, int min)
{
	struct tm tmp = { 0 };
	tmp.tm_year = year - 1900;
	tmp.tm_mon = mon - 1;
	tmp.tm_mday = day;
	tmp.tm_hour = hour;
	tmp.tm_min = min;

	return mktime(&tmp);
}

/*
* UpdateRoot()
* AVL 기반 완전 이진 트리 유지를 위해 노드 생성이나 삭제 시
* 이진 트리의 root를 받아
* 새로운 root 탐색 및 반환
*/
void UpdateRoot(EVENT** root)
{
	// 이진 트리가 없는 경우 새 root를 찾을 필요가 없다.
	if (*root == NULL)
	{
		return;
	}

	int BF;
	BF = GetBalanceFactor(*root);

	// 이미 완전 이진 트리인 경우 새 root를 찾을 필요가 없다.
	if (-2 < BF && BF < 2)
	{
		return;
	}
}

/*
* GetBalanceFactor()
* 완전 이진 트리 유지를 위해
* BalanceFactor 계산해 반환
*/
int GetBalanceFactor(EVENT* root)
{
	return GetHeight(root->prev) - GetHeight(root->next);
}

/*
* GetHeight()
* BalanceFactor 계산 위해
* root->prev의 트리 높이, root->next의 트리 높이 계산해 반환
*/
int GetHeight(EVENT* node)
{
	// 재귀 함수 탈출 조건
	if (node == NULL)
	{
		return 0;
	}

	int left, right;

	left = 0;
	right = 0;

	if (node->prev)
	{
		left = GetHeight(node->prev);
	}
	if (node->next)
	{
		right = GetHeight(node->next);
	}

	return (left > right) ? left + 1 : right + 1;
}