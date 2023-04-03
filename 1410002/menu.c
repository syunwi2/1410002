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
	printf("\n            MENU  \n\n");
	printf("         1. ���� ����  \n");
	printf("         2. ���� ���� ��ȸ  \n");
	printf("         3. �� ���� ��ȸ  \n");
	printf("         4. �� ���� ����  \n");
	printf("         5. �� ���� ����  \n");
	printf("         6. ����      \n");

	printf("\n\n  �� ���ϴ� �۾���ȣ�� �Է����ּ���. : ");
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
			// 4. ���� ����
			case 4:
				UpdateEvent(personalRoot);
				break;
			// 5. ���� ����
			case 5:
				//DeleteEvent(personalRoot);
				break;
			// 6. ����
			case 6:
				exit(1);
		}

	} while (ans!=6);
}