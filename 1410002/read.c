#include "read.h"
#include <stdbool.h>

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
    if (TimeSap < node->start && node->start < TimeSap+86400 && t == 1)
    {
        ChkChoice(node, choice);
    }
    else if (TimeSap < node->start && node->start < TimeSap + 86400*7 && t == 2)
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

void PersonalReadEvent(EVENT** root) 
{
    int t, choice, slt;
    EVENT* node, * ptr;
    while(1)
    {
        do 
        {
            printf("%s님의 개인 일정을 출력하세요.\n", (*root)->ownerID);
            printf("전체 일정 출력 : 1\n");
            printf("개인 일정 출력 : 2\n");
            printf("회사 일정 출력 : 3\n");
            printf("기타 일정 출력 : 4\n");
            printf("조회 종료 : 5\n");
            scanf_s("%d%*c", &choice);
        } while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5);

        if (choice == 5)
        {
            break;
        }

        do
        {
            printf("조회 할 기간을 선택해 주세요. \n");
            printf("하루 : 1, 일주일 : 2 전체 : 3 \n");
            scanf_s("%d%*c", &t);
        
        } while (t != 1 && t != 2 && t != 3);

        if (choice == 1)
        {
            printf("%s님의 일정\n", (*root)->ownerID);
            InorderNode((*root), choice, t);
        }
        else if (choice == 2)
        {
            printf("%s님의 개인일정\n", (*root)->ownerID);
            InorderNode((*root), choice, t);
        }
        else if (choice == 3)
        {
            printf("%s님의 회사일정\n", (*root)->ownerID);
            InorderNode(node, choice, t);
        }
        else if (choice == 4)
        {
            printf("%s님의 기타일정\n", (*root)->ownerID);
            InorderNode(node, choice, t);
        }
        do 
        {   
            printf("일정을 수정하시거나 삭제하겠습니까? \n");
            printf("수정 : 1, 삭제 : 2 다시조회 : 3");
            scanf("%d", &slt);
        } while (slt != 1 && slt != 2 && slt != 3);
        if (slt == 1)
        {
            UpdateEvent(root);
        }
        else if (slt == 2)
        {
            int findnum;
            char findid[7] = { 0 };
            printf("삭제할 노드 번호 선택 : \n");
            scanf_s("%d%*c", &findnum);
            sprintf(findid, "%.6d", findnum);

            node = *root, ptr = NULL;
            while (node != NULL)
            {
                if (strcmp(node->nodeID, findid) < 0)
                {
                    node = node->next;
                }
                else if (strcmp(node->nodeID, findid) > 0)
                {
                    node = node->prev;
                }
                else
                {
                    ptr = node;
                    break;
                }
            }
            DeleteEvent(root, ptr);
        }
        else if (slt == 3)
        {
            continue;
        }
    }
}

void PrintEventCom(EVENT* node)
{
    struct tm* tmpStart, * tmpEnd;

    tmpStart = localtime(&(node->start));
    tmpEnd = localtime(&(node->start));
    printf("nodeID: %s 시작일: %d %d %d %d %d 종료일: %d %d %d %d %d 일정: %s 중요도: %d\n", node->nodeID,
        tmpStart->tm_year + 1900, tmpStart->tm_mon + 1, tmpStart->tm_mday, tmpStart->tm_hour, tmpStart->tm_min,
        tmpEnd->tm_year + 1900, tmpEnd->tm_mon + 1, tmpEnd->tm_mday, tmpEnd->tm_hour, tmpEnd->tm_min,
        node->title, node->importanceLevel);
}

void InorderNodeCom(EVENT* node) 
{
    if (node == NULL)
    {
        return;
    }
    InorderNodeCom(node->prev);
    PrintEventCom(node);
    InorderNodeCom(node->next);
}


void PublicReadEvent(EVENT** root)
{
    EVENT* node;
    node = *root;
    //TimeCheck();

    printf("팀 일정을 출력하세요.\n");
    InorderNodeCom(node);
}