#include <time.h>

typedef enum DEPT {������, ä����, ��������, �濵������} DEPT;

struct person {
	char id[20];
	char name[20];
	char pw[20];
	DEPT dept;
	time_t birthday;
};