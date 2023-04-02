#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>		// gotoxy �������
#include <conio.h>

#include "schedule.h"
#include "signin.h"
#include "signup.h"

#ifndef __USER_H__
#define __USER_H__
typedef enum DEPT { ������, ä����, ��������, �濵������ } DEPT;

typedef struct person {
	char id[20];
	char name[20];
	char pw[20];
	DEPT dept;
	time_t birthday;
} PERSON;
#endif

void MainScreen(void); //���� ����ȭ�� 
void draw_map(void); // ������ �׵θ��� �׸� 
void reset(void); //������ �ʱ�ȭ
void gotoxy(int x, int y);

int get_day(int yyyy, int mm);
int get_month(int yyyy, int mm);
int is_leaf_year(int yyyy);
void screen_cal(int start_day, int day_num);


void Calender();