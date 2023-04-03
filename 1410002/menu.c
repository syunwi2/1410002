#include "menu.h"
#include "schedule.h"


void Menu(PERSON* user_ptr)
{
	int ans;			// �Է°� ����
	EVENT* personalRoot = NULL;
	EVENT* teamRoot = NULL;
	
	PublicFileSave(user_ptr, &teamRoot);		// ���� ����
	PrivateFileSave(user_ptr, &personalRoot);		// ���� ����


	gotoxy(5, 18);
	printf("\n            MENU  \n\n");
	printf("         1. ���� ����  \n");
	printf("         2. ���� ��ȸ  \n");
	printf("         3. ����      \n");

	printf("\n\n  �� ���ϴ� �۾���ȣ�� �Է����ּ���. : ");
	scanf("%d%*c", &ans);


	switch (ans)
	{
		// 1. ���� ����
		case 1:					
			CreateEventScreen(user_ptr);
			break;
		// 2. ���� ��ȸ
		case 2:
			break;
		// 3. ����
		case 3:
			exit(1);




		
	}

}