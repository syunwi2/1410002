#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "schedule.h"

// �׽�Ʈ �Լ�
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
	tag = ȸ��;
	isPublic = 1;
	importanceLevel = 1;

	CreateEvent(&myEvent, "id", start, end, title, tag, isPublic, importanceLevel);

	*myEvent;
}

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
	// ���� ���� �̾��� ���� �ɰ��� ���� �ʿ�
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
	// root�� ������ ���� Ʈ���� �����
	if (*root == NULL)
	{
		*root = newNode;
		return;
	}
	// root�� ������ ���� Ʈ���� newNode�� �����Ѵ�.
	else
	{
		EVENT* tmp;

		// root���� Ž���� �����Ѵ�.
		tmp = *root;
		while (1)
		{
			// Ž�� ���� ��庸�� ������ ����� �������� ���� ���
			if (newNode->start < tmp->start)
			{
				// ���� Ž�� ���� ��� ���� ������ ������ �� ��ġ�� �����Ѵ�.
				if (tmp->prev == NULL)
				{
					tmp->prev = newNode;
					break;
				}
				// ���� Ž�� ���� ����� ���� ������ ������ �ش� ��带 �������� �ٽ� Ž���Ѵ�.
				else
				{
					tmp = tmp->prev;
				}
			}
			// Ž�� ���� ��庸�� ������ ����� �������� ���� ���
			else
			{
				// ���� Ž�� ���� ��� ���� ������ ������ �� ��ġ�� �����Ѵ�.
				if (tmp->next == NULL)
				{
					tmp->next = newNode;
					break;
				}
				// ���� Ž�� ���� ��� ���� ������ ������ �ش� ��带 �������� �ٽ� Ž���Ѵ�.
				else
				{
					tmp = tmp->next;
				}
			}
		}
	}

	// AVL(���� ���� Ʈ��) ���� ���� ��Ʈ ��ȯ �ʿ�

	return;
}