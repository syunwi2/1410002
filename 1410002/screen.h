#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>		// gotoxy 헤더파일
#include <conio.h>
#include "person.h"
#include "schedule.h"
#include "fileio.h"
#include "signin.h"
#include "signup.h"
#include "create.h"


void MainScreen(void);							// 프로그램 시작화면
void gotoxy(int x, int y);						// 커서 옮기는 라이브러리함수

void Calender();								// 달력 호출 함수
int GetDay(int yyyy, int mm);					// 날짜 일수
int GetMonth(int yyyy, int mm);					// 날짜 월
int LeafYear(int yyyy);							// 말일 계산
void ScreenCal(int start_day, int day_num);		// 달력 출력
void LogOn(EVENT** personalRoot, EVENT** teamRoot, PERSON user, char(*dept_str)[20]);	// 로그온 함수
void CreateEventScreen(EVENT** personalRoot, EVENT** teamRoot, PERSON* user_ptr);
int checkDate(int year, int month, int day);	// 날짜 검사 함수