#include "screen.h"

#define MAP_X 3
#define MAP_Y 2
#define MAP_WIDTH 30
#define MAP_HEIGHT 20

#define LEFT 75			// ����Ű�� �ƽ�Ű�ڵ尪
#define RIGHT 77

//gotoxy �ܼ� Ŀ�� ��ǥ ���� �Լ�
void gotoxy(int x, int y)
{
    COORD pos = { x,y };

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
} // gotoxy() end.





void MainScreen(void)
{
    int i, j;

    //draw_map();    //�� �׵θ��� �׸� 
    for (i = MAP_Y + 1; i < MAP_Y + MAP_HEIGHT - 1; i++) 
    { 
        // �� �׵θ� ������ ��ĭ���� ä�� 
        for (j = MAP_X + 1; j < MAP_X + MAP_WIDTH - 1; j++)
        {
            gotoxy(j, i);
            printf("  ");

        }
    }
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 5);
    printf("��--------------------------��");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 6);
    printf("|        14 1000 2         |");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 7);
    printf("��--------------------------��");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 8, MAP_Y + 10);
    printf("    ȸ������ ��  ��  �α���   ");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12);
    printf("      TEAM �ϻ�õ��     ");


    while (1) 
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
        gotoxy(MAP_X + (MAP_WIDTH / 2) - 8, MAP_Y + 9);
        printf("< ����Ű�� ���� �������ּ��� ! >");
        Sleep(800);
        gotoxy(MAP_X + (MAP_WIDTH / 2) - 8, MAP_Y + 9);
        printf("                                 ");
        Sleep(600);

    }
    
}

void reset(void) 
{
    int i;
    system("cls"); //ȭ���� ���� 
    draw_map(); //�� �׵θ��� �׸� 
}

void draw_map(void) 
{ //�� �׵θ� �׸��� �Լ� 
    int i, j;
    for (i = 0; i < MAP_WIDTH; i++) 
    {
        gotoxy(MAP_X + i, MAP_Y);
        printf("��");
    }
    for (i = MAP_Y + 1; i < MAP_Y + MAP_HEIGHT - 1; i++) 
    {
        gotoxy(MAP_X, i);
        printf("��");
        gotoxy(MAP_X + MAP_WIDTH - 1, i);
        printf("��");

    }
    for (i = 0; i < MAP_WIDTH; i++) 
    {
        gotoxy(MAP_X + i, MAP_Y + MAP_HEIGHT - 1);
        printf("��");

    }
}
