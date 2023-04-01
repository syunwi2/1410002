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
* BalanceTree()
* AVL 트리 유지를 위해 노드 생성이나 삭제 시
* 노드를 시작으로 균형이 깨진 부분을 찾아
* 트리의 균형을 유지하는 동작 실행
*/
void BalanceTree(EVENT** root, EVENT* node)
{
	// root까지 탐색을 마치면 트리의 균형을 맞출 필요가 없다.
	if (node == NULL)
	{
		return;
	}

	int BF;
	// 탐색 중인 노드에서 균형이 깨졌는지 검사한다.
	BF = GetBalanceFactor(node);

	// 탐색 중인 노드가 균형이 깨지지 않았으면 부모 노드로 올라가 검사한다.
	if (-1 <= BF && BF <= 1)
	{
		BalanceTree(root, node->parent);
	}
	// 탐색 중인 노드에서 균형이 깨졌다면 아래의 4가지 방법 중 하나를 시행한다.
	else if (1 < BF)
	{
		BF = GetBalanceFactor(node->prev);
		// 1. LL 회전
		if (1 <= BF)
		{

		}
		// 2. LR 회전
	}

}

/*
* GetBalanceFactor(EVENT* node)
* 어떤 노드를 받아
* 그 노드의 BalanceFactor를 계산해 반환한다.
*/
int GetBalanceFactor(EVENT* node)
{
	return GetHeight(node->prev) - GetHeight(node->next);
}

/*
* GetHeight(EVENT* node)
* 어떤 노드를 받아
* 그 노드의 높이를 계산해 반환한다.
*/
int GetHeight(EVENT* node)
{
	// 재귀 함수 탈출 조건
	if (node == NULL)
	{
		return 0;
	}

	int leftHeight, rightHeight, Height;

	leftHeight = GetHeight(node->prev);
	rightHeight = GetHeight(node->next);
	Height = (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;

	return Height;
}