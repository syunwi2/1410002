#include <stdio.h>

#include "schedule.h"
#include "create.h"
#include "delete.h"
#include "screen.h"

void test();

int main() {
	
	MainScreen();
	test();
}

// 테스트 함수
void test() {
	EVENT* myEvent;
	char* id;
	time_t start;
	time_t end;
	char* title;
	TAG tag;
	int isPublic;
	int importanceLevel;

	myEvent = NULL;
	id = "id";

	// 다섯 번째 이벤트
	start = GetTimeT(2023, 1, 28, 12, 00);
	end = GetTimeT(2023, 1, 28, 13, 00);
	title = "title";
	tag = 회사;
	isPublic = 1;
	importanceLevel = 0;
	CreateNewEvent(&myEvent, "id", start, end, title, tag, isPublic, importanceLevel);

	// 두 번째 이벤트
	start = GetTimeT(2023, 1, 28, 12, 00);
	end = GetTimeT(2023, 1, 28, 13, 00);
	title = "title2";
	tag = 회사;
	isPublic = 1;
	importanceLevel = 1;
	CreateNewEvent(&myEvent, "id", start, end, title, tag, isPublic, importanceLevel);

	// 네 번째 이벤트
	start = GetTimeT(2023, 3, 28, 12, 00);
	end = GetTimeT(2023, 3, 28, 13, 00);
	title = "title";
	tag = 회사;
	isPublic = 1;
	importanceLevel = 2;
	CreateNewEvent(&myEvent, "id", start, end, title, tag, isPublic, importanceLevel);

	// 첫 이벤트
	start = GetTimeT(2023, 3, 30, 12, 00);
	end = GetTimeT(2023, 3, 30, 13, 00);
	title = "title";
	tag = 회사;
	isPublic = 1;
	importanceLevel = 3;
	CreateNewEvent(&myEvent, "id", start, end, title, tag, isPublic, importanceLevel);

	// 세 번째 이벤트
	start = GetTimeT(2023, 4, 28, 12, 00);
	end = GetTimeT(2023, 4, 28, 13, 00);
	title = "title";
	tag = 회사;
	isPublic = 1;
	importanceLevel = 4;
	CreateNewEvent(&myEvent, "id", start, end, title, tag, isPublic, importanceLevel);

	// 여섯 번째 이벤트
	start = GetTimeT(2023, 5, 28, 12, 00);
	end = GetTimeT(2023, 5, 28, 13, 00);
	title = "title";
	tag = 회사;
	isPublic = 1;
	importanceLevel = 5;
	CreateNewEvent(&myEvent, "id", start, end, title, tag, isPublic, importanceLevel);

	DeleteEvent(&myEvent, myEvent->prev);
}