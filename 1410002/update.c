#include "update.h"

void UpdateEvent(EVENT** root, EVENT* node)
{
	int chk;
	EVENT* ptr = node;
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



	//�������Ͽ��� ����
	

	//�����Ͽ��� ����

}