#include "delete.h"

/*
* DeleteEvent(EVNET** root, EVENT* node)
* 삭제할 노드와 노드의 이진 트리 root를 받아
* 삭제합니다.
*/
void DeleteEvent(EVENT** root, EVENT* node)
{
	EVENT* tmp;

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
			if (node->prev)
			{
				tmp = node->prev;

				tmp->parent = NULL;
				*root = tmp;
			}
			else
			{
				tmp = node->next;
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
	
	BalanceTree(*root, node);

	free(node);
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
}
