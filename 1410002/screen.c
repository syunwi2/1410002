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
        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 2);
        printf("  다우人 일정 관리 서비스 \n");
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
    printf("\n");
    printf("\n");

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


// ============ 로그인 완료  ================
PERSON* UserPtr(PERSON user)
{
    // 구조체 user 동적메모리 할당
    PERSON* user_ptr = malloc(sizeof(PERSON));

    // 구조체 멤버 값 할당
    strcpy(user_ptr->id, user.id);
    strcpy(user_ptr->name, user.name);
    strcpy(user_ptr->pw, user.pw);
    user_ptr->dept = user.dept;
    user_ptr->birthday = user.birthday;

    return user_ptr;
}




// ============ 로그온 함수 ================

void LogOn(PERSON user, char(*dept_str)[20])
{
    PERSON* user_ptr = UserPtr(user);

    system("cls");
    gotoxy(3, 1);
    // Heap에서 데이터 사용
    printf("환영합니다. %s님 :) \n", user_ptr->name);
    printf("\n     id : %3s, 부서 : %3s  \n",
        user_ptr->id, dept_str[user_ptr->dept]);


    // 달력 출력
    Calender();


    PrivateFileLoad(&user);


    // menu 출력
    Menu(user_ptr);


}











// ============ 일정 생성 호출 함수 ================

void CreateEventScreen(PERSON *user_ptr)
{
    EVENT* myevent = NULL;
    char tmp[100], ch;
    int tmp_i, i = 0;

    char hh_ch[10], mm_ch[10];
    int hh, mm;

    time_t start;
    time_t end;

    char title[100];
    TAG tag;
    int isPublic;
    int imPortanceLevel;



    system("cls");
    gotoxy(3, 1);


    
    // Heap에서 데이터 사용

    printf("======== 일정 생성 ========= \n");

    // 1) id => user_ptr->id



    // 2) time_t 

    // ================= start =======================

    tmp[0] = '\0';			// 임시버퍼 초기화
    int date, year, month, day, result = 0;

    while (!result)
    {

        do {

            gotoxy(3, 3);

            printf("\n 일정 시작일 (ex.20140704) : ");
            printf("                    \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");

            gets(tmp);

        } while (strlen(tmp)!=8);


        date = atoi(tmp);

        year = date / 10000;
        month = (date - (year * 10000)) / 100;
        day = date % 100;

        result = checkDate(year, month, day);

    }




    tmp[0] = '\0';			// 임시버퍼 초기화


    while (1)
    {
        do {
            gotoxy(3, 4);
            printf("\n 일정 시작시간 (ex. 1516) : ");
            printf("                   \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
            gets(tmp);

        } while (strlen(tmp) != 4);						// 시간 입력 4자리 넘을시 재입력 요청

        /*
            문자열로 받은 4자리 시/분 2자리씩 끊어,
            int형으로 명시적 변환 후 유효한 시간인지 재확인
            올바른 입력값이면 GetTimeT 함수로 전달하여 시간에 저장
        */

        for (i = 0; i < 4; i++)
        {
            if (i < 2)
            {
                hh_ch[i] = tmp[i];
            }
            else
            {
                mm_ch[i - 2] = tmp[i];
            }
        }
        hh = atoi(hh_ch);
        mm = atoi(mm_ch);

        if (hh >= 1 && hh <= 23 && mm >= 0 && mm <= 59)
            break;


    }	// while(1) end.


    start = GetTimeT(year, month, day, hh, mm);





    // ================= end =======================

    date = 0, year = 0, month = 0, day = 0, result = 0;


    while (!result)
    {

        do {

            gotoxy(3, 6);
            printf("\n 일정 종료일 (ex.20140704) : ");
            printf("                    \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");

            gets(tmp);

        } while (strlen(tmp) != 8);


        date = atoi(tmp);

        year = date / 10000;
        month = (date - (year * 10000)) / 100;
        day = date % 100;

        result = checkDate(year, month, day);

    }



    while (1)
    {
        do {
            gotoxy(3, 7);
            printf("\n 일정 종료시간 (ex. 1516) : ");
            printf("                   \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
            gets(tmp);

        } while (strlen(tmp) != 4);						// 시간 입력 4자리 넘을시 재입력 요청


        for (i = 0; i < 4; i++)
        {
            if (i < 2)
            {
                hh_ch[i] = tmp[i];
            }
            else
            {
                mm_ch[i - 2] = tmp[i];
            }
        }
        hh = atoi(hh_ch);
        mm = atoi(mm_ch);

        if (hh >= 1 && hh <= 23 && mm >= 0 && mm <= 59)
            break;


    }	// while(1) end.


    end = GetTimeT(year, month, day, hh, mm);




    // 3) title

    do {
        printf("\n 일정명 : ");
        printf("                   \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
        gets(tmp);

    } while (strlen(tmp) >= sizeof(myevent->title));
    strcpy(title, tmp);



    // 4) tag

    tmp[0] = '\0';			// 임시버퍼 초기화
    tmp_i = -1;

    do {

        printf("\n # tag  회사 : 0, 개인 : 1, 기타 : 2 ");
        printf("\n Tag : ");
        printf("                   \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
        scanf("%d%*c", &tmp_i);

    } while (tmp_i < 0 && tmp_i >= sizeof(TAG));

    tag = tmp_i;



    // 5) public 여부 1(Y): 공용, 0(N): 개인

    do {
        printf("\n 공개 여부(Y / N) : ");
        printf("                   \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");

        ch = getchar();

    } while (ch != 'y' && ch != 'Y' && ch != 'n' && ch!= 'N');

    if (ch == 'y' || ch == 'Y')
    {
        isPublic = 1;
    }
    else
    {
        isPublic = 0;
    }


    //6) 중요도

    tmp_i = 0; // 변수 초기화

    do {

        printf("\n 중요도 (0-5) : ");
        printf("                   \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");

        scanf("%d%*c", &tmp_i);

    } while (tmp_i > 5 || tmp_i <0);

    imPortanceLevel = tmp_i;
    



    // 입력 전달
    CreateNewEvent(&myevent, user_ptr->id, start, end, title, tag, isPublic, imPortanceLevel);
    

    // 일정 저장 완료 알림

    system("cls");
    gotoxy(3, 1);
    
    printf("일정이 생성되었습니다. :-)");

    gotoxy(3, 5);
    printf("    메인으로 돌아가기 ◁  ▷  일정 추가 생성   ");


    char dept_str[sizeof(user_ptr->dept)][20]
        = { "원장팀", "채널팀", "인프라팀", "경영지원팀" };  // 팀 name 출력하기 위한 배열


    char key;
    // 플래그
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
                    LogOn(*user_ptr, dept_str);
                    break;
                case RIGHT:
                    CreateEventScreen(user_ptr);
                    break;
                }
            }
        }
    }
}




