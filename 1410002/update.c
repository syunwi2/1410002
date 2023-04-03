#include "update.h"

void UpdateEvent(EVENT** root)
{
	int chk;
	int i;
	long long int tmp;
	EVENT* node = root;
	printf("일정을 수정 할 수 있습니다. \n");
	printf("어떤 일정을 수정하시겠습니까? \n");
	//일정 전체 출력
	do
	{
		printf("일정 다시 확인하기 y or n");
		scanf_s("%d", &chk);
	} while (chk != 1 && chk != 2);
	if (chk == 1)
	{
		PersonalReadEvent(root);
	}

	//수정 노드 선택

	printf("choice");
	scanf_s("%d", &tmp);
	while (node != NULL && tmp != node->start) {
		if ( node->start < tmp) {
			node = node->prev;
		}
		else {
			node = node->next;
		}
	}

	//개인파일에서 수정
//	DeleteEvent(root, ptr);
//	CreateNewEvent(root, id, start, end, title, tag, isPublic, imPortanceLevel);
//	//팀파일에서 수정
//	DeleteEvent(root, ptr);
//	CreateNewEvent(root, id, start, end, title, tag, isPublic, imPortanceLevel);
}