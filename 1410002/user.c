#include "user.h"

#define LEFT 75			// 방향키별 아스키코드값
#define RIGHT 77


void Login() 
{
	printf("    회원가입 ◁  ▷  로그인     \n");

	char key;			// 방향키 입력 변수
	while (1)
	{
		if (_kbhit())
		{
			key = _getch();
			if (key == -32)
			{
				key = _getch();
				switch (key)
				{
				case LEFT:
					SignUp();
					break;
				case RIGHT:
					SignIn();
					break;
				}

			}
		}
	}
}