// 날짜 검사 함수 

int checkDate(int year, int month, int day) 
{
    // 월 검사
    if (month <= 0 || 13 <= month)
    {
        return 0;
    }

    // 홀수 달 검사
    if (month % 2 == 1) 
    {
        // 1, 3, 5, 7월은 31일까지 있다.
        if (1 <= month && month <= 7)
        {
            if (day <= 0 || day >= 32)
            {
                return 0;
            }
        }
        // 9, 11월은 30일까지 있다.
        else
        {
            if (day <= 0 || day >= 31) return 0;
        }
    }
    // 짝수 달 검사
    else
    {
        // 2, 4, 6월 검사
        if (month <= 6)
        {
            // 2월 검사
            if (month == 2)
            {
                // 2월은 윤년에는 29일까지 있다.
                if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
                {
                    if (day <= 0 || day >= 30)
                    {
                        return 0;
                    }
                }
                // 2월은 평년에는 28일까지 있다.
                else if (day <= 0 || day >= 29)
                {
                    return 0;
                }
            }
            // 4, 6월 검사
            else
            {
                // 4, 6월은 30일까지 있다.
                if (day <= 0 || day >= 31)
                {
                    return 0;
                }
            }
        }
        // 8, 10, 12월 검사
        else {
            // 8, 10, 12월은 31일까지 있다.
            if (day <= 0 || day >= 32)
            {
                return 0;
            }
        }
    }
    return 1;
}




