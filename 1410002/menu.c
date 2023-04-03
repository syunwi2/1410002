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
	printf("\n            MENU  \n\n");
	printf("         1. 일정 생성  \n");
	printf("         2. 개인 일정 조회  \n");
	printf("         3. 팀 일정 조회  \n");
	printf("         4. 종료  \n");


	printf("\n\n  ▶ 원하는 작업번호를 입력해주세요. : ");
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