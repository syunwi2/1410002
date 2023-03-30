#include <time.h>

typedef enum TAG { ȸ��, ����, ��Ÿ } TAG;

typedef struct EVENT {
	char ownerID[20];
	time_t start;
	time_t end;
	char title[100];
	TAG tag;
	int isPublic;
	int importanceLevel;
	struct EVENT* contPrev;
	struct EVENT* contNext;
	struct EVENT* prev;
	struct EVENT* next;
} EVENT;