#include "update.h"

long long int TimeUpdate()
{
	int i;
	long long int tmpt;

	printf("choice");
	char tmp[100];
	tmp[0] = '\0';
	char year_ch[10], mon_ch[10], day_ch[10], hour_ch[10], min_ch[10];
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
	return tmpt;
}
 
void UpdateEvent(EVENT** root)
{
	int chk, findnum;
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
	scanf_s("%d", &findnum);
	//수정 노드 선택

	EVENT* ptr = "";
	while (node != NULL &&  findnum!= node->nodeID) 
	{
		if ( node->start > findnum)
		{
			node = node->prev;
		}
		else if (node->start < findnum)
		{
			node = node->next;
		}
		else
		{
			ptr = node;
		}
	}

	strcpy(buffer.nodeID, ptr->nodeID);
	buffer.start = ptr->start;
	buffer.end = ptr->end;
	strcpy(buffer.title, ptr->title);
	buffer.tag = ptr->tag;
	buffer.isPublic = ptr->isPublic;
	buffer.importanceLevel = ptr->importanceLevel;
	
	//기존 일정 정보 삭제
	DeleteEvent(root, ptr);

	// 버퍼 초기화
	char tmp[100];
	tmp[0] = '\0';
	int chk_con;
	do
	{
	// 새 일정 정보 생성

	printf("어떤 정보를 수정 하겠습니까? \n");
	printf("1. 시작일 2. 종료일 3. 제목 4. 태그 5. ispublic 6. 중요도 \n");
	scanf_s("%d", &chk_con);
	} while (chk_con != 1 && chk_con != 2 && chk_con != 3 && chk_con != 4 &&
		chk_con != 5 && chk_con != 6);
	long long int tmpt_res;
	if (chk_con == 1)
	{
		tmpt_res =TimeUpdate();
		CreateNewEvent(root, buffer.nodeID, tmpt_res, buffer.end,
			buffer.title, buffer.tag, buffer.isPublic, buffer.importanceLevel);
	}
	else if (chk_con == 2)
	{
		tmpt_res = TimeUpdate();
		CreateNewEvent(root, buffer.nodeID, buffer.start, tmpt_res,
			buffer.title, buffer.tag, buffer.isPublic, buffer.importanceLevel);
	}
	else if (chk_con == 3)
	{
		do {
			printf("\n 일정명 : ");
			printf("                   \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
			gets(tmp);

		} while (strlen(tmp) >= 100);
		//strcpy(title, tmp);
		CreateNewEvent(root, buffer.nodeID, buffer.start, buffer.end,
			tmp, buffer.tag, buffer.isPublic, buffer.importanceLevel);
	}
	else if (chk_con == 4)
	{
		int tmp_i;
		tmp[0] = '\0';			// 임시버퍼 초기화
		tmp_i = -1;

		do {

			printf("\n # tag  회사 : 0, 개인 : 1, 기타 : 2 ");
			printf("\n Tag : ");
			printf("                   \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
			scanf("%d%*c", &tmp_i);

		} while (tmp_i < 0 && tmp_i >= sizeof(TAG));

		CreateNewEvent(root, buffer.nodeID, buffer.start, buffer.end,
			buffer.title, tmp_i, buffer.isPublic, buffer.importanceLevel);
	}
	else if (chk_con == 5)
	{
		char ch;
		int isPublic;
		do {
			printf("\n 공개 여부(Y / N) : ");
			printf("                   \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");

			ch = getchar();

		} while (ch != 'y' && ch != 'Y' && ch != 'n' && ch != 'N');

		if (ch == 'y' || ch == 'Y')
		{
			isPublic = 1;
		}
		else
		{
			isPublic = 0;
		}

		CreateNewEvent(root, buffer.nodeID, buffer.start, buffer.end,
			buffer.title, buffer.tag, isPublic, buffer.importanceLevel);
	}
	else if (chk_con == 6)
	{
		int tmp_i = 0; // 변수 초기화

		do {

			printf("\n 중요도 (0-5) : ");
			printf("                   \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");

			scanf_s("%d%*c", &tmp_i);

		} while (tmp_i > 5 || tmp_i < 0);

		CreateNewEvent(root, buffer.nodeID, buffer.start, buffer.end,
			buffer.title, buffer.tag, buffer.isPublic, tmp_i);
	}
	
	
	//팀파일에서 수정
	//DeleteEvent(root, ptr);
	//CreateNewEvent(root, id, start, end, title, tag, isPublic, imPortanceLevel);
}