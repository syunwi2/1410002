#include "schedule.h"

/*
* GetTimeT(int year, int mon, int day, int hour, int min) {
* ��, ��, ��, �ð�, ���� ������ �޾�
* time_t Ÿ������ ��ȯ
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
* AVL Ʈ�� ������ ���� ��� �����̳� ���� ��
* ��带 �������� ������ ���� �κ��� ã��
* Ʈ���� ������ �����ϴ� ���� ����
*/
void BalanceTree(EVENT** root, EVENT* node)
{
	int BF;

	// root���� Ž���� ��ġ�� Ʈ���� ������ ���� �ʿ䰡 ����.
	if (node == NULL)
	{
		return;
	}

	// Ž�� ���� ��忡�� ������ �������� �˻��Ѵ�.
	BF = GetBalanceFactor(node);

	// Ž�� ���� ��尡 ������ ������ �ʾ����� �θ� ���� �ö� �˻��Ѵ�.
	if (-1 <= BF && BF <= 1)
	{
		BalanceTree(root, node->parent);
	}
	// Ž�� ���� ��忡�� ������ �����ٸ� �Ʒ��� 4���� ��� �� �ϳ��� �����Ѵ�.
	else if (1 < BF)
	{
		BF = GetBalanceFactor(node->prev);
		// 1. LL ����: ��ȸ��
		if (1 <= BF)
		{
			RightRotate(root, node);
		}
		// 2. LR ����: ��ȸ�� �� ��ȸ��
		else
		{
			LeftRotate(root, node);
			RightRotate(root, node);
		}
	}
	else
	{
		BF = GetBalanceFactor(node->next);
		// 3. RR ���� : ��ȸ��
		if (BF <= -1)
		{
			LeftRotate(root, node);
		}
		// 4. RL ���� : ��ȸ�� �� ��ȸ��
		else
		{
			RightRotate(root, node);
			LeftRotate(root, node);
		}
	}

}

/*
* GetBalanceFactor(EVENT* node)
* � ��带 �޾�
* �� ����� BalanceFactor�� ����� ��ȯ�Ѵ�.
*/
int GetBalanceFactor(EVENT* node)
{
	return GetHeight(node->prev) - GetHeight(node->next);
}

/*
* GetHeight(EVENT* node)
* � ��带 �޾�
* �� ����� ���̸� ����� ��ȯ�Ѵ�.
*/
int GetHeight(EVENT* node)
{
	// ��� �Լ� Ż�� ����
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
* node�� root�� �ϴ� ���� Ʈ���� ��ȸ�� �Ѵ�.
* �ʿ��ϴٸ� ���� Ʈ���� root�� �����Ѵ�.
*/
void LeftRotate(EVENT** root, EVENT* node)
{
	EVENT* nextNode;

	nextNode = node->next;

	// ��ȸ��
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

	// �ʿ�� root ����
	if (nextNode->parent == NULL)
	{
		*root = nextNode;
	}
}

/*
* RightRotate(EVENT** root, EVENT* node)
* node�� root�� �ϴ� ���� Ʈ���� ��ȸ�� �Ѵ�.
* �ʿ��ϴٸ� ���� Ʈ���� root�� �����Ѵ�.
*/
void RightRotate(EVENT** root, EVENT* node)
{
	EVENT* prevNode;

	prevNode = node->prev;

	// ��ȸ��
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

	// �ʿ�� root ����
	if (prevNode->parent == NULL)
	{
		*root = prevNode;
	}
}
