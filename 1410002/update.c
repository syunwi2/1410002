#include "update.h"

long long int TimeUpdate()
{
	int i;
	long long int tmpt;

	//printf("choice");
	char tmp[100];
	tmp[0] = '\0';
	char year_ch[10] = { 0 } , mon_ch[10] = { 0 }, day_ch[10] = { 0 }, hour_ch[10] = { 0 }, min_ch[10] = { 0 };
	int year, mon, day, hour, min;

	while (1)
	{
		do {
			printf(" >>> 날짜를 알려주세요. ex) 2309261500 \n");
			printf("     YYMMDDHHMM : \n");
			gets(tmp);

		} while (strlen(tmp) != 10);

		for (i = 0; i < 10; i++)
		{
			if (i < 2)
			{
				year_ch[i] = tmp[i];
			}
			else if (2 <= i && i < 4)
			{
				mon_ch[i - 2] = tmp[i];
			}
			else if (4 <= i && i < 6)
			{
				day_ch[i - 4] = tmp[i];
			}
			else if (6 <= i && i < 8)
			{
				hour_ch[i - 6] = tmp[i];
			}
			else
			{
				min_ch[i - 8] = tmp[i];
			}
		}
		year = atoi(year_ch) + 2000;
		mon = atoi(mon_ch);
		day = atoi(day_ch);
		hour = atoi(hour_ch);
		min = atoi(min_ch);

		if (mon >= 1 && mon <= 12 && day >= 1 && day <= 31
			&& hour >= 0 && hour <= 24 && min >= 0 && min <= 60)
			break;
	}

	tmpt = GetTimeT(year, mon, day, hour, min);
	return tmpt;
}
 
void UpdateEvent(EVENT** root)
{
	int chk, findnum, chk_con;
	EVENT* node, buffer;
	char tmp[100], findid[7] = { 0 };
	node = *root;
	printf("일정을 수정 할 수 있습니다. \n");
	printf("어떤 일정을 수정하시겠습니까? \n");
	//일정 전체 출력
	do
	{
		printf("일정 다시 확인하기 (다시조회: 1, 수정하기: 2)\n");
		scanf_s("%d%*c", &chk);
	} while (chk != 1 && chk != 2);

	if (chk == 1)
	{
		PersonalReadEvent(root);
	}

	//수정 노드 선택
	printf("수정할 노드 번호 선택 : \n");
	scanf_s("%d%*c", &findnum);
	sprintf(findid, "%.6d", findnum);

	EVENT* ptr;
	while (node != NULL) 
	{
		if ( strcmp(node->nodeID, findid) < 0 )
		{
			node = node->next;
		}
		else if ( strcmp(node->nodeID, findid) > 0 )
		{
			node = node->prev;
		}
		else
		{
			ptr = node;
			break;
		}
	}

	strcpy(buffer.nodeID, ptr->nodeID);
	strcpy(buffer.ownerID, ptr->ownerID);
	buffer.start = ptr->start;
	buffer.end = ptr->end;
	strcpy(buffer.title, ptr->title);
	buffer.tag = ptr->tag;
	buffer.isPublic = ptr->isPublic;
	buffer.importanceLevel = ptr->importanceLevel;
	
	//기존 일정 정보 삭제
	DeleteEvent(root, ptr);
	//ptr = NULL;
	// 버퍼 초기화
	tmp[0] = '\0';
	
	while (1) {
		do
		{
			// 새 일정 정보 생성
			printf("어떤 정보를 수정 하겠습니까? \n");
			printf("1. 시작일 2. 종료일 3. 제목 4. 태그 5. ispublic 6. 중요도 7. 수정된 정보 저장 8. 수정 완료\n");
			scanf_s("%d%*c", &chk_con);
		} while (chk_con != 1 && chk_con != 2 && chk_con != 3 && chk_con != 4 &&
			chk_con != 5 && chk_con != 6 && chk_con != 7 && chk_con != 8);
		// 시작일 수정
		if (chk_con == 1)
		{

			buffer.start = TimeUpdate();
		}
		// 종료일 수정
		else if (chk_con == 2)
		{

			buffer.end = TimeUpdate();
		}
		// 제목 수정
		else if (chk_con == 3)
		{
			do
			{
				printf("일정 내용 : \n");
				printf("                   \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
				gets(tmp);

			} while (strlen(tmp) >= sizeof(tmp));
			strcpy(buffer.title, tmp);
		}
		// 태그 수정
		else if (chk_con == 4)
		{
			do
			{
				printf("\n # tag  회사 : 0, 개인 : 1, 기타 : 2 ");
				printf("\n Tag : ");
				printf("                   \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
				scanf("%d%*c", &buffer.tag);

			} while (buffer.tag < 0 && buffer.tag >= sizeof(TAG));

		}
		// 공개 여부 수정
		else if (chk_con == 5)
		{
			char ch;
			do {
				printf("\n 공개 여부(Y / N) : ");
				printf("                   \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");

				ch = getchar();

			} while (ch != 'y' && ch != 'Y' && ch != 'n' && ch != 'N');

			if (ch == 'y' || ch == 'Y')
			{
				buffer.isPublic = 1;
			}
			else
			{
				buffer.isPublic = 0;
			}
		}
		// 중요도 수정
		else if (chk_con == 6)
		{
			do
			{
				printf("\n 중요도 (0-5) : ");
				printf("                   \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");

				scanf_s("%d%*c", &buffer.importanceLevel);

			} while (buffer.importanceLevel > 5 || buffer.importanceLevel < 0);
		}
		// 수정된 정보 업데이트
		else if (chk_con == 7)
		{
			CreateNewEvent(root, buffer.ownerID, buffer.start, buffer.end, buffer.title, buffer.tag, buffer.isPublic, buffer.importanceLevel);
			printf("수정이 완료되었습니다.\n");
		}
		else if (chk_con == 8)
		{
			break;
		}
	}
	
	//팀파일에서 수정
	//DeleteEvent(root, ptr);
	//CreateNewEvent(root, id, start, end, title, tag, isPublic, imPortanceLevel);
}