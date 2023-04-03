#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>		// gotoxy 헤더파일
#include <conio.h>

#include "schedule.h"
#include "signin.h"
#include "signup.h"
#include "create.h"


#ifndef __USER_H__
#define __USER_H__
typedef enum DEPT { 원장팀, 채널팀, 인프라팀, 경영지원팀 } DEPT;

typedef struct person {
	char id[20];
	char name[20];
	char pw[20];
	DEPT dept;
	time_t birthday;
} PERSON;
#endif

void MainScreen(void);							// 프로그램 시작화면
//void DrawMap(void);							// 화면 테두리 그림 
void gotoxy(int x, int y);						// 커서 옮기는 라이브러리함수

void Calender();								// 달력 호출 함수
int GetDay(int yyyy, int mm);					// 날짜 일수
int GetMonth(int yyyy, int mm);					// 날짜 월
int LeafYear(int yyyy);							// 말일 계산
void ScreenCal(int start_day, int day_num);		// 달력 출력
int checkDate(int year, int month, int day);	// 날짜 검사 함수