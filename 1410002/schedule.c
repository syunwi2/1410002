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
* 완전 이진 트리 유지를 위해 노드 생성이나 삭제 시
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

	EVENT* newRoot;

	newRoot = *root;
	*root = newRoot;
}