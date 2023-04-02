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
    char key;			// ����Ű �Է� ����
    while (1)
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
        printf("��        14 1000 2         ��");
        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 7);
        printf("��--------------------------��");
        gotoxy(MAP_X + (MAP_WIDTH / 2) - 8, MAP_Y + 10);
        printf("    ȸ������ ��  ��  �α���   ");
        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12);
        printf("      TEAM �ϻ�õ��     ");

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
            if (flag == 1)
            {
                gotoxy(MAP_X + (MAP_WIDTH / 2) - 8, MAP_Y + 15);
                printf("< ����Ű�� ���� �������ּ��� ! >");
                Sleep(800);
                gotoxy(MAP_X + (MAP_WIDTH / 2) - 8, MAP_Y + 15);
                printf("                                 ");
                Sleep(600);

            }
        }

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

int get_day(int yyyy, int mm);
int get_month(int yyyy, int mm);
int is_leaf_year(int yyyy);
void screen_cal(int start_day, int day_num);


void Calender()
{
    int yyyy, mm, dd; 
    time_t timer = time(NULL);
    struct tm* t = localtime(&timer);
    
    // ���� ���� ��,�� ���
    yyyy = t->tm_year + 1900;
    mm = t->tm_mon + 1;
    dd = t->tm_mday;
    
    int start_day = get_day(yyyy, mm);
    int day_num = get_month(yyyy, mm);

    printf("\n  Today is %d�� %d�� %d�� \n\n", yyyy, mm, dd);
    screen_cal(start_day, day_num);

    
}


void screen_cal(int start_day, int day_num)
{
    printf(" Sun Mon Tue Wed Thu Fri Sat\n");
    for (int i = 0; i < start_day; i++)
        printf("    ");
    for (int day = 1, ke = start_day; day <= day_num; day++, ke++)
    {
        printf("%4d", day);
        if (ke % 7 == 6)
            printf("\n");
    }
}


int get_day(int yyyy, int mm)
{
    int past = 0;
    for (int y = 1; y < yyyy; y++)
        past = past + 365 + is_leaf_year(y);
    for (int m = 1; m < mm; m++)
        past = past + get_month(yyyy, m);
    return (1 + past) % 7;
}


int get_month(int yyyy, int mm)
{
    int day_of_month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    day_of_month[2] += is_leaf_year(yyyy);
    return day_of_month[mm];
}

// ���� ���

int is_leaf_year(int yyyy)
{
    if (yyyy % 400 == 0)
        return 1;
    if ((yyyy % 100 != 0) && (yyyy % 4 == 0))
        return 1;
    return 0;
}