#include "create.h"

/*
* CreateNewEvent(EVENT** root, char* id, time_t start, time_t end, char* title, TAG tag, int isPublic, int imPortanceLevel)
* ��忡 ����� �����͸� �޾�
* ���� Ʈ���� �����մϴ�.
*/

void CreateEventScreen()
{
	system("cls");
	gotoxy(3, 1);
	// Heap���� ������ ���
	printf("======== ���� ���� ========= \n");
	printf("\n\n �Ͻ� (YYYY-MM-DD) : ");s
	// �Է�
	printf("���� ���� : ");
	// �Է�


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