#include "update.h"

long long int TimeUpdate()
{
	int i;
	long long int tmpt;

	//printf("choice");
	char tmp[100];
	tmp[0] = '\0';
	char year_ch[10] = { 0 } , mon_ch[10] = { 0 }, day_ch[10] = { 0 }, hour_ch[10] = { 0 }, min_ch[10] = { 0 };
	int year, mon, day, hour, min;

	while (1)
	{
		do {
			printf(" >>> ��¥�� �˷��ּ���. ex) 2309261500 \n");
			printf("     YYMMDDHHMM : \n");
			gets(tmp);

		} while (strlen(tmp) != 10);

		for (i = 0; i < 10; i++)
		{
			if (i < 2)
			{
				year_ch[i] = tmp[i];
			}
			else if (2 <= i && i < 4)
			{
				mon_ch[i - 2] = tmp[i];
			}
			else if (4 <= i && i < 6)
			{
				day_ch[i - 4] = tmp[i];
			}
			else if (6 <= i && i < 8)
			{
				hour_ch[i - 6] = tmp[i];
			}
			else
			{
				min_ch[i - 8] = tmp[i];
			}
		}
		year = atoi(year_ch) + 2000;
		mon = atoi(mon_ch);
		day = atoi(day_ch);
		hour = atoi(hour_ch);
		min = atoi(min_ch);

		if (mon >= 1 && mon <= 12 && day >= 1 && day <= 31
			&& hour >= 0 && hour <= 24 && min >= 0 && min <= 60)
			break;
	}

	tmpt = GetTimeT(year, mon, day, hour, min);
	return tmpt;
}
 
void UpdateEvent(EVENT** root)
{
	int chk, findnum, chk_con;
	EVENT* node, buffer;
	char tmp[100], findid[7] = { 0 };
	node = *root;
	printf("������ ���� �� �� �ֽ��ϴ�. \n");
	printf("� ������ �����Ͻðڽ��ϱ�? \n");
	//���� ��ü ���
	do
	{
		printf("���� �ٽ� Ȯ���ϱ� (�ٽ���ȸ: 1, �����ϱ�: 2)\n");
		scanf_s("%d%*c", &chk);
	} while (chk != 1 && chk != 2);

	if (chk == 1)
	{
		PersonalReadEvent(root);
	}

	//���� ��� ����
	printf("������ ��� ��ȣ ���� : \n");
	scanf_s("%d%*c", &findnum);
	sprintf(findid, "%.6d", findnum);

	EVENT* ptr;
	while (node != NULL) 
	{
		if ( strcmp(node->nodeID, findid) < 0 )
		{
			node = node->next;
		}
		else if ( strcmp(node->nodeID, findid) > 0 )
		{
			node = node->prev;
		}
		else
		{
			ptr = node;
			break;
		}
	}

	strcpy(buffer.nodeID, ptr->nodeID);
	strcpy(buffer.ownerID, ptr->ownerID);
	buffer.start = ptr->start;
	buffer.end = ptr->end;
	strcpy(buffer.title, ptr->title);
	buffer.tag = ptr->tag;
	buffer.isPublic = ptr->isPublic;
	buffer.importanceLevel = ptr->importanceLevel;
	
	//���� ���� ���� ����
	DeleteEvent(root, ptr);
	//ptr = NULL;
	// ���� �ʱ�ȭ
	tmp[0] = '\0';
	
	while (1) {
		do
		{
			// �� ���� ���� ����
			printf("� ������ ���� �ϰڽ��ϱ�? \n");
			printf("1. ������ 2. ������ 3. ���� 4. �±� 5. ispublic 6. �߿䵵 7. ������ ���� ���� 8. ���� �Ϸ�\n");
			scanf_s("%d%*c", &chk_con);
		} while (chk_con != 1 && chk_con != 2 && chk_con != 3 && chk_con != 4 &&
			chk_con != 5 && chk_con != 6 && chk_con != 7 && chk_con != 8);
		// ������ ����
		if (chk_con == 1)
		{

			buffer.start = TimeUpdate();
		}
		// ������ ����
		else if (chk_con == 2)
		{

			buffer.end = TimeUpdate();
		}
		// ���� ����
		else if (chk_con == 3)
		{
			do
			{
				printf("���� ���� : \n");
				printf("                   \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
				gets(tmp);

			} while (strlen(tmp) >= sizeof(tmp));
			strcpy(buffer.title, tmp);
		}
		// �±� ����
		else if (chk_con == 4)
		{
			do
			{
				printf("\n # tag  ȸ�� : 0, ���� : 1, ��Ÿ : 2 ");
				printf("\n Tag : ");
				printf("                   \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
				scanf("%d%*c", &buffer.tag);

			} while (buffer.tag < 0 && buffer.tag >= sizeof(TAG));

		}
		// ���� ���� ����
		else if (chk_con == 5)
		{
			char ch;
			do {
				printf("\n ���� ����(Y / N) : ");
				printf("                   \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");

				ch = getchar();

			} while (ch != 'y' && ch != 'Y' && ch != 'n' && ch != 'N');

			if (ch == 'y' || ch == 'Y')
			{
				buffer.isPublic = 1;
			}
			else
			{
				buffer.isPublic = 0;
			}
		}
		// �߿䵵 ����
		else if (chk_con == 6)
		{
			do
			{
				printf("\n �߿䵵 (0-5) : ");
				printf("                   \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");

				scanf_s("%d%*c", &buffer.importanceLevel);

			} while (buffer.importanceLevel > 5 || buffer.importanceLevel < 0);
		}
		// ������ ���� ������Ʈ
		else if (chk_con == 7)
		{
			CreateNewEvent(root, buffer.ownerID, buffer.start, buffer.end, buffer.title, buffer.tag, buffer.isPublic, buffer.importanceLevel);
			printf("������ �Ϸ�Ǿ����ϴ�.\n");
		}
		else if (chk_con == 8)
		{
			break;
		}
	}
	
	//�����Ͽ��� ����
	//DeleteEvent(root, ptr);
	//CreateNewEvent(root, id, start, end, title, tag, isPublic, imPortanceLevel);
}