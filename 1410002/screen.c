#include "screen.h"

#define MAP_X 3
#define MAP_Y 2
#define MAP_WIDTH 30
#define MAP_HEIGHT 20

#define LEFT 75			// 방향키별 아스키코드값
#define RIGHT 77

//gotoxy 콘솔 커서 좌표 변경 함수
void gotoxy(int x, int y)
{
    COORD pos = { x,y };

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
} // gotoxy() end.





void MainScreen(void)
{
    int i, j;

    //draw_map();    //맵 테두리를 그림 
    for (i = MAP_Y + 1; i < MAP_Y + MAP_HEIGHT - 1; i++) 
    { 
        // 맵 테두리 안쪽을 빈칸으로 채움 
        for (j = MAP_X + 1; j < MAP_X + MAP_WIDTH - 1; j++)
        {
            gotoxy(j, i);
            printf("  ");

        }
    }
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 5);
    printf("┌--------------------------┐");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 6);
    printf("|        14 1000 2         |");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 7);
    printf("└--------------------------┘");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 8, MAP_Y + 10);
    printf("    회원가입 ◁  ▷  로그인   ");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12);
    printf("      TEAM 일사천리     ");


    while (1) 
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
        gotoxy(MAP_X + (MAP_WIDTH / 2) - 8, MAP_Y + 9);
        printf("< 방향키를 눌러 시작해주세요 ! >");
        Sleep(800);
        gotoxy(MAP_X + (MAP_WIDTH / 2) - 8, MAP_Y + 9);
        printf("                                 ");
        Sleep(600);

    }
    
}

void reset(void) 
{
    int i;
    system("cls"); //화면을 지움 
    draw_map(); //맵 테두리를 그림 
}

void draw_map(void) 
{ //맵 테두리 그리는 함수 
    int i, j;
    for (i = 0; i < MAP_WIDTH; i++) 
    {
        gotoxy(MAP_X + i, MAP_Y);
        printf("■");
    }
    for (i = MAP_Y + 1; i < MAP_Y + MAP_HEIGHT - 1; i++) 
    {
        gotoxy(MAP_X, i);
        printf("■");
        gotoxy(MAP_X + MAP_WIDTH - 1, i);
        printf("■");

    }
    for (i = 0; i < MAP_WIDTH; i++) 
    {
        gotoxy(MAP_X + i, MAP_Y + MAP_HEIGHT - 1);
        printf("■");

    }
}
