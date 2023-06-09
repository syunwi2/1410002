#include "screen.h"

#define MAP_X 3
#define MAP_Y 2
#define MAP_WIDTH 30
#define MAP_HEIGHT 20

#define LEFT 75			// 寞щ酈滌 嬴蝶酈囀萄高
#define RIGHT 77



void textcolor(int colorNum) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
}

// ============ 醴憮 謝ル 滲唳 л熱 ================

void gotoxy(int x, int y)
{
    COORD pos = { x,y };

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
} // gotoxy() end.





// ============ 羅 �飛� л熱 ================

void MainScreen(void)
{
    textcolor(15);
    char key;			// 寞щ酈 殮溘 滲熱
    while (1)
    {

        int i, j;

        printf("                                                                                 \n");
        printf("                                                                                 \n");
        printf("                                                                                 \n");
        printf("                                                                                 \n");
        printf("                                                                                 \n");
        printf("                                                                                 \n");
        printf("             忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖              \n");
        printf("             弛                棻辦嬣 橾薑 婦葬 憮綠蝶                 弛             \n");
        printf("             戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣               \n");
        printf("             弛                                                        弛               \n");
        printf("             弛                                                        弛               \n");
        printf("             弛             忙式式式式式式式式式式式式式式式式式式式式式式式式式式忖               弛               \n");
        printf("             弛             弛        1 4 1000 2        弛               弛               \n");
        printf("             弛             戌式式式式式式式式式式式式式式式式式式式式式式式式式式戎               弛               \n");
        printf("             弛                                                        弛               \n");
        printf("             弛                                                        弛               \n");
        printf("             弛                                                        弛               \n");
        printf("             弛               �蛾灠㊣� ８  Ⅰ  煎斜檣                  弛               \n");
        printf("             弛                                                        弛               \n");
        printf("             弛                                                        弛               \n");
        printf("             弛                                                        弛               \n");
        printf("             弛                                                        弛               \n");
        printf("             弛                                                        弛               \n");
        printf("             弛                                                        弛               \n");
        printf("             弛                                                        弛               \n");
        printf("             弛                                                        弛               \n");
        printf("             弛                    TEAM 橾餌繭葬                       弛               \n");
        printf("             弛                                                        弛               \n");
        printf("             戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎               \n");
        printf("                                                                                 \n");



        // 寞щ酈 <> 殮溘衛 褒ч 煎霜
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

            // 寞щ酈 <> 諼 翕濛 衛 寰頂僥
            if (flag == 1)
            {
                textcolor(14);

                gotoxy(MAP_X + (MAP_WIDTH / 2 + 8), MAP_Y + 19);
                printf("< 寞щ酈蒂 揚楝 衛濛п輿撮蹂 ! >");
                Sleep(800);
                gotoxy(MAP_X + (MAP_WIDTH / 2 + 8), MAP_Y + 19);
                printf("                                 ");
                Sleep(600);

            }


        }

    }


}



// ============ 殖溘 л熱 ================

void Calender()
{
    // 殖溘 轎溘 л熱
    int yyyy, mm, dd;
    time_t timer = time(NULL);
    struct tm* t = localtime(&timer);

    // ⑷營 蕾樓 錯,橾 橢晦
    yyyy = t->tm_year + 1900;
    mm = t->tm_mon + 1;
    dd = t->tm_mday;


    // 殖溘 衛濛橾, 謙猿橾 啗骯
    int start_day = GetDay(yyyy, mm);
    int day_num = GetMonth(yyyy, mm);

    textcolor(15);
    printf(" \n\n     \" Today is %d喇 %d錯 %d橾 \" \n", yyyy, mm, dd);
    textcolor(14);
    printf("  式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式 \n");


    // ⑷營 蕾樓 錯,橾 殖溘 轎溘 л熱煎 瞪殖
    ScreenCal(start_day, day_num);

}



// ============ 殖溘 轎溘 л熱 ================

