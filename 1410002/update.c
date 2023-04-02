#include "update.h"

void UpdateEvent(EVENT** root, EVENT* node)
{
	int chk;
	EVENT* ptr = node;
	printf("일정을 수정 할 수 있습니다. \n");
	printf("어떤 일정을 수정하시겠습니까? \n");
	//일정 전체 출력
<<<<<<< HEAD
	do
	{
		printf("일정 다시 확인하기 y or n");
		scanf_s("%d", &chk);
	} while (chk != 1 && chk != 2);
	if (chk == 1)
	{
		PersonalReadEvent(root);
	}
	
=======
	PersonalReadEvent(root);

>>>>>>> 8447fa898f2b65bc4dfa3b8042e9252488471ba8
	//수정 노드 선택



	//개인파일에서 수정
//	CreateNewEvent(root, id, start, end, title, tag, isPublic, imPortanceLevel);
//	DeleteEvent(root, node);
//	//팀파일에서 수정
//	CreateNewEvent(root, id, start, end, title, tag, isPublic, imPortanceLevel);
//	DeleteEvent(root, node);
}