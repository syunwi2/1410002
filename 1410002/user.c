#include <stdio.h>
#include "user.h"
#include "screen.h"

#include <stdlib.h>
#include <string.h>
#include <conio.h>		// ����Ű �Է°����� _kbhit() �� ������� ����
//void login() {
//	MainScreen();
//}

#define LEFT 75			// ����Ű�� �ƽ�Ű�ڵ尪
#define RIGHT 77

void Login();
void SignUp();
void SignIn();


int main()
{
	// test��
	printf("����, ������ ����Ű�� �����ּ���. \n");
	Login();

	return 0;
}

void Login() 
{
	char key;			// ����Ű �Է� ����
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
