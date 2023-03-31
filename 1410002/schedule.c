#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "schedule.h"

// 테스트 함수
void test() {
	EVENT* myEvent;
	char* id;
	time_t start;
	time_t end;
	char* title;
	TAG tag;
	int isPublic;
	int importanceLevel;

	myEvent = NULL;
	id = "id";

	// 첫 이벤트
	start = GetTimeT(2023, 3, 30, 12, 00);
	end = GetTimeT(2023, 3, 30, 13, 00);
	title = "title";
	tag = 회사;
	isPublic = 1;
	importanceLevel = 3;
	CreateEvent(&myEvent, "id", start, end, title, tag, isPublic, importanceLevel);

	// 두 번째 이벤트
	start = GetTimeT(2023, 2, 28, 12, 00);
	end = GetTimeT(2023, 2, 28, 13, 00);
	title = "title";
	tag = 회사;
	isPublic = 1;
	importanceLevel = 1;
	CreateEvent(&myEvent, "id", start, end, title, tag, isPublic, importanceLevel);

	// 세 번째 이벤트
	start = GetTimeT(2023, 4, 28, 12, 00);
	end = GetTimeT(2023, 4, 28, 13, 00);
	title = "title";
	tag = 회사;
	isPublic = 1;
	importanceLevel = 4;
	CreateEvent(&myEvent, "id", start, end, title, tag, isPublic, importanceLevel);

	// 네 번째 이벤트
	start = GetTimeT(2023, 3, 28, 12, 00);
	end = GetTimeT(2023, 3, 28, 13, 00);
	title = "title";
	tag = 회사;
	isPublic = 1;
	importanceLevel = 2;
	CreateEvent(&myEvent, "id", start, end, title, tag, isPublic, importanceLevel);

	// 다섯 번째 이벤트
	start = GetTimeT(2023, 1, 28, 12, 00);
	end = GetTimeT(2023, 1, 28, 13, 00);
	title = "title";
	tag = 회사;
	isPublic = 1;
	importanceLevel = 0;
	CreateEvent(&myEvent, "id", start, end, title, tag, isPublic, importanceLevel);

	// 여섯 번째 이벤트
	start = GetTimeT(2023, 5, 28, 12, 00);
	end = GetTimeT(2023, 5, 28, 13, 00);
	title = "title";
	tag = 회사;
	isPublic = 1;
	importanceLevel = 5;
	CreateEvent(&myEvent, "id", start, end, title, tag, isPublic, importanceLevel);

	DeleteEvent(&myEvent, myEvent->prev);
}

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
* CreateEvent(EVENT** root, char* id, time_t start, time_t end, char* title, TAG tag, int isPublic, int imPortanceLevel)
* 노드에 저장될 데이터를 받아
* 이진 트리에 삽입합니다.
*/
void CreateEvent(EVENT** root, char* id, time_t start, time_t end, char* title, TAG tag, int isPublic, int imPortanceLevel)
{
	EVENT* newNode;

	newNode = (EVENT*)malloc(sizeof(EVENT));
	if (newNode == NULL)
	{
		perror("CreateEvent() :: Error :");
		exit(1);
	}
	// 여러 날에 이어진 일정 쪼개기 구현 필요
	strcpy(newNode->ownerID, id);
	newNode->start = start;
	newNode->end = end;
	strcpy(newNode->title, title);
	newNode->tag = tag;
	newNode->isPublic = isPublic;
	newNode->importanceLevel = imPortanceLevel;
	newNode->contNext = NULL;
	newNode->contPrev = NULL;
	newNode->parent = NULL;
	newNode->prev = NULL;
	newNode->next = NULL;

	InsertEvent(root, newNode);
}

/*
* InsertEvent(EVENT** root, EVENT* newNode)
* CreateEvent에 의해 호출되어
* 이진 트리의 루트와 삽입될 노드를 받아
* 노드를 이진 트리에 삽입합니다.
*/
void InsertEvent(EVENT** root, EVENT* newNode)
{
	// root가 없으면 이진 트리를 만든다
	if (*root == NULL)
	{
		*root = newNode;
		return;
	}
	// root가 있으면 이진 트리에 newNode를 삽입한다.
	else
	{
		EVENT* tmp;

		// root부터 탐색을 시작한다.
		tmp = *root;
		while (1)
		{
			// 탐색 중인 노드보다 삽입할 노드의 시작일이 빠른 경우
			if (newNode->start < tmp->start)
			{
				// 현재 탐색 중인 노드 이전 일정이 없으면 이 위치에 삽입한다.
				if (tmp->prev == NULL)
				{
					tmp->prev = newNode;
					newNode->parent = tmp;
					break;
				}
				// 현재 탐색 중인 노드의 이전 일정이 있으면 해당 노드를 기준으로 다시 탐색한다.
				else
				{
					tmp = tmp->prev;
				}
			}
			// 탐색 중인 노드보다 삽입할 노드의 시작일이 느린 경우
			else
			{
				// 현재 탐색 중인 노드 이후 일정이 없으면 이 위치에 삽입한다.
				if (tmp->next == NULL)
				{
					tmp->next = newNode;
					newNode->parent = tmp;
					break;
				}
				// 현재 탐색 중인 노드 이후 일정이 있으면 해당 노드를 기준으로 다시 탐색한다.
				else
				{
					tmp = tmp->next;
				}
			}
		}
	}

	// AVL(완전 이진 트리) 구현 위해 루트 변환 필요
	UpdateRoot(root);

	return;
}

