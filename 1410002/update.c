#include "update.h"

void UpdateEvent(EVENT* root, EVENT* node)
{
	EVENT* ptr;
	printf("일정을 수정 할 수 있습니다. \n");
	printf("어떤 일정을 수정하시겠습니까? \n");
	//일정 전체 출력
	PersonalReadEvent(root);

	//수정 노드 선택



	//개인파일에서 수정
//	CreateNewEvent(root, id, start, end, title, tag, isPublic, imPortanceLevel);
//	DeleteEvent(root, node);
//	//팀파일에서 수정
//	CreateNewEvent(root, id, start, end, title, tag, isPublic, imPortanceLevel);
//	DeleteEvent(root, node);
}