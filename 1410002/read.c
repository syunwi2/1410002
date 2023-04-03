#include "read.h"
#include <stdbool.h>

//void TimePrint(EVENT* node, int choice)
//{
//    time_t now = time(NULL);
//    struct tm* today = localtime(&now);
//
//    if (node->start == today->tm_year && t == 1)
//    {
//        PrintEvent(node, choice);
//    }
//    else if (node->start == today->tm_year && t == 1)
//    {
//        PrintEvent(node, choice);
//    }
//    else if (node->start == today->tm_year && t == 1)
//    {
//        PrintEvent(node, choice);
//    }
//}
long long int TimeGet()
{
    long long tt;
    time_t now = time(NULL);
    long long today = (long long)now;
    return today;
}

void ChkChoice(EVENT* node, int choice)
{
    struct tm* tmpStart, *tmpEnd;

    tmpStart = localtime(&(node->start));
    tmpEnd = localtime(&(node->start));

    if (choice == 1 )
    {

        printf("nodeID: %s 시작일: %d %d %d %d %d 종료일: %d %d %d %d %d 일정: %s 공개여부: %s 중요도: %d\n", node->nodeID,
                                                  tmpStart->tm_year + 1900, tmpStart->tm_mon + 1, tmpStart->tm_mday, tmpStart->tm_hour, tmpStart->tm_min,
                                                  tmpEnd->tm_year + 1900, tmpEnd->tm_mon + 1, tmpEnd->tm_mday, tmpEnd->tm_hour, tmpEnd->tm_min,
                                                  node->title, (node->isPublic == 1)? "공개": "비공개", node->importanceLevel);
    }
    else if (choice == 2 && node->tag == 0)
    {
        printf("nodeID: %s 시작일: %d %d %d %d %d 종료일: %d %d %d %d %d 일정: %s 공개여부: %s 중요도: %d\n", node->nodeID,
                                                tmpStart->tm_year + 1900, tmpStart->tm_mon + 1, tmpStart->tm_mday, tmpStart->tm_hour, tmpStart->tm_min,
                                                tmpEnd->tm_year + 1900, tmpEnd->tm_mon + 1, tmpEnd->tm_mday, tmpEnd->tm_hour, tmpEnd->tm_min,
                                                node->title, (node->isPublic == 1) ? "공개" : "비공개", node->importanceLevel);
    }
    else if (choice == 3 && node->tag == 1)
    {
        printf("nodeID: %s 시작일: %d %d %d %d %d 종료일: %d %d %d %d %d 일정: %s 공개여부: %s 중요도: %d\n", node->nodeID,
                                                tmpStart->tm_year + 1900, tmpStart->tm_mon + 1, tmpStart->tm_mday, tmpStart->tm_hour, tmpStart->tm_min,
                                                tmpEnd->tm_year + 1900, tmpEnd->tm_mon + 1, tmpEnd->tm_mday, tmpEnd->tm_hour, tmpEnd->tm_min,
                                                node->title, (node->isPublic == 1) ? "공개" : "비공개", node->importanceLevel);
    }
    else if (choice == 4 && node->tag == 2)
    {
        printf("nodeID: %s 시작일: %d %d %d %d %d 종료일: %d %d %d %d %d 일정: %s 공개여부: %s 중요도: %d\n", node->nodeID,
                                                tmpStart->tm_year + 1900, tmpStart->tm_mon + 1, tmpStart->tm_mday, tmpStart->tm_hour, tmpStart->tm_min,
                                                tmpEnd->tm_year + 1900, tmpEnd->tm_mon + 1, tmpEnd->tm_mday, tmpEnd->tm_hour, tmpEnd->tm_min,
                                                node->title, (node->isPublic == 1) ? "공개" : "비공개", node->importanceLevel);
    }
}

void PrintEvent(EVENT* node, int choice, int t) 
{
    long long int TimeSap;
    TimeSap = TimeGet();
    if (TimeSap < node->start < TimeSap+86400 && t == 1)
    {
        ChkChoice(node, choice);
    }
    else if (TimeSap < node->start < TimeSap + 86400*7 && t == 2)
    {
        ChkChoice(node, choice);
    }
    else if (t ==3)
    {
        ChkChoice(node, choice);
    }
}

void InorderNode(EVENT* node, int choice, int t) 
{
    if (node == NULL)
    {
        return;
    }
    InorderNode(node->prev, choice, t);
    PrintEvent(node, choice, t);
    InorderNode(node->next, choice, t);
}

//void TimeCheck()
//{
//    int t;
//    do
//    {
//        printf("일정 시간 확인 ? ");
//        printf("하루 : 1, 일주일 : 2 전체 : 3");
//        scanf_s("%d", &t);
//
//    } while (t != 1 && t != 2 && t != 3);
//}

