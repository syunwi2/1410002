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
	// root���� Ž���� ��ġ�� Ʈ���� ������ ���� �ʿ䰡 ����.
	if (node == NULL)
	{
		return;
	}

	int BF;
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
		// 1. LL ȸ��
		if (1 <= BF)
		{

		}
		// 2. LR ȸ��
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