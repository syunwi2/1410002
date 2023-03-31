#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifndef __SCHEDULE__H__
#define __SCHEDULE__H__
typedef enum TAG { 회사, 개인, 기타 } TAG;
typedef enum COLOR { black, red } COLOR;

typedef struct EVENT {
	char ownerID[20];
	time_t start;
	time_t end;
	char title[100];
	TAG tag;
	int isPublic;
	int importanceLevel;
	struct EVENT* parent;
	struct EVENT* prev;
	struct EVENT* next;
	COLOR color;
} EVENT;
#endif

time_t GetTimeT(int year, int mon, int day, int hour, int min);
void BalanceTree(EVENT** root, EVENT* newNode);