/*
* DeleteEvent(EVNET** root, EVENT* node)
* 삭제할 노드와 노드의 이진 트리 root를 받아
* 삭제합니다.
*/
void DeleteEvent(EVENT** root, EVENT* node)
{
	EVENT* tmp;
	// 연속된 일정 삭제 구현 필요

	// ----- root 노드인 경우 -----
	if (node->parent == NULL)
	{
		// root의 이전 일정과 이후 일정이 모두 있는 경우
		if (((node->prev) != NULL) && ((node->next) != NULL))
		{
			// root와 가장 가까운 일정을 찾아 root에 넣는다.
			tmp = FindNext(node);
			CopyEvent(node, tmp);
			
			// 찾은 노드 삭제
			DeleteEvent(root, tmp);

			return;
		}
		// root의 이전 혹은 이후 일정만 있는 경우
		else if (((node->prev) != NULL) || ((node->next) != NULL))
		{
			// root의 prev나 next 노드를 root로 수정한다.
			if (node->parent->prev == node)
			{
				tmp = (node->prev != NULL) ? node->prev : node->next;
				tmp->parent = NULL;
				*root = tmp;
			}
			else
			{
				tmp = (node->prev != NULL) ? node->prev : node->next;
				tmp->parent = NULL;
				*root = tmp;
			}
		}
		// root만 있는 경우
		else
		{
			// 트리의 root를 NULL로 수정한다.
			*root = NULL;
		}
	}

	// ----- 일반 node인 경우 ----
	else {
		// node의 이전 일정과 이후 일정이 모두 있는 경우
		if (((node->prev) != NULL) && ((node->next) != NULL))
		{
			// node와 가장 가까운 일정을 찾아 node에 넣는다.
			tmp = FindNext(node);
			CopyEvent(node, tmp);

			// 찾은 노드 삭제
			DeleteEvent(root, tmp);

			return;
		}
		// node의 이전 혹은 이후 일정만 있는 경우
		else if (((node->prev) != NULL) || ((node->next) != NULL))
		{
			// 부모 노드의 prev나 next 노드를 노드의 prev나 next로 수정한다.
			if (node->parent->prev == node)
			{
				tmp = (node->prev != NULL) ? node->prev : node->next;
				node->parent->prev = tmp;
				tmp->parent = node->parent;
			}
			else
			{
				tmp = (node->prev != NULL) ? node->prev : node->next;
				node->parent->next = tmp;
				tmp->parent = node->parent;
			}
		}
		// node의 이전 혹은 이후 일정이 없는 경우
		else
		{
			if (node->parent->prev == node)
			{
				node->parent->prev = NULL;
			}
			else
			{
				node->parent->next = NULL;
			}
		}
	}
	free(node);

	UpdateRoot(root);
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

/*
* FindNext(EVENT* node)
* 하나의 일정을 받아
* 날짜순으로 그 일정과 가장 가까운 일정을 찾아 반환한다.
*/
EVENT* FindNext(EVENT* node)
{
	EVENT* nextEvent;

	nextEvent = node->next;
	if (nextEvent->prev)
	{
		nextEvent = nextEvent->prev;
	}

	return nextEvent;
}

/*
* CopyEvent(EVENT* to, EVENT* from)
* from 노드의 일정을 to 노드에 복사한다.
*/
void CopyEvent(EVENT* to, EVENT* from)
{
	strcpy(to->ownerID, from->ownerID);
	to->start = from->start;
	to->end = from->start;
	strcpy(to->title, from->title);
	to->tag = from->tag;
	to->isPublic = from->isPublic;
	to->importanceLevel = from->importanceLevel;
	to->contPrev = from->contPrev;
	to->contNext = from->contNext;
}