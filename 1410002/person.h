// 작성자 : 정민경

#include <time.h>

#ifndef __PERSON_H__
#define __PERSON_H__
typedef enum DEPT { 원장팀, 채널팀, 인프라팀, 경영지원팀 } DEPT;

typedef struct person {
	char id[20];
	char name[20];
	char pw[20];
	DEPT dept;
	time_t birthday;
} PERSON;
#endif