void PersonalReadEvent(EVENT** root) 
{
    int t, choice;
    EVENT *node;
    node = *root;
    do
    {
        printf("일정 시간 확인 ? ");
        printf("하루 : 1, 일주일 : 2 전체 : 3");
        scanf_s("%d", &t);
        
    } while (t != 1 && t != 2 && t != 3);

    do 
    {
        printf("개인 일정을 출력하세요.\n");
        printf("전체 일정 출력 : 1\n");
        printf("개인 일정 출력 : 2\n");
        printf("회사 일정 출력 : 3\n");
        printf("기타 일정 출력 : 4\n");
        scanf_s("%d", &choice);
    } while (choice != 1 && choice != 2 && choice != 3 && choice != 4);

    if (choice == 1)
    {
        printf("%s님의 일정\n", node->ownerID);
        InorderNode(node, choice, t);
    }
    else if (choice == 2)
    {
        printf("%s님의 회사일정", node->ownerID);
        InorderNode(node, choice, t);
    }
    else if (choice == 3)
    {
        printf("%s님의 개인일정", node->ownerID);
        InorderNode(node, choice, t);
    }
    else if (choice == 4)
    {
        printf("%s님의 기타일정", node->ownerID);
        InorderNode(node, choice, t);
    }
}

void PrintEventCom(EVENT* node, int deptch)
{
    printf("%s %lld %lld %s %d %d\n", node->nodeID, node->start, node->end, node->title, node->isPublic, node->importanceLevel);
}

void InorderNodeCom(EVENT* node, int deptch) 
{
    if (node == NULL)
    {
        printf("일정이 존재 하지 않습니다.");
        return;
    }
    InorderNodeCom(node->prev, deptch);
    PrintEventCom(node, deptch);
    InorderNodeCom(node->next, deptch);
}


void PublicReadEvent(EVENT** root)
{
    static int deptch = 0;
    EVENT* node;
    node = *root;
    //TimeCheck();
    do {
        printf("팀 일정을 출력하세요.\n");
        printf("채널 팀 일정 출력 : 1\n");
        printf("원장 팀 일정 출력 : 2\n");
        printf("경영지원 팀 일정 출력 : 3\n");
        printf("본부 팀 일정 출력 : 4\n");
        scanf_s("%d", &deptch);
    } while (deptch != 1 && deptch != 2 && deptch != 3 && deptch != 4);

    if (deptch == 1)
    {
        printf("채널팀의 일정");
        InorderNodeCom(node, deptch);
    }
    else if (deptch == 2)
    {
        printf("원장팀의 일정");
        InorderNodeCom(node, deptch);
    }
    else if (deptch == 3)
    {
        printf("경영지원팀의 일정");
        InorderNodeCom(node, deptch);
    }
    else if (deptch == 4)
    {
        printf("본부팀의 일정");
        InorderNodeCom(node, deptch);
    }


}

//void ReadEvent(EVENT* root)
//{
//	EVENT* ptr;
//	ptr = root;
//	
//	int tmp;
//	
//	do {
//
//	printf("개인 일정을 출력하세요. \n");
//	printf("전체 일정 출력 : 1 \n");
//	printf("개인 일정 출력 : 2 \n");
//	printf("회사 일정 출력 : 3 \n");
//	printf("기타 일정 출력 : 4 \n");
//	scanf_s("%d", &tmp);
//	} while (tmp != 1 && tmp != 2 && tmp != 3 && tmp != 4);
//
//	if (tmp==1)
//	{
//		while (ptr)
//		{
//			printf("%s %d %d %s %s %d %d", ptr->ownerID, ptr->start, ptr->end,
//				ptr->tag, ptr->isPublic, ptr->importanceLevel);
//			ptr = ptr->next;
//		}
//	}
//	else if (tmp == 1)
//	{
//		while (ptr)
//		{
//			if (ptr->tag == 1)
//			{
//				printf("%s %d %d %s %s %d %d", ptr->ownerID, ptr->start, ptr->end,
//					ptr->tag, ptr->isPublic, ptr->importanceLevel);
//			}
//			ptr = ptr->next;
//		}
//	}
//	else if (tmp == 2)
//	{
//		while (ptr)
//		{
//			if (ptr->tag == 0)
//			{
//				printf("%s %d %d %s %s %d %d", ptr->ownerID, ptr->start, ptr->end,
//					ptr->tag, ptr->isPublic, ptr->importanceLevel);
//			}
//			ptr = ptr->next;
//		}
//	}
//	else if (tmp == 3)
//	{
//		while (ptr)
//		{
//			if (ptr->tag == 2)
//			{
//				printf("%s %d %d %s %s %d %d", ptr->ownerID, ptr->start, ptr->end,
//					ptr->tag, ptr->isPublic, ptr->importanceLevel);
//			}
//			ptr = ptr->next;
//		}
//	}
//}