#include "read.h"

void ReadEvent(EVENT* root)
{
	EVENT* ptr;
	ptr = root;
	
	int tmp;
	
	do {

	printf("���� ������ ����ϼ���. \n");
	printf("��ü ���� ��� : 1 \n");
	printf("���� ���� ��� : 2 \n");
	printf("ȸ�� ���� ��� : 3 \n");
	printf("��Ÿ ���� ��� : 4 \n");
	scanf_s("%d", &tmp);
	} while (tmp != 1 && tmp != 2 && tmp != 3 && tmp != 4);

	if (tmp==1)
	{
		while (ptr)
		{
			printf("%s %d %d %s %s %d %d", ptr->ownerID, ptr->start, ptr->end,
				ptr->tag, ptr->isPublic, ptr->importanceLevel);
			ptr = ptr->next;
		}
	}
	else if (tmp == 1)
	{
		while (ptr)
		{
			if (ptr->tag == 1)
			{
				printf("%s %d %d %s %s %d %d", ptr->ownerID, ptr->start, ptr->end,
					ptr->tag, ptr->isPublic, ptr->importanceLevel);
			}
			ptr = ptr->next;
		}
	}
	else if (tmp == 2)
	{
		while (ptr)
		{
			if (ptr->tag == 0)
			{
				printf("%s %d %d %s %s %d %d", ptr->ownerID, ptr->start, ptr->end,
					ptr->tag, ptr->isPublic, ptr->importanceLevel);
			}
			ptr = ptr->next;
		}
	}
	else if (tmp == 3)
	{
		while (ptr)
		{
			if (ptr->tag == 2)
			{
				printf("%s %d %d %s %s %d %d", ptr->ownerID, ptr->start, ptr->end,
					ptr->tag, ptr->isPublic, ptr->importanceLevel);
			}
			ptr = ptr->next;
		}
	}
}