void ScreenCal(int start_day, int day_num)
{
    textcolor(14);
    printf("   Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");                      // 蹂橾 轎溘

    int i, day, sd;
    textcolor(15);

    for (i = 0; i < start_day; i++)
    {
        printf("     ");                                             // 羅 輿 衛濛 陳瞼梱雖 奢寥 轎溘
    }

    for (day = 1, sd = start_day; day <= day_num; day++, sd++)      // 橾輿橾 欽嬪煎 橾濠 轎溘
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






// ============ 錯滌 衛濛 陳瞼 啗骯 л熱 ================

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





// ============ 錯滌 葆雖虞 陳瞼 啗骯 л熱 ================


int GetMonth(int yyyy, int mm)
{
    int day_of_month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    day_of_month[2] += LeafYear(yyyy);

    return day_of_month[mm];
}





// ============ 蜓橾 啗骯 л熱 ================

int LeafYear(int yyyy)
{
    if (yyyy % 400 == 0)
        return 1;

    if ((yyyy % 100 != 0) && (yyyy % 4 == 0))
        return 1;

    return 0;

}


// ============ 煎斜檣 諫猿  ================
PERSON* UserPtr(PERSON user)
{
    // 掘褻羹 user 翕瞳詭賅葬 й渡
    PERSON* user_ptr = malloc(sizeof(PERSON));

    // 掘褻羹 詹幗 高 й渡
    strcpy(user_ptr->id, user.id);
    strcpy(user_ptr->name, user.name);
    strcpy(user_ptr->pw, user.pw);
    user_ptr->dept = user.dept;
    user_ptr->birthday = user.birthday;

    return user_ptr;
}




// ============ 煎斜螞 л熱 ================

void LogOn(EVENT** personalRoot, EVENT** teamRoot, PERSON user, char(*dept_str)[20])
{
    PERSON* user_ptr = UserPtr(user);

    system("cls");
    Calender();
    gotoxy(55, 2);
    // Heap縑憮 等檜攪 餌辨
    textcolor(14);
    printf(" �紊腎桭炴�. %s椒 :) \n", user_ptr->name);
    textcolor(15);
    gotoxy(55, 4);
    printf("忙式式式式式成式式式式式式式式式式式式式式忖 ");
    gotoxy(55, 5);
    printf("弛  id 弛              弛 ");
    gotoxy(55, 6);
    printf("戍式式式式式托式式式式式式式式式式式式式式扣");
    gotoxy(55, 7);
    printf("弛 睡憮弛              弛");
    gotoxy(55, 8);
    printf("戌式式式式式扛式式式式式式式式式式式式式式戎 \n");

    gotoxy(64, 5);
    printf("%3s \n", user_ptr->id);
    gotoxy(64, 7);
    printf("%3s \n", dept_str[user_ptr->dept]);

    PrivateFileLoad(&user);
    PublicFileLoad(&user);



    // menu 轎溘
    Menu(personalRoot, teamRoot, user_ptr);


}











// ============ 橾薑 儅撩 ��轎 л熱 ================

void CreateEventScreen(EVENT** personalRoot, EVENT** teamRoot, PERSON* user_ptr)
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
    printf("                             ㄙㄙㄙㄙ 橾薑 濛撩徹 ㄙㄙㄙㄙ                         \n");
    printf("              式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式           \n");
    printf("                                                                                 \n");
    printf("               ㄙ 橾濠朝 'YYYYMMDD' ⑽衝戲煎 濛撩ж撮蹂. (ex.20140704)             \n");
    printf("               ㄙ 衛除擎 'HHMM' ⑽衝戲煎 濛撩ж撮蹂.     (ex.  1516  )             \n");
    printf("               ㄙ 橾薑貲擎 50旋濠 頂煎 濛撩ж撮蹂.                                 \n");
    printf("               ㄙ 鷓斜朝 '0-2 頂 璋濠'煎 濛撩ж撮蹂.                               \n");
    printf("                  # tag  �蜓� : 0, 偃檣 : 1, 晦顫 : 2                            \n");
    printf("               ㄙ橾薑 奢嶸 罹睡縑 渠п Y 傳朝 N戲煎 濛撩ж撮蹂.                    \n");
    printf("               ㄙ橾薑 醞蹂紫縑 渠п '0-5 頂 璋濠'煎 濛撩ж撮蹂.                    \n");
    printf("                                                                                 \n");
    printf("              式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式          \n");

    textcolor(15);
    printf("            忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖 \n");
    printf("            弛   衛濛橾       弛                                        弛 \n");
    printf("            弛   衛濛衛除     弛                                        弛 \n");
    printf("            戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣 \n");
    printf("            弛   謙猿橾       弛                                        弛 \n");
    printf("            弛   謙猿衛除     弛                                        弛 \n");
    printf("            戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣 \n");
    printf("            弛   橾薑貲       弛                                        弛 \n");
    printf("            戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣 \n");
    printf("            弛   #Tag (0-2)   弛                                        弛 \n");
    printf("            戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣 \n");
    printf("            弛   奢偃 (Y / N) 弛                                        弛 \n");
    printf("            戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣 \n");
    printf("            弛   醞蹂紫 (0-5) 弛                                        弛 \n");
    printf("            戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎 \n");



    tmp[0] = '\0';			// 歜衛幗ぷ 蟾晦��
    int date, year, month, day, result = 0;


    while (!result)
    {

        do {

            gotoxy(32, 15);
            printf("                    \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");

            gets(tmp);

        } while (strlen(tmp) != 8);


        date = atoi(tmp);

        year = date / 10000;
        month = (date - (year * 10000)) / 100;
        day = date % 100;

        result = checkDate(year, month, day);

    }


    tmp[0] = '\0';			// 歜衛幗ぷ 蟾晦��


    while (1)
    {
        do {
            gotoxy(33, 16);
            printf("                   \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
            gets(tmp);

        } while (strlen(tmp) != 4);						// 衛除 殮溘 4濠葬 剩擊衛 營殮溘 蹂羶

        /*
            僥濠翮煎 嫡擎 4濠葬 衛/碟 2濠葬噶 莒橫,
            int⑽戲煎 貲衛瞳 滲�� �� 嶸�褲� 衛除檣雖 營�挫�
            螢夥艇 殮溘高檜賊 GetTimeT л熱煎 瞪殖ж罹 衛除縑 盪濰
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

        } while (strlen(tmp) != 4);						// 衛除 殮溘 4濠葬 剩擊衛 營殮溘 蹂羶


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

    tmp[0] = '\0';			// 歜衛幗ぷ 蟾晦��
    tmp_i = -1;

    do {

        gotoxy(33, 23);
        printf("                   \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
        scanf("%d%*c", &tmp_i);

    } while (tmp_i < 0 && tmp_i >= sizeof(TAG));

    tag = tmp_i;



    // 5) public 罹睡 1(Y): 奢辨, 0(N): 偃檣

    do {
        gotoxy(33, 25);
        printf("                   \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");

        ch = getchar();

    } while (ch != 'y' && ch != 'Y' && ch != 'n' && ch != 'N');

    if (ch == 'y' || ch == 'Y')
    {
        isPublic = 1;
    }
    else
    {
        isPublic = 0;
    }


    //6) 醞蹂紫

    tmp_i = 0; // 滲熱 蟾晦��

    do {

        gotoxy(33, 27);


        printf("                   \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");

        scanf("%d%*c", &tmp_i);

    } while (tmp_i > 5 || tmp_i < 0);

    imPortanceLevel = tmp_i;


    // 殮溘 瞪殖
    CreateNewEvent(personalRoot, user_ptr->id, start, end, title, tag, isPublic, imPortanceLevel);
    if (isPublic)
    {
        CreateNewEvent(teamRoot, user_ptr->id, start, end, title, tag, isPublic, imPortanceLevel);
    }

    // 橾薑 盪濰 諫猿 憲葡

    system("cls");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("            式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式           \n");
    printf("                                                                               \n");
    printf("                         ㄙ 橾薑檜 儅撩腎歷蝗棲棻. :-)                           \n");
    printf("                                                                               \n");
    printf("                                                                               \n");
    printf("                    詭檣戲煎 給嬴陛晦 ８  Ⅰ  橾薑 蹺陛 儅撩                       \n");
    printf("                                                                               \n");
    printf("                                                                               \n");
    printf("            式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式          \n");
    printf("\n");
    printf("\n");



    char dept_str[sizeof(user_ptr->dept)][20]
        = { "錳濰ぜ", "瓣割ぜ", "檣Щ塭ぜ", "唳艙雖錳ぜ" };  // ぜ name 轎溘ж晦 嬪и 寡翮


    char key;
    // Ы楚斜
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




// 陳瞼 匐餌 л熱 

int checkDate(int year, int month, int day)
{
    // 錯 匐餌
    if (month <= 0 || 13 <= month)
    {
        return 0;
    }

    // �汝� 殖 匐餌
    if (month % 2 == 1)
    {
        // 1, 3, 5, 7錯擎 31橾梱雖 氈棻.
        if (1 <= month && month <= 7)
        {
            if (day <= 0 || day >= 32)
            {
                return 0;
            }
        }
        // 9, 11錯擎 30橾梱雖 氈棻.
        else
        {
            if (day <= 0 || day >= 31) return 0;
        }
    }
    // 礎熱 殖 匐餌
    else
    {
        // 2, 4, 6錯 匐餌
        if (month <= 6)
        {
            // 2錯 匐餌
            if (month == 2)
            {
                // 2錯擎 彌喇縑朝 29橾梱雖 氈棻.
                if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
                {
                    if (day <= 0 || day >= 30)
                    {
                        return 0;
                    }
                }
                // 2錯擎 ゎ喇縑朝 28橾梱雖 氈棻.
                else if (day <= 0 || day >= 29)
                {
                    return 0;
                }
            }
            // 4, 6錯 匐餌
            else
            {
                // 4, 6錯擎 30橾梱雖 氈棻.
                if (day <= 0 || day >= 31)
                {
                    return 0;
                }
            }
        }
        // 8, 10, 12錯 匐餌
        else {
            // 8, 10, 12錯擎 31橾梱雖 氈棻.
            if (day <= 0 || day >= 32)
            {
                return 0;
            }
        }
    }
    return 1;
}




