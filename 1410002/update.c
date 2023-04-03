#include "update.h"

long long int TimeUpdate()
{
	int i;
	long long int tmpt;

	printf("choice");
	char tmp[100];
	tmp[0] = '\0';
	char year_ch[10], mon_ch[10], day_ch[10], hour_ch[10], min_ch[10];
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
	return tmpt;
}
 
void UpdateEvent(EVENT** root)
{
	int chk, findnum;
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
	scanf_s("%d", &findnum);
	//���� ��� ����

	EVENT* ptr = "";
	while (node != NULL &&  findnum!= node->nodeID) 
	{
		if ( node->start > findnum)
		{
			node = node->prev;
		}
		else if (node->start < findnum)
		{
			node = node->next;
		}
		else
		{
			ptr = node;
		}
	}

	strcpy(buffer.nodeID, ptr->nodeID);
	buffer.start = ptr->start;
	buffer.end = ptr->end;
	strcpy(buffer.title, ptr->title);
	buffer.tag = ptr->tag;
	buffer.isPublic = ptr->isPublic;
	buffer.importanceLevel = ptr->importanceLevel;
	
	//���� ���� ���� ����
	DeleteEvent(root, ptr);

	// ���� �ʱ�ȭ
	char tmp[100];
	tmp[0] = '\0';
	int chk_con;
	do
	{
	// �� ���� ���� ����

	printf("� ������ ���� �ϰڽ��ϱ�? \n");
	printf("1. ������ 2. ������ 3. ���� 4. �±� 5. ispublic 6. �߿䵵 \n");
	scanf_s("%d", &chk_con);
	} while (chk_con != 1 && chk_con != 2 && chk_con != 3 && chk_con != 4 &&
		chk_con != 5 && chk_con != 6);
	long long int tmpt_res;
	if (chk_con == 1)
	{
		tmpt_res =TimeUpdate();
		CreateNewEvent(root, buffer.nodeID, tmpt_res, buffer.end,
			buffer.title, buffer.tag, buffer.isPublic, buffer.importanceLevel);
	}
	else if (chk_con == 2)
	{
		tmpt_res = TimeUpdate();
		CreateNewEvent(root, buffer.nodeID, buffer.start, tmpt_res,
			buffer.title, buffer.tag, buffer.isPublic, buffer.importanceLevel);
	}
	else if (chk_con == 3)
	{
		do {
			printf("\n ������ : ");
			printf("                   \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
			gets(tmp);

		} while (strlen(tmp) >= 100);
		//strcpy(title, tmp);
		CreateNewEvent(root, buffer.nodeID, buffer.start, buffer.end,
			tmp, buffer.tag, buffer.isPublic, buffer.importanceLevel);
	}
	else if (chk_con == 4)
	{
		int tmp_i;
		tmp[0] = '\0';			// �ӽù��� �ʱ�ȭ
		tmp_i = -1;

		do {

			printf("\n # tag  ȸ�� : 0, ���� : 1, ��Ÿ : 2 ");
			printf("\n Tag : ");
			printf("                   \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
			scanf("%d%*c", &tmp_i);

		} while (tmp_i < 0 && tmp_i >= sizeof(TAG));

		CreateNewEvent(root, buffer.nodeID, buffer.start, buffer.end,
			buffer.title, tmp_i, buffer.isPublic, buffer.importanceLevel);
	}
	else if (chk_con == 5)
	{
		char ch;
		int isPublic;
		do {
			printf("\n ���� ����(Y / N) : ");
			printf("                   \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");

			ch = getchar();

		} while (ch != 'y' && ch != 'Y' && ch != 'n' && ch != 'N');

		if (ch == 'y' || ch == 'Y')
		{
			isPublic = 1;
		}
		else
		{
			isPublic = 0;
		}

		CreateNewEvent(root, buffer.nodeID, buffer.start, buffer.end,
			buffer.title, buffer.tag, isPublic, buffer.importanceLevel);
	}
	else if (chk_con == 6)
	{
		int tmp_i = 0; // ���� �ʱ�ȭ

		do {

			printf("\n �߿䵵 (0-5) : ");
			printf("                   \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");

			scanf_s("%d%*c", &tmp_i);

		} while (tmp_i > 5 || tmp_i < 0);

		CreateNewEvent(root, buffer.nodeID, buffer.start, buffer.end,
			buffer.title, buffer.tag, buffer.isPublic, tmp_i);
	}
	
	
	//�����Ͽ��� ����
	//DeleteEvent(root, ptr);
	//CreateNewEvent(root, id, start, end, title, tag, isPublic, imPortanceLevel);
}