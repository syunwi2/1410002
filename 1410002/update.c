#include "update.h"

void UpdateEvent(EVENT** root, EVENT* node)
{
	int chk;
	EVENT* ptr = node;
	printf("������ ���� �� �� �ֽ��ϴ�. \n");
	printf("� ������ �����Ͻðڽ��ϱ�? \n");
	//���� ��ü ���
<<<<<<< HEAD
	do
	{
		printf("���� �ٽ� Ȯ���ϱ� y or n");
		scanf_s("%d", &chk);
	} while (chk != 1 && chk != 2);
	if (chk == 1)
	{
		PersonalReadEvent(root);
	}
	
=======
	PersonalReadEvent(root);

>>>>>>> 8447fa898f2b65bc4dfa3b8042e9252488471ba8
	//���� ��� ����



	//�������Ͽ��� ����
//	CreateNewEvent(root, id, start, end, title, tag, isPublic, imPortanceLevel);
//	DeleteEvent(root, node);
//	//�����Ͽ��� ����
//	CreateNewEvent(root, id, start, end, title, tag, isPublic, imPortanceLevel);
//	DeleteEvent(root, node);
}