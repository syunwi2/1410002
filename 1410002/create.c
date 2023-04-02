#include "create.h"

/*
* CreateNewEvent(EVENT** root, char* id, time_t start, time_t end, char* title, TAG tag, int isPublic, int imPortanceLevel)
* 노드에 저장될 데이터를 받아
* 이진 트리에 삽입합니다.
*/

void CreateEventScreen()
{
	system("cls");
	gotoxy(3, 1);
	// Heap에서 데이터 사용
	printf("======== 일정 생성 ========= \n");
	printf("\n\n 일시 (YYYY-MM-DD) : ");s
	// 입력
	printf("일정 내용 : ");
	// 입력


}


void CreateNewEvent(EVENT** root, char* id, time_t start, time_t end, char* title, TAG tag, int isPublic, int imPortanceLevel)
{
	EVENT* newNode;

	newNode = (EVENT*)malloc(sizeof(EVENT));
	if (newNode == NULL)
	{
		perror("CreateEvent() :: Error :");
		exit(1);
	}

	strcpy(newNode->ownerID, id);
	newNode->start = start;
	newNode->end = end;
	strcpy(newNode->title, title);
	newNode->tag = tag;
	newNode->isPublic = isPublic;
	newNode->importanceLevel = imPortanceLevel;
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