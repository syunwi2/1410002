#include "menu.h"
#include "schedule.h"


void Menu(EVENT** personalRoot, EVENT** teamRoot, PERSON* user_ptr)
{
	int ans;			// 입력값 변수
	
	PublicFileSave(user_ptr, teamRoot);		// 파일 저장
	PrivateFileSave(user_ptr, personalRoot);		// 파일 저장
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
		printf("         1. 일정 생성  ");
		gotoxy(27, 18);
		printf("         2. 개인 일정 조회  ");
		gotoxy(27, 19);
		printf("         3. 팀 일정 조회  ");
		gotoxy(27, 20);
		printf("         4. 종료      ");

		gotoxy(26, 23);
		textcolor(14);
		printf("▶ 원하는 작업번호를 입력해주세요. : ");
		scanf("%d%*c", &ans);



		switch (ans)
		{
			// 1. 일정 생성
			case 1:					
				CreateEventScreen(personalRoot, teamRoot, user_ptr);
				break;
			// 2. 일정 조회
			case 2:
				PersonalReadEvent(personalRoot);
				break;
			// 3. 팀 일정 조회
			case 3:
				PublicReadEvent(teamRoot);
				break;
			// 4. 종료
			case 4:
				exit(1);
		}

	} while (ans!=4);
}