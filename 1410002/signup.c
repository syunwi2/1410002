#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>		// gotoxy 헤더파일

#include "user.h"
#include "screen.h"
#include "schedule.h"

#pragma warning(disable :4996)

//gotoxy 콘솔 커서 좌표 변경 함수
void gotoxy(int x, int y)
{
	COORD pos = { x,y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
} // gotoxy() end.





void SignUp()
{
	system("cls");
	gotoxy(3, 0);
	printf(" < 회원가입 > \n");
	PERSON user;
	char tmp[100], ch;		// 입력값제어 임시 배열, 변수
	int i;					// 임시 변수





	// ============ id 입력 ================

	tmp[0] = '\0';			// 임시버퍼 초기화
	while (1)
	{
		do {
			gotoxy(0, 2);
			printf(" >>> ID를 1 - 20글자 내로 입력해주세요. \n");
			printf("     ID : ");
			gets(tmp);
		} while (strlen(tmp) >= sizeof(user.id) || (strlen(tmp) < 1));
		

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
			// id가 중복이면 체크
			if (strcmp(tmp, ex_user.id) == 0)
			{
				printf("     ※  중복된 id가 있습니다. : %s \n", ex_user.id);
				flag = 0;
			}
		} // 안쪽 while(1) end.

		if (flag == 1)
			break;

	} // 바깥 while(1) end.
	
	strcpy(user.id, tmp);





	// ============ 이름 입력 ================

	tmp[0] = '\0';			// 임시버퍼 초기화
	do {
		gotoxy(0, 4);
		printf(" >>> 이름을 1-20글자 내로 입력해주세요. \n");
		printf("     Name : ");
		gets(tmp);

	} while (strlen(tmp) >= sizeof(user.name) || (strlen(tmp) < 1));

	strcpy(user.name, tmp);





	// ============ 비밀번호 입력 ================

	tmp[0] = '\0';			// 임시버퍼 초기화
	do {
		gotoxy(0, 6);
		printf(">>> 비밀번호를 1-20글자 내로 입력해주세요. \n");
		printf("     PW : ");
		gets(tmp);

		/* 비밀번호 입력시 암호화하기 위한 코드 (예정)
			while (1) {
				// 사용자에게 문자를 입력받는다.
				ch = _getch();
				// 해당 문자가 엔터키면 작업을 중단한다.
				if (ch == '\r')
				{
					break;
				}
				else
				{
					_putch('*');
				}

				// 엔터키가 아니면 '*'문자를 출력한다.
			}
		*/

	} while (strlen(tmp) >= sizeof(user.pw) || (strlen(tmp) < 1));

	strcpy(user.pw, tmp);
	




	// ============ 부서 입력 ================

	do {
		gotoxy(0, 8);
		printf(" >>> 부서를 선택해주세요. (0-3) \n");
		printf("     원장 : 0, 채널 : 1, 인프라 : 2, 경영지원 : 3 \n");
		printf("     Team : ");
		scanf("%d%*c", &i);

	} while (i > (sizeof(user.dept)-1) || i < 0);

	user.dept = i;
	char dept_str[sizeof(user.dept)][20] = { "원장팀", "채널팀", "인프라팀", "경영지원팀"};





	// ============ 생일 입력 ================

	tmp[0] = '\0';			// 임시버퍼 초기화
	char mon_ch[10], day_ch[10];
	int mon, day;

	while (1)
	{
		do {
			gotoxy(0, 10);
			printf(" >>> 생일을 알려주세요. ex) 0926 \n");
			printf("     YYDD : ");
			gets(tmp);

		} while (strlen(tmp) != 4);

		
		for (i = 0; i < 4; i++)
		{
			if (i < 2)
			{
				mon_ch[i] = tmp[i];
			}
			else
			{
				day_ch[i-2] = tmp[i];
			}
		}
		mon = atoi(mon_ch);
		day = atoi(day_ch);

		if (mon >= 1 && mon <= 12 && day >=1 && day <=31)
			break;


	}	// while(1) end.

	user.birthday = getTimeT(2023, mon, day, 0, 0);





	// ============ user 파일에 입력 ================

	FILE* fp;
	fp = fopen("user.txt", "at");
	if (fp == NULL)
	{
		perror("Error : ");
		exit(1);
	}

	fprintf(fp, "%s %s %s %d %lld \n",
		user.id, user.name, user.pw, user.dept, user.birthday);

	printf("파일 저장 완료. \n");





	// ============ 회원가입 완료화면 ================

	system("cls");
	gotoxy(5, 1);
	printf("환영합니다. %s님 :) \n", user.name);
	printf("id: %s \t name: %s \t pw: %s \t 부서: %s \t 생일: %s \n",
		user.id, user.name, user.pw, dept_str[user.dept], tmp);



} // SignUp() end.
