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
	start = GetTimeT(2023, 3, 30, 12, 00);
	end = GetTimeT(2023, 3, 30, 13, 00);
	title = "title";
	tag = 회사;
	isPublic = 1;
	importanceLevel = 1;

	CreateEvent(&myEvent, "id", start, end, title, tag, isPublic, importanceLevel);

	*myEvent;
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
* 
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

	InsertEvent(root, newNode);
}

/*
* 
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

	return;
}