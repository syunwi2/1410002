// �ۼ��� : ���ΰ�

#include <time.h>

#ifndef __PERSON_H__
#define __PERSON_H__
typedef enum DEPT { ������, ä����, ��������, �濵������ } DEPT;

typedef struct person {
	char id[20];
	char name[20];
	char pw[20];
	DEPT dept;
	time_t birthday;
} PERSON;
#endif