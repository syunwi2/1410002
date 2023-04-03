#include "menu.h"
#include "schedule.h"


void Menu(EVENT** personalRoot, EVENT** teamRoot, PERSON* user_ptr)
{
	int ans;			// �Է°� ����
	
	PublicFileSave(user_ptr, teamRoot);		// ���� ����
	PrivateFileSave(user_ptr, personalRoot);		// ���� ����
	gotoxy(5, 18);
	do
	{
		textcolor(14);
		gotoxy(27, 13);
		printf("==================================");
		gotoxy(27, 14);
		printf("               MENU         ");
		gotoxy(27, 15);
		printf("==================================");

		textcolor(15);
		gotoxy(27, 17);
		printf("         1. ���� ����  ");
		gotoxy(27, 18);
		printf("         2. ���� ���� ��ȸ  ");
		gotoxy(27, 19);
		printf("         3. �� ���� ��ȸ  ");
		gotoxy(27, 20);
		printf("         4. ����      ");

		gotoxy(26, 23);
		textcolor(14);
		printf("�� ���ϴ� �۾���ȣ�� �Է����ּ���. : ");
		scanf("%d%*c", &ans);



		switch (ans)
		{
			// 1. ���� ����
			case 1:					
				CreateEventScreen(personalRoot, teamRoot, user_ptr);
				break;
			// 2. ���� ��ȸ
			case 2:
				PersonalReadEvent(personalRoot);
				break;
			// 3. �� ���� ��ȸ
			case 3:
				PublicReadEvent(teamRoot);
				break;
			// 4. ����
			case 4:
				exit(1);
		}

	} while (ans!=4);
}