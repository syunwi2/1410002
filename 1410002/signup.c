#include "signup.h"
#pragma warning(disable :4996)


// ============ ȸ������ �Լ� ================

void SignUp()
{
	PERSON user;
	char tmp[100];						// �Է°����� �ӽ� �迭, ����

	int i = 0;				// �ӽ� ����
	char dept_str[sizeof(user.dept)][20]
		= { "������", "ä����", "��������", "�濵������" };  // �� name ����ϱ� ���� �迭


	system("cls");
	textcolor(14);
	gotoxy(5, 3);
	printf("                        �������� Sign Up ��������                        \n");
	printf("                                                                            \n");
	textcolor(15);

	tmp[0] = '\0';			// �ӽù��� �ʱ�ȭ
	printf("\n");
	printf("                      >>> ID�� 1 - 20���� ���� �Է����ּ���.     \n");
	printf("                    ������������������������������������������������������������������������������������ \n");
	printf("                    ��    id    ��                             �� \n");
	printf("                    ������������������������������������������������������������������������������������ \n");
	printf("\n");




	while (1)
	{
		do {
			gotoxy(34, 8);
			printf("                    \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
			// ID �Է�
			gets(tmp);

		} while (strlen(tmp) >= sizeof(user.id) || strlen(tmp) < 1); 	// ������ �迭������ ũ�� �ٽ� �Է¹���



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
				gotoxy(25, 10);
				printf("��  �ߺ��� id�� �ֽ��ϴ�. : %s \n", ex_user.id);
				flag = 0;
			}

		} // ���� while(1) end.

		if (flag == 1)
			break;

	} // �ٱ� while(1) end.

	strcpy(user.id, tmp);





	// ============ �̸� �Է� ================
	printf("\n");
	printf("                      >>> �̸��� 1-20���� ���� �Է����ּ���.     \n");
	printf("                    ������������������������������������������������������������������������������������ \n");
	printf("                    ��   name   ��                             �� \n");
	printf("                    ������������������������������������������������������������������������������������ \n");
	printf("\n");

	tmp[0] = '\0';			// �ӽù��� �ʱ�ȭ
	do {
		gotoxy(34, 12);

		printf("                   \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
		gets(tmp);

	} while (strlen(tmp) >= sizeof(user.name) || (strlen(tmp) < 1));

	strcpy(user.name, tmp);






	// ============ ��й�ȣ �Է� ================
	printf("\n");
	printf("                      >>> ��й�ȣ�� 1-20���� ���� �Է����ּ���.  \n");
	printf("                    ������������������������������������������������������������������������������������ \n");
	printf("                    �� password ��                             �� \n");
	printf("                    ������������������������������������������������������������������������������������ \n");
	printf("\n");

	tmp[0] = '\0';			// �ӽù��� �ʱ�ȭ
	i = 0;					// ���� �ʱ�ȭ


	do {
		gotoxy(34, 16);
		printf("                    \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
		gets(tmp);


	} while (strlen(tmp) >= sizeof(user.pw) || (strlen(tmp) < 1));

	strcpy(user.pw, tmp);





	// ============ �μ� �Է� ================

	printf("\n");
	printf("                      >>> �μ��� �������ּ���. (0-3)             \n");
	printf("		       ����: 0, ä��: 1, ������: 2, �濵����: 3 \n");
	printf("                    ������������������������������������������������������������������������������������ \n");
	printf("                    ��   dept   ��                             �� \n");
	printf("                    ������������������������������������������������������������������������������������ \n");
	printf("\n");

	do {

		gotoxy(34, 21);

		printf("                   \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
		scanf("%d%*c", &i);

	} while (i > (sizeof(user.dept) - 1) || i < 0);

	user.dept = i;





	// ============ ���� �Է� ================

	printf("\n");
	printf("                      >>> ������ �˷��ּ���. (YYDD) ex) 0926     \n");
	printf("                    ������������������������������������������������������������������������������������ \n");
	printf("                    �� birthday ��                             �� \n");
	printf("                    ������������������������������������������������������������������������������������ \n");
	printf("\n");


	tmp[0] = '\0';			// �ӽù��� �ʱ�ȭ
	char mon_ch[10], day_ch[10];
	int mon, day;

	while (1)
	{
		do {
			gotoxy(34, 25);
			printf("                   \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
			gets(tmp);

		} while (strlen(tmp) != 4);						// ���� �Է� 4�ڸ� ������ ���Է� ��û



		/*
			���ڿ��� ���� 4�ڸ� ��/�� 2�ڸ��� ����,
			int������ ����� ��ȯ �� ��ȿ�� ��¥���� ��Ȯ��
			�ùٸ� �Է°��̸� GetTimeT �Լ��� �����Ͽ� ���Ͽ� ����
		*/

		for (i = 0; i < 4; i++)
		{
			if (i < 2)
			{
				mon_ch[i] = tmp[i];
			}
			else
			{
				day_ch[i - 2] = tmp[i];
			}
		}
		mon = atoi(mon_ch);
		day = atoi(day_ch);

		if (mon >= 1 && mon <= 12 && day >= 1 && day <= 31)
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
	
	EVENT* personalRoot = NULL;
	EVENT* teamRoot = NULL;

	personalRoot = PrivateFileLoad(&user);
	teamRoot = PublicFileLoad(&user);

	// ============ �α��� �Ϸ�ȭ�� ================

	LogOn(&personalRoot, &teamRoot, user, dept_str);


} // SignUp() end.
