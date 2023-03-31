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

	// ù �̺�Ʈ
	start = GetTimeT(2023, 3, 30, 12, 00);
	end = GetTimeT(2023, 3, 30, 13, 00);
	title = "title";
	tag = ȸ��;
	isPublic = 1;
	importanceLevel = 3;
	CreateEvent(&myEvent, "id", start, end, title, tag, isPublic, importanceLevel);

	// �� ��° �̺�Ʈ
	start = GetTimeT(2023, 2, 28, 12, 00);
	end = GetTimeT(2023, 2, 28, 13, 00);
	title = "title";
	tag = ȸ��;
	isPublic = 1;
	importanceLevel = 1;
	CreateEvent(&myEvent, "id", start, end, title, tag, isPublic, importanceLevel);

	// �� ��° �̺�Ʈ
	start = GetTimeT(2023, 4, 28, 12, 00);
	end = GetTimeT(2023, 4, 28, 13, 00);
	title = "title";
	tag = ȸ��;
	isPublic = 1;
	importanceLevel = 4;
	CreateEvent(&myEvent, "id", start, end, title, tag, isPublic, importanceLevel);

	// �� ��° �̺�Ʈ
	start = GetTimeT(2023, 3, 28, 12, 00);
	end = GetTimeT(2023, 3, 28, 13, 00);
	title = "title";
	tag = ȸ��;
	isPublic = 1;
	importanceLevel = 2;
	CreateEvent(&myEvent, "id", start, end, title, tag, isPublic, importanceLevel);

	// �ټ� ��° �̺�Ʈ
	start = GetTimeT(2023, 1, 28, 12, 00);
	end = GetTimeT(2023, 1, 28, 13, 00);
	title = "title";
	tag = ȸ��;
	isPublic = 1;
	importanceLevel = 0;
	CreateEvent(&myEvent, "id", start, end, title, tag, isPublic, importanceLevel);

	// ���� ��° �̺�Ʈ
	start = GetTimeT(2023, 5, 28, 12, 00);
	end = GetTimeT(2023, 5, 28, 13, 00);
	title = "title";
	tag = ȸ��;
	isPublic = 1;
	importanceLevel = 5;
	CreateEvent(&myEvent, "id", start, end, title, tag, isPublic, importanceLevel);

	DeleteEvent(&myEvent, myEvent->prev);
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
* CreateEvent(EVENT** root, char* id, time_t start, time_t end, char* title, TAG tag, int isPublic, int imPortanceLevel)
* ��忡 ����� �����͸� �޾�
* ���� Ʈ���� �����մϴ�.
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
	newNode->contNext = NULL;
	newNode->contPrev = NULL;
	newNode->parent = NULL;
	newNode->prev = NULL;
	newNode->next = NULL;

	InsertEvent(root, newNode);
}

/*
* InsertEvent(EVENT** root, EVENT* newNode)
* CreateEvent�� ���� ȣ��Ǿ�
* ���� Ʈ���� ��Ʈ�� ���Ե� ��带 �޾�
* ��带 ���� Ʈ���� �����մϴ�.
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
					newNode->parent = tmp;
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
					newNode->parent = tmp;
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
	UpdateRoot(root);

	return;
}

/*
* DeleteEvent(EVNET** root, EVENT* node)
* ������ ���� ����� ���� Ʈ�� root�� �޾�
* �����մϴ�.
*/
void DeleteEvent(EVENT** root, EVENT* node)
{
	EVENT* tmp;
	// ���ӵ� ���� ���� ���� �ʿ�

	// ----- root ����� ��� -----
	if (node->parent == NULL)
	{
		// root�� ���� ������ ���� ������ ��� �ִ� ���
		if (((node->prev) != NULL) && ((node->next) != NULL))
		{
			// root�� ���� ����� ������ ã�� root�� �ִ´�.
			tmp = FindNext(node);
			CopyEvent(node, tmp);
			
			// ã�� ��� ����
			DeleteEvent(root, tmp);

			return;
		}
		// root�� ���� Ȥ�� ���� ������ �ִ� ���
		else if (((node->prev) != NULL) || ((node->next) != NULL))
		{
			// root�� prev�� next ��带 root�� �����Ѵ�.
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
		// root�� �ִ� ���
		else
		{
			// Ʈ���� root�� NULL�� �����Ѵ�.
			*root = NULL;
		}
	}

	// ----- �Ϲ� node�� ��� ----
	else {
		// node�� ���� ������ ���� ������ ��� �ִ� ���
		if (((node->prev) != NULL) && ((node->next) != NULL))
		{
			// node�� ���� ����� ������ ã�� node�� �ִ´�.
			tmp = FindNext(node);
			CopyEvent(node, tmp);

			// ã�� ��� ����
			DeleteEvent(root, tmp);

			return;
		}
		// node�� ���� Ȥ�� ���� ������ �ִ� ���
		else if (((node->prev) != NULL) || ((node->next) != NULL))
		{
			// �θ� ����� prev�� next ��带 ����� prev�� next�� �����Ѵ�.
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
		// node�� ���� Ȥ�� ���� ������ ���� ���
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

/*
* FindNext(EVENT* node)
* �ϳ��� ������ �޾�
* ��¥������ �� ������ ���� ����� ������ ã�� ��ȯ�Ѵ�.
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
* from ����� ������ to ��忡 �����Ѵ�.
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