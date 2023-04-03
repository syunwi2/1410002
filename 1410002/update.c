#include "update.h"

void UpdateEvent(EVENT** root, PERSON* user)
{
	int chk;
	int i;
	long long int tmpt;
	EVENT* node, buffer;
	node = *root;
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
	char tmp[100];
	tmp[0] = '\0';			
	char year_ch[10],mon_ch[10], day_ch[10], hour_ch[10], min_ch[10];
	int year, mon, day, hour, min;

	while (1)
	{
		do {
			printf(" >>> ��¥�� �˷��ּ���. ex) 2309261500 \n");
			printf("     YYMMDDHHMM : ");
			gets(tmp);

		} while (strlen(tmp) != 10);

		/*
			���ڿ��� ���� 6�ڸ� ��/�� 2�ڸ��� ����,
			int������ ����� ��ȯ �� ��ȿ�� ��¥���� ��Ȯ��
			�ùٸ� �Է°��̸� GetTimeT �Լ��� �����Ͽ� ���Ͽ� ����
		*/

		for (i = 0; i < 10; i++)
		{
			if (i < 2)
			{
				year_ch[i] = tmp[i];
			}
			else if (2 <= i < 4)
			{
				mon_ch[i - 2] = tmp[i];
			}
			else if (4 <= i < 6)
			{
				day_ch[i - 4] = tmp[i];
			}
			else if (6 <= i < 8)
			{
				hour_ch[i - 6] = tmp[i];
			}
			else 
			{
				min_ch[i - 8] = tmp[i];
			}
		}
		year = atoi(year_ch);
		mon = atoi(mon_ch);
		day = atoi(day_ch);
		hour = atoi(hour_ch);
		min = atoi(min_ch);

		if (mon >= 1 && mon <= 12 && day >= 1 && day <= 31
			&& hour >= 0 && hour <= 24 && min >= 0 && min <= 60)
			break;


	}	// while(1) end.

	tmpt = GetTimeT(year, mon, day, hour, min);
	EVENT* ptr = "";
	while (node != NULL && tmpt != node->start) 
	{
		if ( node->start > tmpt) 
		{
			node = node->prev;
		}
		else if (node->start < tmpt)
		{
			node = node->next;
		}
		else
		{
			ptr = node;
		}
	}

	strcpy(buffer.ownerID, ptr->ownerID);
	buffer.start = ptr->start;
	buffer.end = ptr->end;
	strcpy(buffer.title, ptr->title);
	buffer.tag = ptr->tag;
	buffer.isPublic = ptr->isPublic;
	buffer.importanceLevel = ptr->importanceLevel;
	
	//���� ���� ���� ����
	DeleteEvent(root, ptr);

	// ���� �ʱ�ȭ
	tmp[0] = '\0';

	prtinf("");

	// �� ���� ���� ����
	CreateNewEvent(root, user->id, buffer.start, buffer.end, buffer.title, buffer.tag, buffer.isPublic, buffer.importanceLevel);
	
	//�����Ͽ��� ����
	//DeleteEvent(root, ptr);
	//CreateNewEvent(root, id, start, end, title, tag, isPublic, imPortanceLevel);
}