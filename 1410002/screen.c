#include "screen.h"

#define MAP_X 3
#define MAP_Y 2
#define MAP_WIDTH 30
#define MAP_HEIGHT 20

#define LEFT 75			// ¹æÇâÅ°º° ¾Æ½ºÅ°ÄÚµå°ª
#define RIGHT 77



void textcolor(int colorNum) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
}

// ============ Ä¿¼­ ÁÂÇ¥ º¯°æ ÇÔ¼ö ================

void gotoxy(int x, int y)
{
    COORD pos = { x,y };

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
} // gotoxy() end.





// ============ Ã¹ È­¸é ÇÔ¼ö ================

void MainScreen(void)
{
    textcolor(15);
    char key;			// ¹æÇâÅ° ÀÔ·Â º¯¼ö
    while (1)
    {

        int i, j;

        printf("                                                                                 \n");
        printf("                                                                                 \n");
        printf("                                                                                 \n");
        printf("                                                                                 \n");
        printf("                                                                                 \n");
        printf("                                                                                 \n");
        printf("             ¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤              \n");
        printf("             ¦¢                ´Ù¿ììÑ ÀÏÁ¤ °ü¸® ¼­ºñ½º                 ¦¢             \n");
        printf("             ¦§¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦©               \n");
        printf("             ¦¢                                                        ¦¢               \n");
        printf("             ¦¢                                                        ¦¢               \n");
        printf("             ¦¢             ¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤               ¦¢               \n");
        printf("             ¦¢             ¦¢        1 4 1000 2        ¦¢               ¦¢               \n");
        printf("             ¦¢             ¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥               ¦¢               \n");
        printf("             ¦¢                                                        ¦¢               \n");
        printf("             ¦¢                                                        ¦¢               \n");
        printf("             ¦¢                                                        ¦¢               \n");
        printf("             ¦¢               È¸¿ø°¡ÀÔ ¢·  ¢¹  ·Î±×ÀÎ                  ¦¢               \n");
        printf("             ¦¢                                                        ¦¢               \n");
        printf("             ¦¢                                                        ¦¢               \n");
        printf("             ¦¢                                                        ¦¢               \n");
        printf("             ¦¢                                                        ¦¢               \n");
        printf("             ¦¢                                                        ¦¢               \n");
        printf("             ¦¢                                                        ¦¢               \n");
        printf("             ¦¢                                                        ¦¢               \n");
        printf("             ¦¢                                                        ¦¢               \n");
        printf("             ¦¢                    TEAM ÀÏ»çÃµ¸®                       ¦¢               \n");
        printf("             ¦¢                                                        ¦¢               \n");
        printf("             ¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥               \n");
        printf("                                                                                 \n");



        // ¹æÇâÅ° <> ÀÔ·Â½Ã ½ÇÇà ·ÎÁ÷
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

            // ¹æÇâÅ° <> ¿Ü µ¿ÀÛ ½Ã ¾È³»¹®
            if (flag == 1)
            {
                textcolor(14);

                gotoxy(MAP_X + (MAP_WIDTH / 2 + 8) , MAP_Y + 19);
                printf("< ¹æÇâÅ°¸¦ ´­·¯ ½ÃÀÛÇØÁÖ¼¼¿ä ! >");
                Sleep(800);
                gotoxy(MAP_X + (MAP_WIDTH / 2 + 8) , MAP_Y + 19);
                printf("                                 ");
                Sleep(600);

            }


        }

    }


}



// ============ ´Þ·Â ÇÔ¼ö ================

void Calender()
{
    // ´Þ·Â Ãâ·Â ÇÔ¼ö
    int yyyy, mm, dd; 
    time_t timer = time(NULL);
    struct tm* t = localtime(&timer);
    
    // ÇöÀç Á¢¼Ó ¿ù,ÀÏ ¾ò±â
    yyyy = t->tm_year + 1900;
    mm = t->tm_mon + 1;
    dd = t->tm_mday;
    

    // ´Þ·Â ½ÃÀÛÀÏ, Á¾·áÀÏ °è»ê
    int start_day = GetDay(yyyy, mm);
    int day_num = GetMonth(yyyy, mm);
    
    textcolor(15);
    printf(" \n\n     \" Today is %d³â %d¿ù %dÀÏ \" \n", yyyy, mm, dd);
    textcolor(14);
    printf("  ¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡ \n");

    
    // ÇöÀç Á¢¼Ó ¿ù,ÀÏ ´Þ·Â Ãâ·Â ÇÔ¼ö·Î Àü´Þ
    ScreenCal(start_day, day_num);
    
}



