#include "screen.h"

#define MAP_X 3
#define MAP_Y 2
#define MAP_WIDTH 30
#define MAP_HEIGHT 20

#define LEFT 75			// ����Ű�� �ƽ�Ű�ڵ尪
#define RIGHT 77



void textcolor(int colorNum) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
}

// ============ Ŀ�� ��ǥ ���� �Լ� ================

void gotoxy(int x, int y)
{
    COORD pos = { x,y };

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
} // gotoxy() end.





// ============ ù ȭ�� �Լ� ================

void MainScreen(void)
{
    textcolor(15);
    char key;			// ����Ű �Է� ����
    while (1)
    {

        int i, j;

        printf("                                                                                 \n");
        printf("                                                                                 \n");
        printf("                                                                                 \n");
        printf("                                                                                 \n");
        printf("                                                                                 \n");
        printf("                                                                                 \n");
        printf("             ��������������������������������������������������������������������������������������������������������������������              \n");
        printf("             ��                �ٿ��� ���� ���� ����                 ��             \n");
        printf("             ��������������������������������������������������������������������������������������������������������������������               \n");
        printf("             ��                                                        ��               \n");
        printf("             ��                                                        ��               \n");
        printf("             ��             ��������������������������������������������������������               ��               \n");
        printf("             ��             ��        1 4 1000 2        ��               ��               \n");
        printf("             ��             ��������������������������������������������������������               ��               \n");
        printf("             ��                                                        ��               \n");
        printf("             ��                                                        ��               \n");
        printf("             ��                                                        ��               \n");
        printf("             ��               ȸ������ ��  ��  �α���                  ��               \n");
        printf("             ��                                                        ��               \n");
        printf("             ��                                                        ��               \n");
        printf("             ��                                                        ��               \n");
        printf("             ��                                                        ��               \n");
        printf("             ��                                                        ��               \n");
        printf("             ��                                                        ��               \n");
        printf("             ��                                                        ��               \n");
        printf("             ��                                                        ��               \n");
        printf("             ��                    TEAM �ϻ�õ��                       ��               \n");
        printf("             ��                                                        ��               \n");
        printf("             ��������������������������������������������������������������������������������������������������������������������               \n");
        printf("                                                                                 \n");



        // ����Ű <> �Է½� ���� ����
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

            // ����Ű <> �� ���� �� �ȳ���
            if (flag == 1)
            {
                textcolor(14);

                gotoxy(MAP_X + (MAP_WIDTH / 2 + 8) , MAP_Y + 19);
                printf("< ����Ű�� ���� �������ּ��� ! >");
                Sleep(800);
                gotoxy(MAP_X + (MAP_WIDTH / 2 + 8) , MAP_Y + 19);
                printf("                                 ");
                Sleep(600);

            }


        }

    }


}



// ============ �޷� �Լ� ================

void Calender()
{
    // �޷� ��� �Լ�
    int yyyy, mm, dd; 
    time_t timer = time(NULL);
    struct tm* t = localtime(&timer);
    
    // ���� ���� ��,�� ���
    yyyy = t->tm_year + 1900;
    mm = t->tm_mon + 1;
    dd = t->tm_mday;
    

    // �޷� ������, ������ ���
    int start_day = GetDay(yyyy, mm);
    int day_num = GetMonth(yyyy, mm);
    
    textcolor(15);
    printf(" \n\n     \" Today is %d�� %d�� %d�� \" \n", yyyy, mm, dd);
    textcolor(14);
    printf("  �������������������������������������������������������������������� \n");

    
    // ���� ���� ��,�� �޷� ��� �Լ��� ����
    ScreenCal(start_day, day_num);
    
}



// ============ �޷� ��� �Լ� ================

void ScreenCal(int start_day, int day_num)
{                 
    textcolor(14);
    printf("   Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");                      // ���� ���

    int i, day, sd;
    textcolor(15);

    for (i = 0; i < start_day; i++)
    {
        printf("     ");                                             // ù �� ���� ��¥���� ���� ���
    }

    for (day = 1, sd = start_day; day <= day_num; day++, sd++)      // ������ ������ ���� ���
    {
        printf(" ");                                          
        printf("%4d", day);

        if (sd % 7 == 6)
        {
            printf("\n");
        }

    }
    printf("\n");
    printf("\n");

}






// ============ ���� ���� ��¥ ��� �Լ� ================

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





// ============ ���� ������ ��¥ ��� �Լ� ================


int GetMonth(int yyyy, int mm)
{
    int day_of_month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    day_of_month[2] += LeafYear(yyyy);
    
    return day_of_month[mm];
}





// ============ ���� ��� �Լ� ================

