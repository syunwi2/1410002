#include "signin.h"


// ============ 로그인 함수 ================

void SignIn()
{
	PERSON user;
	char tmp_id[100], tmp_pw[100];		// id, pw 입력값 임시배열
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

	i = 0;								// 변수 초기화
	int buffer = 0;						
	
	
	while (1)
	{
		do {
			gotoxy(0, 4);
			printf("     ID : ");		// ID 입력
			printf("                    \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
			gets(tmp_id);

			printf("\n     PW : ");		// PW 입력
			printf("                    \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");

			while((tmp_pw[i] = getch()) != '\r')
			{

				// 백스페이스 기능 추가 (비밀번호 잘못 입력시 다시 써도 되도록)
				if (tmp_pw[i] == 8)
				{
					printf("\b");
					fputs(" ", stdout);
					printf("\b");

					if (i > 0)
					{
						i--;
					}
				}

				else
				{
					putch('*');
					i++;
				}

				buffer = (int)tmp_pw[i];	// buffer : 입력값이 엔터(13)인지 확인
			}

			tmp_pw[i] = '\0';

		} while (strlen(tmp_id) >= sizeof(user.id) || strlen(tmp_id) < 1		// 설정한 배열값보다 크면 다시 입력받음
				|| strlen(tmp_pw) >= sizeof(user.pw) || strlen(tmp_pw) < 1);


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

		// 기존회원 데이터 구조체변수에 입력
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

		if (flag == 0)						// id, pw 일치하여 flag == 0이면 반복문 중단
		{
			break;
		}
		else
		{
			printf("\n\n     ※  ID / PW를 다시 입력해주세요. \n");	
		}

	} // 바깥 while(1) end.

	EVENT* personalRoot = NULL;
	EVENT* teamRoot = NULL;

	personalRoot = PrivateFileLoad(&user);
	teamRoot = PublicFileLoad(&user);

	LogOn(&personalRoot, &teamRoot, user, dept_str);					// 로그온 함수 호출 (로그인완료 화면)

}
