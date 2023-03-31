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
* UpdateRoot()
* AVL ��� ���� ���� Ʈ�� ������ ���� ��� �����̳� ���� ��
* ���� Ʈ���� root�� �޾�
* ���ο� root Ž�� �� ��ȯ
*/
void UpdateRoot(EVENT** root)
{
	// ���� Ʈ���� ���� ��� �� root�� ã�� �ʿ䰡 ����.
	if (*root == NULL)
	{
		return;
	}

	int BF;
	BF = GetBalanceFactor(*root);

	// �̹� ���� ���� Ʈ���� ��� �� root�� ã�� �ʿ䰡 ����.
	if (-2 < BF && BF < 2)
	{
		return;
	}
}

/*
* GetBalanceFactor()
* ���� ���� Ʈ�� ������ ����
* BalanceFactor ����� ��ȯ
*/
int GetBalanceFactor(EVENT* root)
{
	return GetHeight(root->prev) - GetHeight(root->next);
}

/*
* GetHeight()
* BalanceFactor ��� ����
* root->prev�� Ʈ�� ����, root->next�� Ʈ�� ���� ����� ��ȯ
*/
int GetHeight(EVENT* node)
{
	// ��� �Լ� Ż�� ����
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