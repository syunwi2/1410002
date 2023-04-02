#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "user.h"
#include "screen.h"



void SignIn()
{
	PERSON user;
	char tmp_id[100],tmp_pw[100];		// id, pw 입력값 임시배열
	int i;								// 임시 변수
	char dept_str[sizeof(user.dept)][20] 
		= { "원장팀", "채널팀", "인프라팀", "경영지원팀" };  // 팀 name 출력하기 위한 배열


	system("cls");
	gotoxy(3, 0);
	printf("                                    \n");
	printf(" ============= 로그인 ============= \n");
	printf("                                    \n");




	// ============ id / pw 입력 ================

	tmp_id[0] = '\0';					// 임시버퍼 초기화
	tmp_pw[0] = '\0';					// 임시버퍼 초기화

	while (1)
	{
		do {
			gotoxy(0, 4);
			printf("     ID : ");
			gets(tmp_id);

			printf("\n     PW : ");
			gets(tmp_pw);

		} while (strlen(tmp_id) >= sizeof(user.id) || strlen(tmp_id) < 1
				|| strlen(tmp_pw) >= sizeof(user.id) || strlen(tmp_pw) < 1);


		// user.txt > 기존회원 데이터 읽어 id 중복체크 
		FILE* op;
		PERSON ex_user;		// 기존회원 구조체변수
		int flag = 1;

		op = fopen("user.txt", "rt");
		if (op == NULL)
		{
			perror("Error : ");
			exit(1);
		}


		while (1)
		{
			i = fscanf(op, "%s %s %s %d %lld \n",
				ex_user.id, ex_user.name, ex_user.pw, &ex_user.dept, &ex_user.birthday);

			// 비교할 데이터가 없으면 중단
			if (i != 5)
				break;

			// id, pw가 모두 맞으면 체크
			if (strcmp(tmp_id, ex_user.id) == 0 && strcmp(tmp_pw, ex_user.pw) == 0)
			{
				flag = 0;
				user = ex_user;				// 구조체 복사 (정보 복사)
				break;
			}

		} // 안쪽 while(1) end.

		if (flag == 0)
		{
			break;
		}
		else
		{
			printf("     ※  ID / PW를 다시 입력해주세요. \n");	
		}

	} // 바깥 while(1) end.

	LogOn(user, dept_str);

}


void LogOn(PERSON user, char (*dept_str)[20])
{

	// 구조체 user 동적메모리 할당
	PERSON* user_ptr = malloc(sizeof(PERSON));

	// 구조체 멤버 값 할당
	strcpy(user_ptr->id, user.id);
	strcpy(user_ptr->name, user.name);
	strcpy(user_ptr->pw, user.pw);
	user_ptr->dept = user.dept;
	user_ptr->birthday = user.birthday;




	// ============ 로그인 완료화면 ================

	system("cls");
	gotoxy(5, 1);
	// Heap에서 데이터 사용
	printf("환영합니다. %s님 :) \n", user_ptr->name);
	printf("\n     id : %3s, 부서 : %3s  \n",
		user_ptr->id, dept_str[user_ptr->dept]);

	Calender();



}