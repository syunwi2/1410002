#include "update.h"

void UpdateEvent(EVENT** root)
{
	int chk;
	int i;
	long long int tmp;
	EVENT* node = root;
	printf("������ ���� �� �� �ֽ��ϴ�. \n");
	printf("� ������ �����Ͻðڽ��ϱ�? \n");
	//���� ��ü ���
	do
	{
		printf("���� �ٽ� Ȯ���ϱ� y or n");
		scanf_s("%d", &chk);
	} while (chk != 1 && chk != 2);
	if (chk == 1)
	{
		PersonalReadEvent(root);
	}

	//���� ��� ����

	printf("choice");
	scanf_s("%d", &tmp);
	while (node != NULL && tmp != node->start) {
		if ( node->start < tmp) {
			node = node->prev;
		}
		else {
			node = node->next;
		}
	}

	//�������Ͽ��� ����
//	DeleteEvent(root, ptr);
//	CreateNewEvent(root, id, start, end, title, tag, isPublic, imPortanceLevel);
//	//�����Ͽ��� ����
//	DeleteEvent(root, ptr);
//	CreateNewEvent(root, id, start, end, title, tag, isPublic, imPortanceLevel);
}