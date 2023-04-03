#include "update.h"

void UpdateEvent(EVENT** root, PERSON* user)
{
	int chk;
	int i;
	long long int tmpt;
	EVENT* node, buffer;
	node = *root;
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
	char tmp[100];
	tmp[0] = '\0';			
	char year_ch[10],mon_ch[10], day_ch[10], hour_ch[10], min_ch[10];
	int year, mon, day, hour, min;

	while (1)
	{
		do {
			printf(" >>> 날짜를 알려주세요. ex) 2309261500 \n");
			printf("     YYMMDDHHMM : ");
			gets(tmp);

		} while (strlen(tmp) != 10);

		/*
			문자열로 받은 6자리 월/일 2자리씩 끊어,
			int형으로 명시적 변환 후 유효한 날짜인지 재확인
			올바른 입력값이면 GetTimeT 함수로 전달하여 생일에 저장
		*/

		for (i = 0; i < 10; i++)
		{
			if (i < 2)
			{
				year_ch[i] = tmp[i];
			}
			else if (2 <= i < 4)
			{
				mon_ch[i - 2] = tmp[i];
			}
			else if (4 <= i < 6)
			{
				day_ch[i - 4] = tmp[i];
			}
			else if (6 <= i < 8)
			{
				hour_ch[i - 6] = tmp[i];
			}
			else 
			{
				min_ch[i - 8] = tmp[i];
			}
		}
		year = atoi(year_ch);
		mon = atoi(mon_ch);
		day = atoi(day_ch);
		hour = atoi(hour_ch);
		min = atoi(min_ch);

		if (mon >= 1 && mon <= 12 && day >= 1 && day <= 31
			&& hour >= 0 && hour <= 24 && min >= 0 && min <= 60)
			break;


	}	// while(1) end.

	tmpt = GetTimeT(year, mon, day, hour, min);
	EVENT* ptr = "";
	while (node != NULL && tmpt != node->start) 
	{
		if ( node->start > tmpt) 
		{
			node = node->prev;
		}
		else if (node->start < tmpt)
		{
			node = node->next;
		}
		else
		{
			ptr = node;
		}
	}

	strcpy(buffer.ownerID, ptr->ownerID);
	buffer.start = ptr->start;
	buffer.end = ptr->end;
	strcpy(buffer.title, ptr->title);
	buffer.tag = ptr->tag;
	buffer.isPublic = ptr->isPublic;
	buffer.importanceLevel = ptr->importanceLevel;
	
	//기존 일정 정보 삭제
	DeleteEvent(root, ptr);

	// 버퍼 초기화
	tmp[0] = '\0';

	prtinf("");

	// 새 일정 정보 생성
	CreateNewEvent(root, user->id, buffer.start, buffer.end, buffer.title, buffer.tag, buffer.isPublic, buffer.importanceLevel);
	
	//팀파일에서 수정
	//DeleteEvent(root, ptr);
	//CreateNewEvent(root, id, start, end, title, tag, isPublic, imPortanceLevel);
}