#include <stdio.h>
#include "user.h"
#include "schedule.h"
#include "create.h"
#include "delete.h"

void test();

int main() {
	login();
	test();
}

// �׽�Ʈ �Լ�
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

	// ù �̺�Ʈ
	start = GetTimeT(2023, 3, 30, 12, 00);
	end = GetTimeT(2023, 3, 30, 13, 00);
	title = "title";
	tag = ȸ��;
	isPublic = 1;
	importanceLevel = 3;
	CreateEvent(&myEvent, "id", start, end, title, tag, isPublic, importanceLevel);

	// �� ��° �̺�Ʈ
	start = GetTimeT(2023, 2, 28, 12, 00);
	end = GetTimeT(2023, 2, 28, 13, 00);
	title = "title";
	tag = ȸ��;
	isPublic = 1;
	importanceLevel = 1;
	CreateEvent(&myEvent, "id", start, end, title, tag, isPublic, importanceLevel);

	// �� ��° �̺�Ʈ
	start = GetTimeT(2023, 4, 28, 12, 00);
	end = GetTimeT(2023, 4, 28, 13, 00);
	title = "title";
	tag = ȸ��;
	isPublic = 1;
	importanceLevel = 4;
	CreateEvent(&myEvent, "id", start, end, title, tag, isPublic, importanceLevel);

	// �� ��° �̺�Ʈ
	start = GetTimeT(2023, 3, 28, 12, 00);
	end = GetTimeT(2023, 3, 28, 13, 00);
	title = "title";
	tag = ȸ��;
	isPublic = 1;
	importanceLevel = 2;
	CreateEvent(&myEvent, "id", start, end, title, tag, isPublic, importanceLevel);

	// �ټ� ��° �̺�Ʈ
	start = GetTimeT(2023, 1, 28, 12, 00);
	end = GetTimeT(2023, 1, 28, 13, 00);
	title = "title";
	tag = ȸ��;
	isPublic = 1;
	importanceLevel = 0;
	CreateEvent(&myEvent, "id", start, end, title, tag, isPublic, importanceLevel);

	// ���� ��° �̺�Ʈ
	start = GetTimeT(2023, 5, 28, 12, 00);
	end = GetTimeT(2023, 5, 28, 13, 00);
	title = "title";
	tag = ȸ��;
	isPublic = 1;
	importanceLevel = 5;
	CreateEvent(&myEvent, "id", start, end, title, tag, isPublic, importanceLevel);

	DeleteEvent(&myEvent, myEvent->prev);
}