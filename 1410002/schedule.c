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
	int BF;

	// root까지 탐색을 마치면 트리의 균형을 맞출 필요가 없다.
	if (node == NULL)
	{
		return;
	}

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
		// 1. LL 형태: 우회전
		if (1 <= BF)
		{
			RightRotate(root, node);
		}
		// 2. LR 형태: 좌회전 후 우회전
		else
		{
			LeftRotate(root, node);
			RightRotate(root, node);
		}
	}
	else
	{
		BF = GetBalanceFactor(node->next);
		// 3. RR 형태 : 좌회전
		if (BF <= -1)
		{
			LeftRotate(root, node);
		}
		// 4. RL 형태 : 우회전 후 좌회전
		else
		{
			RightRotate(root, node);
			LeftRotate(root, node);
		}
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

/*
* LeftRotate(EVENT** root, EVENT* node)
* node를 root로 하는 서브 트리를 좌회전 한다.
* 필요하다면 이진 트리의 root를 변경한다.
*/
void LeftRotate(EVENT** root, EVENT* node)
{
	EVENT* nextNode;

	nextNode = node->next;

	// 좌회전
	node->next = nextNode->prev;
	if (nextNode->prev != NULL)
	{
		nextNode->prev->parent = node;
	}
	nextNode->prev = node;
	nextNode->parent = node->parent;
	if (node->parent != NULL)
	{
		if (node->parent->prev == node)
		{
			node->parent->prev = nextNode;
		}
		else
		{
			node->parent->next = nextNode;
		}
	}
	node->parent = nextNode;

	// 필요시 root 변경
	if (nextNode->parent == NULL)
	{
		*root = nextNode;
	}
}

/*
* RightRotate(EVENT** root, EVENT* node)
* node를 root로 하는 서브 트리를 우회전 한다.
* 필요하다면 이진 트리의 root를 변경한다.
*/
void RightRotate(EVENT** root, EVENT* node)
{
	EVENT* prevNode;

	prevNode = node->prev;

	// 우회전
	node->prev = prevNode->next;
	if (prevNode->next != NULL)
	{
		prevNode->next->parent = node;
	}
	prevNode->next = node;
	prevNode->parent = node->parent;
	if (node->parent != NULL)
	{
		if (node->parent->prev == node)
		{
			node->parent->prev = prevNode;
		}
		else
		{
			node->parent->next = prevNode;
		}
	}
	node->parent = prevNode;

	// 필요시 root 변경
	if (prevNode->parent == NULL)
	{
		*root = prevNode;
	}
}