int LeafYear(int yyyy)
{
    if (yyyy % 400 == 0)
        return 1;

    if ((yyyy % 100 != 0) && (yyyy % 4 == 0))
        return 1;

    return 0;

}


// ============ �α��� �Ϸ�  ================
PERSON* UserPtr(PERSON user)
{
    // ����ü user �����޸� �Ҵ�
    PERSON* user_ptr = malloc(sizeof(PERSON));

    // ����ü ��� �� �Ҵ�
    strcpy(user_ptr->id, user.id);
    strcpy(user_ptr->name, user.name);
    strcpy(user_ptr->pw, user.pw);
    user_ptr->dept = user.dept;
    user_ptr->birthday = user.birthday;

    return user_ptr;
}




// ============ �α׿� �Լ� ================

void LogOn(EVENT** personalRoot, EVENT** teamRoot, PERSON user, char(*dept_str)[20])
{
    PERSON* user_ptr = UserPtr(user);

    system("cls");
    Calender();
    gotoxy(55, 2);
    // Heap���� ������ ���
    textcolor(14);
    printf(" ȯ���մϴ�. %s�� :) \n", user_ptr->name);
    textcolor(15);
    gotoxy(55, 4);
    printf("�������������������������������������������� ");
    gotoxy(55, 5);
    printf("��  id ��              �� ");
    gotoxy(55, 6);
    printf("��������������������������������������������");
    gotoxy(55, 7);
    printf("�� �μ���              ��");
    gotoxy(55, 8);
    printf("�������������������������������������������� \n");

    gotoxy(64, 5);
    printf("%3s \n", user_ptr->id);
    gotoxy(64, 7);
    printf("%3s \n", dept_str[user_ptr->dept]);

    PrivateFileLoad(&user);
    PublicFileLoad(&user);



    // menu ���
    Menu(personalRoot, teamRoot, user_ptr);


}











// ============ ���� ���� ȣ�� �Լ� ================

