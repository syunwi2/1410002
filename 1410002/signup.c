#include "signup.h"
#pragma warning(disable :4996)


// ============ 회원가입 함수 ================

void SignUp()
{
	PERSON user;
	char tmp[100];						// 입력값제어 임시 배열, 변수

	int i = 0;				// 임시 변수
	char dept_str[sizeof(user.dept)][20]
		= { "원장팀", "채널팀", "인프라팀", "경영지원팀" };  // 팀 name 출력하기 위한 배열


	system("cls");
	textcolor(14);
	gotoxy(5, 3);
	printf("                        ＊＊＊＊ Sign Up ＊＊＊＊                        \n");
	printf("                                                                            \n");
	textcolor(15);

	tmp[0] = '\0';			// 임시버퍼 초기화
	printf("\n");
	printf("                      >>> ID를 1 - 20글자 내로 입력해주세요.     \n");
	printf("                    ┌────────────────────────────────────────┐ \n");
	printf("                    │    id    │                             │ \n");
	printf("                    └────────────────────────────────────────┘ \n");
	printf("\n");




	while (1)
	{
		do {
			gotoxy(34, 8);
			printf("                    \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
			// ID 입력
			gets(tmp);

		} while (strlen(tmp) >= sizeof(user.id) || strlen(tmp) < 1); 	// 설정한 배열값보다 크면 다시 입력받음



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
				gotoxy(25, 10);
				printf("※  중복된 id가 있습니다. : %s \n", ex_user.id);
				flag = 0;
			}

		} // 안쪽 while(1) end.

		if (flag == 1)
			break;

	} // 바깥 while(1) end.

	strcpy(user.id, tmp);





	// ============ 이름 입력 ================
	printf("\n");
	printf("                      >>> 이름을 1-20글자 내로 입력해주세요.     \n");
	printf("                    ┌────────────────────────────────────────┐ \n");
	printf("                    │   name   │                             │ \n");
	printf("                    └────────────────────────────────────────┘ \n");
	printf("\n");

	tmp[0] = '\0';			// 임시버퍼 초기화
	do {
		gotoxy(34, 12);

		printf("                   \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
		gets(tmp);

	} while (strlen(tmp) >= sizeof(user.name) || (strlen(tmp) < 1));

	strcpy(user.name, tmp);






	// ============ 비밀번호 입력 ================
	printf("\n");
	printf("                      >>> 비밀번호를 1-20글자 내로 입력해주세요.  \n");
	printf("                    ┌────────────────────────────────────────┐ \n");
	printf("                    │ password │                             │ \n");
	printf("                    └────────────────────────────────────────┘ \n");
	printf("\n");

	tmp[0] = '\0';			// 임시버퍼 초기화
	i = 0;					// 변수 초기화


	do {
		gotoxy(34, 16);
		printf("                    \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
		gets(tmp);


	} while (strlen(tmp) >= sizeof(user.pw) || (strlen(tmp) < 1));

	strcpy(user.pw, tmp);





	// ============ 부서 입력 ================

	printf("\n");
	printf("                      >>> 부서를 선택해주세요. (0-3)             \n");
	printf("		       원장: 0, 채널: 1, 인프라: 2, 경영지원: 3 \n");
	printf("                    ┌────────────────────────────────────────┐ \n");
	printf("                    │   dept   │                             │ \n");
	printf("                    └────────────────────────────────────────┘ \n");
	printf("\n");

	do {

		gotoxy(34, 21);

		printf("                   \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
		scanf("%d%*c", &i);

	} while (i > (sizeof(user.dept) - 1) || i < 0);

	user.dept = i;





	// ============ 생일 입력 ================

	printf("\n");
	printf("                      >>> 생일을 알려주세요. (YYDD) ex) 0926     \n");
	printf("                    ┌────────────────────────────────────────┐ \n");
	printf("                    │ birthday │                             │ \n");
	printf("                    └────────────────────────────────────────┘ \n");
	printf("\n");


	tmp[0] = '\0';			// 임시버퍼 초기화
	char mon_ch[10], day_ch[10];
	int mon, day;

	while (1)
	{
		do {
			gotoxy(34, 25);
			printf("                   \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
			gets(tmp);

		} while (strlen(tmp) != 4);						// 생일 입력 4자리 넘을시 재입력 요청



		/*
			문자열로 받은 4자리 월/일 2자리씩 끊어,
			int형으로 명시적 변환 후 유효한 날짜인지 재확인
			올바른 입력값이면 GetTimeT 함수로 전달하여 생일에 저장
		*/

		for (i = 0; i < 4; i++)
		{
			if (i < 2)
			{
				mon_ch[i] = tmp[i];
			}
			else
			{
				day_ch[i - 2] = tmp[i];
			}
		}
		mon = atoi(mon_ch);
		day = atoi(day_ch);

		if (mon >= 1 && mon <= 12 && day >= 1 && day <= 31)
			break;


	}	// while(1) end.

	user.birthday = GetTimeT(2023, mon, day, 0, 0);




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
	
	EVENT* personalRoot = NULL;
	EVENT* teamRoot = NULL;

	personalRoot = PrivateFileLoad(&user);
	teamRoot = PublicFileLoad(&user);

	// ============ 로그인 완료화면 ================

	LogOn(&personalRoot, &teamRoot, user, dept_str);


} // SignUp() end.
