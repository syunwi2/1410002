#include <time.h>

typedef enum DEPT {원장팀, 채널팀, 인프라팀, 경영지원팀} DEPT;

typedef struct person {
	char id[20];
	char name[20];
	char pw[20];
	DEPT dept;
	time_t birthday;
} PERSON;

void login();