void CreateEventScreen(EVENT** personalRoot, EVENT** teamRoot, PERSON *user_ptr)
{
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


    printf("\n");
    textcolor(14);
    printf("                             �������� ���� �ۼ��� ��������                         \n");
    printf("              ����������������������������������������������������������������������������������������������������������������           \n");
    printf("                                                                                 \n");
    printf("               �� ���ڴ� 'YYYYMMDD' �������� �ۼ��ϼ���. (ex.20140704)             \n");
    printf("               �� �ð��� 'HHMM' �������� �ۼ��ϼ���.     (ex.  1516  )             \n");
    printf("               �� �������� 50���� ���� �ۼ��ϼ���.                                 \n");
    printf("               �� �±״� '0-3 �� ����'�� �ۼ��ϼ���.                               \n");
    printf("                  # tag  ȸ�� : 0, ���� : 1, ��Ÿ : 2                            \n");
    printf("               ������ ���� ���ο� ���� Y �Ǵ� N���� �ۼ��ϼ���.                    \n");
    printf("               ������ �߿䵵�� ���� '0-5 �� ����'�� �ۼ��ϼ���.                    \n");
    printf("                                                                                 \n");
    printf("              ����������������������������������������������������������������������������������������������������������������          \n");

    textcolor(15);
    printf("            ���������������������������������������������������������������������������������������������������������������������� \n");
    printf("            ��   ������       ��                                        �� \n");
    printf("            ��   ���۽ð�     ��                                        �� \n");
    printf("            ���������������������������������������������������������������������������������������������������������������������� \n");
    printf("            ��   ������       ��                                        �� \n");
    printf("            ��   ����ð�     ��                                        �� \n");
    printf("            ���������������������������������������������������������������������������������������������������������������������� \n");
    printf("            ��   ������       ��                                        �� \n");
    printf("            ���������������������������������������������������������������������������������������������������������������������� \n");
    printf("            ��   #Tag (0-3)   ��                                        �� \n");
    printf("            ���������������������������������������������������������������������������������������������������������������������� \n");
    printf("            ��   ���� (Y / N) ��                                        �� \n");
    printf("            ���������������������������������������������������������������������������������������������������������������������� \n");
    printf("            ��   �߿䵵 (0-5) ��                                        �� \n");
    printf("            ���������������������������������������������������������������������������������������������������������������������� \n");



    tmp[0] = '\0';			// �ӽù��� �ʱ�ȭ
    int date, year, month, day, result = 0;


    while (!result)
    {

        do {

            gotoxy(32, 15);
            printf("                    \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");

            gets(tmp);

        } while (strlen(tmp)!=8);


        date = atoi(tmp);

        year = date / 10000;
        month = (date - (year * 10000)) / 100;
        day = date % 100;

        result = checkDate(year, month, day);

    }


    tmp[0] = '\0';			// �ӽù��� �ʱ�ȭ


    while (1)
    {
        do {
            gotoxy(33, 16);
            printf("                   \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
            gets(tmp);

        } while (strlen(tmp) != 4);						// �ð� �Է� 4�ڸ� ������ ���Է� ��û

        /*
            ���ڿ��� ���� 4�ڸ� ��/�� 2�ڸ��� ����,
            int������ ����� ��ȯ �� ��ȿ�� �ð����� ��Ȯ��
            �ùٸ� �Է°��̸� GetTimeT �Լ��� �����Ͽ� �ð��� ����
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

            gotoxy(32, 18);
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
            gotoxy(33, 19);
            printf("                   \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
            gets(tmp);

        } while (strlen(tmp) != 4);						// �ð� �Է� 4�ڸ� ������ ���Է� ��û


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
        gotoxy(33, 21);
        printf("                   \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
        gets(tmp);

    } while (strlen(tmp) >= sizeof((*personalRoot)->title));
    strcpy(title, tmp);



    // 4) tag

    tmp[0] = '\0';			// �ӽù��� �ʱ�ȭ
    tmp_i = -1;

    do {

        gotoxy(33, 23);
        printf("                   \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
        scanf("%d%*c", &tmp_i);

    } while (tmp_i < 0 && tmp_i >= sizeof(TAG));

    tag = tmp_i;



    // 5) public ���� 1(Y): ����, 0(N): ����

    do {
        gotoxy(33, 25);
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


    //6) �߿䵵

    tmp_i = 0; // ���� �ʱ�ȭ

    do {

        gotoxy(33, 27);


        printf("                   \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");

        scanf("%d%*c", &tmp_i);

    } while (tmp_i > 5 || tmp_i <0);

    imPortanceLevel = tmp_i;
    

    // �Է� ����
    CreateNewEvent(personalRoot, user_ptr->id, start, end, title, tag, isPublic, imPortanceLevel);
    if (isPublic)
    {
        CreateNewEvent(teamRoot, user_ptr->id, start, end, title, tag, isPublic, imPortanceLevel);
    }

    // ���� ���� �Ϸ� �˸�

    system("cls");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("            ����������������������������������������������������������������������������������������������������������������           \n");
    printf("                                                                               \n");
    printf("                         �� ������ �����Ǿ����ϴ�. :-)                           \n");
    printf("                                                                               \n");
    printf("                                                                               \n");
    printf("                    �������� ���ư��� ��  ��  ���� �߰� ����                       \n");
    printf("                                                                               \n");
    printf("                                                                               \n");
    printf("            ����������������������������������������������������������������������������������������������������������������          \n");
    printf("\n");
    printf("\n");



    char dept_str[sizeof(user_ptr->dept)][20]
        = { "������", "ä����", "��������", "�濵������" };  // �� name ����ϱ� ���� �迭


    char key;
    // �÷���
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
                    //LogOn(*user_ptr, dept_str);
                    LogOn(personalRoot, teamRoot, *user_ptr, dept_str);
                    break;
                case RIGHT:
                    CreateEventScreen(personalRoot, teamRoot, user_ptr);
                    break;
                }
            }
        }
    }



}




// ��¥ �˻� �Լ� 

int checkDate(int year, int month, int day) 
{
    // �� �˻�
    if (month <= 0 || 13 <= month)
    {
        return 0;
    }

    // Ȧ�� �� �˻�
    if (month % 2 == 1) 
    {
        // 1, 3, 5, 7���� 31�ϱ��� �ִ�.
        if (1 <= month && month <= 7)
        {
            if (day <= 0 || day >= 32)
            {
                return 0;
            }
        }
        // 9, 11���� 30�ϱ��� �ִ�.
        else
        {
            if (day <= 0 || day >= 31) return 0;
        }
    }
    // ¦�� �� �˻�
    else
    {
        // 2, 4, 6�� �˻�
        if (month <= 6)
        {
            // 2�� �˻�
            if (month == 2)
            {
                // 2���� ���⿡�� 29�ϱ��� �ִ�.
                if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
                {
                    if (day <= 0 || day >= 30)
                    {
                        return 0;
                    }
                }
                // 2���� ��⿡�� 28�ϱ��� �ִ�.
                else if (day <= 0 || day >= 29)
                {
                    return 0;
                }
            }
            // 4, 6�� �˻�
            else
            {
                // 4, 6���� 30�ϱ��� �ִ�.
                if (day <= 0 || day >= 31)
                {
                    return 0;
                }
            }
        }
        // 8, 10, 12�� �˻�
        else {
            // 8, 10, 12���� 31�ϱ��� �ִ�.
            if (day <= 0 || day >= 32)
            {
                return 0;
            }
        }
    }
    return 1;
}




