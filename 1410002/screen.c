#include "screen.h"

#define MAP_X 3
#define MAP_Y 2
#define MAP_WIDTH 30
#define MAP_HEIGHT 20

#define LEFT 75			// 방향키별 아스키코드값
#define RIGHT 77





// ============ 커서 좌표 변경 함수 ================

void gotoxy(int x, int y)
{
    COORD pos = { x,y };

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
} // gotoxy() end.





// ============ 첫 화면 함수 ================

void MainScreen(void)
{
    char key;			// 방향키 입력 변수
    while (1)
    {

        int i, j;

        ////DrawMap();    // 테두리를 그림 
        //for (i = MAP_Y + 1; i < MAP_Y + MAP_HEIGHT - 1; i++) 
        //{ 
        //    // 테두리 안쪽을 빈칸으로 채움 
        //    for (j = MAP_X + 1; j < MAP_X + MAP_WIDTH - 1; j++)
        //    {
        //        gotoxy(j, i);
        //        printf("  ");

        //    }
        //}

        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 5);
        printf("┌--------------------------┐");
        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 6);
        printf("│        14 1000 2         │");
        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 7);
        printf("└--------------------------┘");
        gotoxy(MAP_X + (MAP_WIDTH / 2) - 8, MAP_Y + 10);
        printf("    회원가입 ◁  ▷  로그인   ");
        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12);
        printf("      TEAM 일사천리     ");


        // 방향키 <> 입력시 실행 로직
        int flag = 1;
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
                        flag = 0;
                        break;
                    case RIGHT:
                        SignIn();
                        flag = 0;

                        break;
                    }
                }
            }

            // 방향키 <> 외 동작 시 안내문
            if (flag == 1)
            {
                gotoxy(MAP_X + (MAP_WIDTH / 2) - 8, MAP_Y + 15);
                printf("< 방향키를 눌러 시작해주세요 ! >");
                Sleep(800);
                gotoxy(MAP_X + (MAP_WIDTH / 2) - 8, MAP_Y + 15);
                printf("                                 ");
                Sleep(600);

            }
        }

    }
    
}

/*

void Reset(void) 
{
    int i;
    system("cls"); //화면을 지움 
    DrawMap(); //맵 테두리를 그림 
}

// ========== 테두리 그리는 함수 
void DrawMap(void)
{ 
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



*/          // 테두리 그린다면 활성화 =====






// ============ 달력 함수 ================

void Calender()
{
    // 달력 출력 함수
    int yyyy, mm, dd; 
    time_t timer = time(NULL);
    struct tm* t = localtime(&timer);
    
    // 현재 접속 월,일 얻기
    yyyy = t->tm_year + 1900;
    mm = t->tm_mon + 1;
    dd = t->tm_mday;
    

    // 달력 시작일, 종료일 계산
    int start_day = GetDay(yyyy, mm);
    int day_num = GetMonth(yyyy, mm);
    
    printf(" \n\n   \" Today is %d년 %d월 %d일 \" \n", yyyy, mm, dd);
    printf(" ------------------------------ \n");

    
    // 현재 접속 월,일 달력 출력 함수로 전달
    ScreenCal(start_day, day_num);
    
}





// ============ 달력 출력 함수 ================

void ScreenCal(int start_day, int day_num)
{
    printf("  Sun Mon Tue Wed Thu Fri Sat\n");                      // 요일 출력

    int i, day, sd;

    for (i = 0; i < start_day; i++)
    {
        printf("    ");                                             // 첫 주 시작 날짜까지 공백 출력
    }

    for (day = 1, sd = start_day; day <= day_num; day++, sd++)      // 일주일 단위로 일자 출력
    {
        printf("%4d", day);

        if (sd % 7 == 6)
        {
            printf("\n");
        }

    }
}






// ============ 월별 시작 날짜 계산 함수 ================

int GetDay(int yyyy, int mm)
{
    int past = 0, y, m;

    for (y = 1; y < yyyy; y++)
    {
        past = past + 365 + LeafYear(y);
    }

    for (m = 1; m < mm; m++)
    {
        past = past + GetMonth(yyyy, m);
    }

    return (1 + past) % 7;
}





// ============ 월별 마지막 날짜 계산 함수 ================


int GetMonth(int yyyy, int mm)
{
    int day_of_month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    day_of_month[2] += LeafYear(yyyy);
    
    return day_of_month[mm];
}





// ============ 말일 계산 함수 ================

int LeafYear(int yyyy)
{
    if (yyyy % 400 == 0)
        return 1;

    if ((yyyy % 100 != 0) && (yyyy % 4 == 0))
        return 1;

    return 0;

}