// ============ ´Þ·Â Ãâ·Â ÇÔ¼ö ================

void ScreenCal(int start_day, int day_num)
{                 
    textcolor(14);
    printf("   Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");                      // ¿äÀÏ Ãâ·Â

    int i, day, sd;
    textcolor(15);

    for (i = 0; i < start_day; i++)
    {
        printf("     ");                                             // Ã¹ ÁÖ ½ÃÀÛ ³¯Â¥±îÁö °ø¹é Ãâ·Â
    }

    for (day = 1, sd = start_day; day <= day_num; day++, sd++)      // ÀÏÁÖÀÏ ´ÜÀ§·Î ÀÏÀÚ Ãâ·Â
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






// ============ ¿ùº° ½ÃÀÛ ³¯Â¥ °è»ê ÇÔ¼ö ================

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





// ============ ¿ùº° ¸¶Áö¸· ³¯Â¥ °è»ê ÇÔ¼ö ================


int GetMonth(int yyyy, int mm)
{
    int day_of_month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    day_of_month[2] += LeafYear(yyyy);
    
    return day_of_month[mm];
}





// ============ ¸»ÀÏ °è»ê ÇÔ¼ö ================

int LeafYear(int yyyy)
{
    if (yyyy % 400 == 0)
        return 1;

    if ((yyyy % 100 != 0) && (yyyy % 4 == 0))
        return 1;

    return 0;

}


// ============ ·Î±×ÀÎ ¿Ï·á  ================
PERSON* UserPtr(PERSON user)
{
    // ±¸Á¶Ã¼ user µ¿Àû¸Þ¸ð¸® ÇÒ´ç
    PERSON* user_ptr = malloc(sizeof(PERSON));

    // ±¸Á¶Ã¼ ¸â¹ö °ª ÇÒ´ç
    strcpy(user_ptr->id, user.id);
    strcpy(user_ptr->name, user.name);
    strcpy(user_ptr->pw, user.pw);
    user_ptr->dept = user.dept;
    user_ptr->birthday = user.birthday;

    return user_ptr;
}




// ============ ·Î±×¿Â ÇÔ¼ö ================

void LogOn(EVENT** personalRoot, EVENT** teamRoot, PERSON user, char(*dept_str)[20])
{
    PERSON* user_ptr = UserPtr(user);

    system("cls");
    Calender();
    gotoxy(55, 2);
    // Heap¿¡¼­ µ¥ÀÌÅÍ »ç¿ë
    textcolor(14);
    printf(" È¯¿µÇÕ´Ï´Ù. %s´Ô :) \n", user_ptr->name);
    textcolor(15);
    gotoxy(55, 4);
    printf("¦£¦¡¦¡¦¡¦¡¦¡¦¨¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤ ");
    gotoxy(55, 5);
    printf("¦¢  id ¦¢              ¦¢ ");
    gotoxy(55, 6);
    printf("¦§¦¡¦¡¦¡¦¡¦¡¦«¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦©");
    gotoxy(55, 7);
    printf("¦¢ ºÎ¼­¦¢              ¦¢");
    gotoxy(55, 8);
    printf("¦¦¦¡¦¡¦¡¦¡¦¡¦ª¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥ \n");

    gotoxy(64, 5);
    printf("%3s \n", user_ptr->id);
    gotoxy(64, 7);
    printf("%3s \n", dept_str[user_ptr->dept]);

    PrivateFileLoad(&user);
    PublicFileLoad(&user);



    // menu Ãâ·Â
    Menu(personalRoot, teamRoot, user_ptr);


}











// ============ ÀÏÁ¤ »ý¼º È£Ãâ ÇÔ¼ö ================

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
    printf("                             £ª£ª£ª£ª ÀÏÁ¤ ÀÛ¼º¹ý £ª£ª£ª£ª                         \n");
    printf("              ¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡           \n");
    printf("                                                                                 \n");
    printf("               £ª ÀÏÀÚ´Â 'YYYYMMDD' Çü½ÄÀ¸·Î ÀÛ¼ºÇÏ¼¼¿ä. (ex.20140704)             \n");
    printf("               £ª ½Ã°£Àº 'HHMM' Çü½ÄÀ¸·Î ÀÛ¼ºÇÏ¼¼¿ä.     (ex.  1516  )             \n");
    printf("               £ª ÀÏÁ¤¸íÀº 50±ÛÀÚ ³»·Î ÀÛ¼ºÇÏ¼¼¿ä.                                 \n");
    printf("               £ª ÅÂ±×´Â '0-3 ³» ¼ýÀÚ'·Î ÀÛ¼ºÇÏ¼¼¿ä.                               \n");
    printf("                  # tag  È¸»ç : 0, °³ÀÎ : 1, ±âÅ¸ : 2                            \n");
    printf("               £ªÀÏÁ¤ °øÀ¯ ¿©ºÎ¿¡ ´ëÇØ Y ¶Ç´Â NÀ¸·Î ÀÛ¼ºÇÏ¼¼¿ä.                    \n");
    printf("               £ªÀÏÁ¤ Áß¿äµµ¿¡ ´ëÇØ '0-5 ³» ¼ýÀÚ'·Î ÀÛ¼ºÇÏ¼¼¿ä.                    \n");
    printf("                                                                                 \n");
    printf("              ¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡          \n");

    textcolor(15);
    printf("            ¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤ \n");
    printf("            ¦¢   ½ÃÀÛÀÏ       ¦¢                                        ¦¢ \n");
    printf("            ¦¢   ½ÃÀÛ½Ã°£     ¦¢                                        ¦¢ \n");
    printf("            ¦§¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦© \n");
    printf("            ¦¢   Á¾·áÀÏ       ¦¢                                        ¦¢ \n");
    printf("            ¦¢   Á¾·á½Ã°£     ¦¢                                        ¦¢ \n");
    printf("            ¦§¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦© \n");
    printf("            ¦¢   ÀÏÁ¤¸í       ¦¢                                        ¦¢ \n");
    printf("            ¦§¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦© \n");
    printf("            ¦¢   #Tag (0-3)   ¦¢                                        ¦¢ \n");
    printf("            ¦§¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦© \n");
    printf("            ¦¢   °ø°³ (Y / N) ¦¢                                        ¦¢ \n");
    printf("            ¦§¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦© \n");
    printf("            ¦¢   Áß¿äµµ (0-5) ¦¢                                        ¦¢ \n");
    printf("            ¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥ \n");



    tmp[0] = '\0';			// ÀÓ½Ã¹öÆÛ ÃÊ±âÈ­
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


    tmp[0] = '\0';			// ÀÓ½Ã¹öÆÛ ÃÊ±âÈ­


    while (1)
    {
        do {
            gotoxy(33, 16);
            printf("                   \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
            gets(tmp);

        } while (strlen(tmp) != 4);						// ½Ã°£ ÀÔ·Â 4ÀÚ¸® ³ÑÀ»½Ã ÀçÀÔ·Â ¿äÃ»

        /*
            ¹®ÀÚ¿­·Î ¹ÞÀº 4ÀÚ¸® ½Ã/ºÐ 2ÀÚ¸®¾¿ ²÷¾î,
            intÇüÀ¸·Î ¸í½ÃÀû º¯È¯ ÈÄ À¯È¿ÇÑ ½Ã°£ÀÎÁö ÀçÈ®ÀÎ
            ¿Ã¹Ù¸¥ ÀÔ·Â°ªÀÌ¸é GetTimeT ÇÔ¼ö·Î Àü´ÞÇÏ¿© ½Ã°£¿¡ ÀúÀå
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

        } while (strlen(tmp) != 4);						// ½Ã°£ ÀÔ·Â 4ÀÚ¸® ³ÑÀ»½Ã ÀçÀÔ·Â ¿äÃ»


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

    tmp[0] = '\0';			// ÀÓ½Ã¹öÆÛ ÃÊ±âÈ­
    tmp_i = -1;

    do {

        gotoxy(33, 23);
        printf("                   \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
        scanf("%d%*c", &tmp_i);

    } while (tmp_i < 0 && tmp_i >= sizeof(TAG));

    tag = tmp_i;



    // 5) public ¿©ºÎ 1(Y): °ø¿ë, 0(N): °³ÀÎ

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


    //6) Áß¿äµµ

    tmp_i = 0; // º¯¼ö ÃÊ±âÈ­

    do {

        gotoxy(33, 27);


        printf("                   \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");

        scanf("%d%*c", &tmp_i);

    } while (tmp_i > 5 || tmp_i <0);

    imPortanceLevel = tmp_i;
    

    // ÀÔ·Â Àü´Þ
    CreateNewEvent(personalRoot, user_ptr->id, start, end, title, tag, isPublic, imPortanceLevel);
    if (isPublic)
    {
        CreateNewEvent(teamRoot, user_ptr->id, start, end, title, tag, isPublic, imPortanceLevel);
    }

    // ÀÏÁ¤ ÀúÀå ¿Ï·á ¾Ë¸²

    system("cls");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("            ¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡           \n");
    printf("                                                                               \n");
    printf("                         £ª ÀÏÁ¤ÀÌ »ý¼ºµÇ¾ú½À´Ï´Ù. :-)                           \n");
    printf("                                                                               \n");
    printf("                                                                               \n");
    printf("                    ¸ÞÀÎÀ¸·Î µ¹¾Æ°¡±â ¢·  ¢¹  ÀÏÁ¤ Ãß°¡ »ý¼º                       \n");
    printf("                                                                               \n");
    printf("                                                                               \n");
    printf("            ¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡          \n");
    printf("\n");
    printf("\n");



    char dept_str[sizeof(user_ptr->dept)][20]
        = { "¿øÀåÆÀ", "Ã¤³ÎÆÀ", "ÀÎÇÁ¶óÆÀ", "°æ¿µÁö¿øÆÀ" };  // ÆÀ name Ãâ·ÂÇÏ±â À§ÇÑ ¹è¿­


    char key;
    // ÇÃ·¡±×
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




// ³¯Â¥ °Ë»ç ÇÔ¼ö 

int checkDate(int year, int month, int day) 
{
    // ¿ù °Ë»ç
    if (month <= 0 || 13 <= month)
    {
        return 0;
    }

    // È¦¼ö ´Þ °Ë»ç
    if (month % 2 == 1) 
    {
        // 1, 3, 5, 7¿ùÀº 31ÀÏ±îÁö ÀÖ´Ù.
        if (1 <= month && month <= 7)
        {
            if (day <= 0 || day >= 32)
            {
                return 0;
            }
        }
        // 9, 11¿ùÀº 30ÀÏ±îÁö ÀÖ´Ù.
        else
        {
            if (day <= 0 || day >= 31) return 0;
        }
    }
    // Â¦¼ö ´Þ °Ë»ç
    else
    {
        // 2, 4, 6¿ù °Ë»ç
        if (month <= 6)
        {
            // 2¿ù °Ë»ç
            if (month == 2)
            {
                // 2¿ùÀº À±³â¿¡´Â 29ÀÏ±îÁö ÀÖ´Ù.
                if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
                {
                    if (day <= 0 || day >= 30)
                    {
                        return 0;
                    }
                }
                // 2¿ùÀº Æò³â¿¡´Â 28ÀÏ±îÁö ÀÖ´Ù.
                else if (day <= 0 || day >= 29)
                {
                    return 0;
                }
            }
            // 4, 6¿ù °Ë»ç
            else
            {
                // 4, 6¿ùÀº 30ÀÏ±îÁö ÀÖ´Ù.
                if (day <= 0 || day >= 31)
                {
                    return 0;
                }
            }
        }
        // 8, 10, 12¿ù °Ë»ç
        else {
            // 8, 10, 12¿ùÀº 31ÀÏ±îÁö ÀÖ´Ù.
            if (day <= 0 || day >= 32)
            {
                return 0;
            }
        }
    }
    return 1;
}




