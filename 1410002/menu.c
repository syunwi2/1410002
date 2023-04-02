#include "menu.h"
#include "screen.h"
#include "create.h"


void Menu()
{
	int ans;			// 입력값 변수

	gotoxy(3, 15);
	printf("\n     MENU  \n\n");
	printf("  1. 일정 생성  \n");
	printf("  2. 일정 조회  \n");
	printf("  3. 종료  \n");

	printf("\n\n  ▶ 원하는 작업번호를 입력해주세요. : ");
	scanf("%d", &ans);


	switch (ans)
	{
	case 1:
		CreateEventScreen();
		break;



		
	}

}