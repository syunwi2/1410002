#include "user.h"

#define LEFT 75			// ����Ű�� �ƽ�Ű�ڵ尪
#define RIGHT 77


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
