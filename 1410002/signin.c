#include "user.h"


// ============ �α��� �Լ� ================

void SignIn()
{
	PERSON user;
	char tmp_id[100], tmp_pw[100];		// id, pw �Է°� �ӽù迭
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
	i = 0;								// ���� �ʱ�ȭ
	int buffer = 0;						
	
	
	while (1)
	{
		do {
			gotoxy(0, 4);
			printf("     ID : ");		// ID �Է�
			printf("                    \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
			gets(tmp_id);

			printf("\n     PW : ");		// PW �Է�
			printf("                    \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");

			for (i = 0;buffer != 13; i++) 
			{
				tmp_pw[i] = getch();

				if (tmp_pw[i] == '\n')
				{
					i--;
					continue;
				}

				putch('*');

				buffer = (int)tmp_pw[i];	// buffer : �Է°��� ����(13)���� Ȯ��
			}

			tmp_pw[i - 1] = '\0';

		} while (strlen(tmp_id) >= sizeof(user.id) || strlen(tmp_id) < 1		// ������ �迭������ ũ�� �ٽ� �Է¹���
				|| strlen(tmp_pw) >= sizeof(user.pw) || strlen(tmp_pw) < 1);


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

		// ����ȸ�� ������ ����ü������ �Է�
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

		if (flag == 0)						// id, pw ��ġ�Ͽ� flag == 0�̸� �ݺ��� �ߴ�
		{
			break;
		}
		else
		{
			printf("     ��  ID / PW�� �ٽ� �Է����ּ���. \n");	
		}

	} // �ٱ� while(1) end.

	LogOn(user, dept_str);					// �α׿� �Լ� ȣ�� (�α��οϷ� ȭ��)

}
