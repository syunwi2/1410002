#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>		// gotoxy �������
#include <conio.h>

#include "screen.h"
#include "schedule.h"

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

void Login();
void SignUp();
void SignIn();