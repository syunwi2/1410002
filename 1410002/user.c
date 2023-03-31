#include <stdio.h>
#include "user.h"
#include "screen.h"

#include <stdlib.h>
#include <string.h>
#include <conio.h>		// 방향키 입력값위한 _kbhit() 의 헤더파일 선언
//void login() {
//	MainScreen();
//}

#define LEFT 75			// 방향키별 아스키코드값
#define RIGHT 77

void Login();
void SignUp();
void SignIn();


int main()
{
	// test용
	printf("왼쪽, 오른쪽 방향키를 눌러주세요. \n");
	Login();

	return 0;
}

void Login() 
{
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
