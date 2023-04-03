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
	printf("         4. 팀 일정 수정  \n");
	printf("         5. 팀 일정 삭제  \n");
	printf("         6. 종료      \n");

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
			// 4. 일정 수정
			case 4:
				UpdateEvent(personalRoot);
				break;
			// 5. 일정 삭제
			case 5:
				//DeleteEvent(personalRoot);
				break;
			// 6. 종료
			case 6:
				exit(1);
		}

	} while (ans!=6);
}