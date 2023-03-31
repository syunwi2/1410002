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
* ���� ���� Ʈ�� ������ ���� ��� �����̳� ���� ��
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

	EVENT* newRoot;

	newRoot = *root;
	*root = newRoot;
}