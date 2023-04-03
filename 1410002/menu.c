#include "menu.h"


void Menu(PERSON* user_ptr)
{
	int ans;			// 입력값 변수

	gotoxy(5, 15);
	printf("\n            MENU  \n\n");
	printf("         1. 일정 생성  \n");
	printf("         2. 일정 조회  \n");
	printf("         3. 종료      \n");

	printf("\n\n  ▶ 원하는 작업번호를 입력해주세요. : ");
	scanf("%d%*c", &ans);


	switch (ans)
	{
		// 1. 일정 생성
		case 1:					
			CreateEventScreen(user_ptr);
			break;
		// 2. 일정 조회
		case 2:
			break;
		// 3. 종료
		case 3:
			exit(1);




		
	}

}