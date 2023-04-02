#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>		// gotoxy �������

#include "user.h"
#include "screen.h"
#include "schedule.h"

#pragma warning(disable :4996)

void SignUp()
{
	PERSON user;
	char tmp[100];		// �Է°����� �ӽ� �迭, ����
	int i;					// �ӽ� ����
	char dept_str[sizeof(user.dept)][20]
		= { "������", "ä����", "��������", "�濵������" };  // �� name ����ϱ� ���� �迭


	system("cls");
	gotoxy(3, 0);
	printf("                                     \n");
	printf(" ============= ȸ������ ============= \n");
	printf("                                     \n");




	// ============ id �Է� ================

	tmp[0] = '\0';			// �ӽù��� �ʱ�ȭ
	while (1)
	{
		do {
			gotoxy(0, 4);
			printf(" >>> ID�� 1 - 20���� ���� �Է����ּ���. \n");
			printf("     ID : ");
			gets(tmp);
		} while (strlen(tmp) >= sizeof(user.id) || (strlen(tmp) < 1));
		

		// user.txt > ����ȸ�� ������ �о� id �ߺ�üũ 
		FILE* op;
		PERSON ex_user;		// ����ȸ�� ����ü����
		int flag = 1;

		op = fopen("user.txt", "rt");
		if (op == NULL) 
		{
			perror("Error : ");
			exit(1);
		}


		while (1)
		{
			i = fscanf(op, "%s %s %s %d %lld \n",
			ex_user.id, ex_user.name, ex_user.pw, &ex_user.dept, &ex_user.birthday);

			// ���� �����Ͱ� ������ �ߴ�
			if (i != 5)
				break;

			// id�� �ߺ��̸� üũ
			if (strcmp(tmp, ex_user.id) == 0)
			{
				printf("     ��  �ߺ��� id�� �ֽ��ϴ�. : %s \n", ex_user.id);
				flag = 0;
			}

		} // ���� while(1) end.

		if (flag == 1)
			break;

	} // �ٱ� while(1) end.
	
	strcpy(user.id, tmp);





	// ============ �̸� �Է� ================

	tmp[0] = '\0';			// �ӽù��� �ʱ�ȭ
	do {
		gotoxy(0, 7);
		printf(" >>> �̸��� 1-20���� ���� �Է����ּ���. \n");
		printf("     Name : ");
		gets(tmp);

	} while (strlen(tmp) >= sizeof(user.name) || (strlen(tmp) < 1));

	strcpy(user.name, tmp);





	// ============ ��й�ȣ �Է� ================

	tmp[0] = '\0';			// �ӽù��� �ʱ�ȭ
	do {
		gotoxy(0, 10);
		printf(" >>> ��й�ȣ�� 1-20���� ���� �Է����ּ���. \n");
		printf("     PW : ");
		gets(tmp);

		/* ��й�ȣ �Է½� ��ȣȭ�ϱ� ���� �ڵ� (����)
			while (1) {
				// ����ڿ��� ���ڸ� �Է¹޴´�.
				ch = _getch();
				// �ش� ���ڰ� ����Ű�� �۾��� �ߴ��Ѵ�.
				if (ch == '\r')
				{
					break;
				}
				else
				{
					_putch('*');
				}

				// ����Ű�� �ƴϸ� '*'���ڸ� ����Ѵ�.
			}
		*/

	} while (strlen(tmp) >= sizeof(user.pw) || (strlen(tmp) < 1));

	strcpy(user.pw, tmp);
	




	// ============ �μ� �Է� ================

	do {

		gotoxy(0, 13);
		printf(" >>> �μ��� �������ּ���. (0-3) \n");
		printf("     ���� : 0, ä�� : 1, ������ : 2, �濵���� : 3 \n");
		printf("     Team : ");
		scanf("%d%*c", &i);

	} while (i > (sizeof(user.dept)-1) || i < 0);

	user.dept = i;





	// ============ ���� �Է� ================

	tmp[0] = '\0';			// �ӽù��� �ʱ�ȭ
	char mon_ch[10], day_ch[10];
	int mon, day;

	while (1)
	{
		do {
			gotoxy(0, 17);
			printf(" >>> ������ �˷��ּ���. ex) 0926 \n");
			printf("     YYDD : ");
			gets(tmp);

		} while (strlen(tmp) != 4);

		
		for (i = 0; i < 4; i++)
		{
			if (i < 2)
			{
				mon_ch[i] = tmp[i];
			}
			else
			{
				day_ch[i-2] = tmp[i];
			}
		}
		mon = atoi(mon_ch);
		day = atoi(day_ch);

		if (mon >= 1 && mon <= 12 && day >=1 && day <=31)
			break;


	}	// while(1) end.

	user.birthday = GetTimeT(2023, mon, day, 0, 0);





	// ============ user ���Ͽ� �Է� ================

	FILE* fp;
	fp = fopen("user.txt", "at");
	if (fp == NULL)
	{
		perror("Error : ");
		exit(1);
	}

	fprintf(fp, "%s %s %s %d %lld \n",
		user.id, user.name, user.pw, user.dept, user.birthday);

	printf("���� ���� �Ϸ�. \n");


	// ����ü user �����޸� �Ҵ�
	PERSON* user_ptr = malloc(sizeof(PERSON));

	// ����ü ��� �� �Ҵ�
	strcpy(user_ptr->id, user.id);
	strcpy(user_ptr->name, user.name);
	strcpy(user_ptr->pw, user.pw);
	user_ptr->dept = user.dept;
	user_ptr->birthday = user.birthday;


	// ============ ȸ������ �Ϸ�ȭ�� ================

	system("cls");
	gotoxy(5, 1);
	printf("                                    \n");
	printf("ȯ���մϴ�. %s�� :) \n", user.name);
	printf("                                    \n");
	printf("\n id: %s \n name: %s \n pw: %s \n �μ�: %s \n ����: %s \n",
		user.id, user.name, user.pw, dept_str[user.dept], tmp);



} // SignUp() end.
