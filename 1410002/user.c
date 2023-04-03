#include "user.h"
#include "menu.h"


#define LEFT 75			// 방향키별 아스키코드값
#define RIGHT 77


// ============ 로그인 완료  ================
PERSON* UserPtr(PERSON user)
{
	// 구조체 user 동적메모리 할당
	PERSON* user_ptr = malloc(sizeof(PERSON));

	// 구조체 멤버 값 할당
	strcpy(user_ptr->id, user.id);
	strcpy(user_ptr->name, user.name);
	strcpy(user_ptr->pw, user.pw);
	user_ptr->dept = user.dept;
	user_ptr->birthday = user.birthday;
	
	return user_ptr;
}


void LogOn(PERSON user, char(*dept_str)[20])
{
	PERSON* user_ptr = UserPtr(user);

	// ============ 로그온 화면 ================


	system("cls");
	gotoxy(3, 1);
	// Heap에서 데이터 사용
	printf("환영합니다. %s님 :) \n", user_ptr->name);
	printf("\n     id : %3s, 부서 : %3s  \n",
		user_ptr->id, dept_str[user_ptr->dept]);


	// 달력 출력
	Calender();


	//PrivateFileLoad();


	// menu 출력
	Menu(user_ptr);


}