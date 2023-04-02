#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "user.h"
#include "screen.h"



void SignIn()
{
	PERSON user;
	char tmp_id[100],tmp_pw[100];		// id, pw �Է°� �ӽù迭
	int i;								// �ӽ� ����
	char dept_str[sizeof(user.dept)][20] 
		= { "������", "ä����", "��������", "�濵������" };  // �� name ����ϱ� ���� �迭


	system("cls");
	gotoxy(3, 0);
	printf("                                    \n");
	printf(" ============= �α��� ============= \n");
	printf("                                    \n");




	// ============ id / pw �Է� ================

	tmp_id[0] = '\0';					// �ӽù��� �ʱ�ȭ
	tmp_pw[0] = '\0';					// �ӽù��� �ʱ�ȭ

	while (1)
	{
		do {
			gotoxy(0, 4);
			printf("     ID : ");
			gets(tmp_id);

			printf("\n     PW : ");
			gets(tmp_pw);

		} while (strlen(tmp_id) >= sizeof(user.id) || strlen(tmp_id) < 1
				|| strlen(tmp_pw) >= sizeof(user.id) || strlen(tmp_pw) < 1);


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

			// id, pw�� ��� ������ üũ
			if (strcmp(tmp_id, ex_user.id) == 0 && strcmp(tmp_pw, ex_user.pw) == 0)
			{
				flag = 0;
				user = ex_user;				// ����ü ���� (���� ����)
				break;
			}

		} // ���� while(1) end.

		if (flag == 0)
		{
			break;
		}
		else
		{
			printf("     ��  ID / PW�� �ٽ� �Է����ּ���. \n");	
		}

	} // �ٱ� while(1) end.

	LogOn(user, dept_str);

}


void LogOn(PERSON user, char (*dept_str)[20])
{

	// ����ü user �����޸� �Ҵ�
	PERSON* user_ptr = malloc(sizeof(PERSON));

	// ����ü ��� �� �Ҵ�
	strcpy(user_ptr->id, user.id);
	strcpy(user_ptr->name, user.name);
	strcpy(user_ptr->pw, user.pw);
	user_ptr->dept = user.dept;
	user_ptr->birthday = user.birthday;




	// ============ �α��� �Ϸ�ȭ�� ================

	system("cls");
	gotoxy(5, 1);
	// Heap���� ������ ���
	printf("ȯ���մϴ�. %s�� :) \n", user_ptr->name);
	printf("\n     id : %3s, �μ� : %3s  \n",
		user_ptr->id, dept_str[user_ptr->dept]);

	Calender();



}