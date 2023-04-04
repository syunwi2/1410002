// 작성자 : 정민경

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifndef __SCHEDULE__H__
#define __SCHEDULE__H__
typedef enum TAG { 회사, 개인, 기타 } TAG;

typedef struct EVENT {
	char nodeID[20];
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
} EVENT;
#endif

time_t GetTimeT(int year, int mon, int day, int hour, int min);
void BalanceTree(EVENT** root, EVENT* node);
int GetBalanceFactor(EVENT* node);
int GetHeight(EVENT* node);
void LeftRotate(EVENT** root, EVENT* node);
void RightRotate(EVENT** root, EVENT* node);
