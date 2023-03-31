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
* red-black 트리 유지를 위해 노드 생성이나 삭제 시
* 노드를 시작으로 균형이 깨진 부분을 찾아
* 트리의 균형을 유지하는 동작 실행
*/
void BalanceTree(EVENT** root, EVENT* node)
{
	