#include "menu.h"
#include "screen.h"
#include "create.h"


void Menu()
{
	int ans;			// �Է°� ����

	gotoxy(5, 15);
	printf("\n            MENU  \n\n");
	printf("         1. ���� ����  \n");
	printf("         2. ���� ��ȸ  \n");
	printf("         3. ����      \n");

	printf("\n\n  �� ���ϴ� �۾���ȣ�� �Է����ּ���. : ");
	scanf("%d", &ans);


	switch (ans)
	{
		// 1. ���� ����
		case 1:					
			CreateEventScreen();
			break;
		// 2. ���� ��ȸ
		case 2:
			break;
		// 3. ����
		case 3:
			exit(1);




		
	}

}