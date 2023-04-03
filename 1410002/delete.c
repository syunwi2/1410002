#include "delete.h"

/*
* DeleteEvent(EVNET** root, EVENT* node)
* ������ ���� ����� ���� Ʈ�� root�� �޾�
* �����մϴ�.
*/
void DeleteEvent(EVENT** root, EVENT* node)
{
	EVENT* tmp;

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
	
	BalanceTree(*root, node);

	free(node);
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
}
