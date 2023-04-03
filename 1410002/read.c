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

        printf("nodeID: %s ������: %d %d %d %d %d ������: %d %d %d %d %d ����: %s ��������: %s �߿䵵: %d\n", node->nodeID,
                                                  tmpStart->tm_year + 1900, tmpStart->tm_mon + 1, tmpStart->tm_mday, tmpStart->tm_hour, tmpStart->tm_min,
                                                  tmpEnd->tm_year + 1900, tmpEnd->tm_mon + 1, tmpEnd->tm_mday, tmpEnd->tm_hour, tmpEnd->tm_min,
                                                  node->title, (node->isPublic == 1)? "����": "�����", node->importanceLevel);
    }
    else if (choice == 2 && node->tag == 0)
    {
        printf("nodeID: %s ������: %d %d %d %d %d ������: %d %d %d %d %d ����: %s ��������: %s �߿䵵: %d\n", node->nodeID,
                                                tmpStart->tm_year + 1900, tmpStart->tm_mon + 1, tmpStart->tm_mday, tmpStart->tm_hour, tmpStart->tm_min,
                                                tmpEnd->tm_year + 1900, tmpEnd->tm_mon + 1, tmpEnd->tm_mday, tmpEnd->tm_hour, tmpEnd->tm_min,
                                                node->title, (node->isPublic == 1) ? "����" : "�����", node->importanceLevel);
    }
    else if (choice == 3 && node->tag == 1)
    {
        printf("nodeID: %s ������: %d %d %d %d %d ������: %d %d %d %d %d ����: %s ��������: %s �߿䵵: %d\n", node->nodeID,
                                                tmpStart->tm_year + 1900, tmpStart->tm_mon + 1, tmpStart->tm_mday, tmpStart->tm_hour, tmpStart->tm_min,
                                                tmpEnd->tm_year + 1900, tmpEnd->tm_mon + 1, tmpEnd->tm_mday, tmpEnd->tm_hour, tmpEnd->tm_min,
                                                node->title, (node->isPublic == 1) ? "����" : "�����", node->importanceLevel);
    }
    else if (choice == 4 && node->tag == 2)
    {
        printf("nodeID: %s ������: %d %d %d %d %d ������: %d %d %d %d %d ����: %s ��������: %s �߿䵵: %d\n", node->nodeID,
                                                tmpStart->tm_year + 1900, tmpStart->tm_mon + 1, tmpStart->tm_mday, tmpStart->tm_hour, tmpStart->tm_min,
                                                tmpEnd->tm_year + 1900, tmpEnd->tm_mon + 1, tmpEnd->tm_mday, tmpEnd->tm_hour, tmpEnd->tm_min,
                                                node->title, (node->isPublic == 1) ? "����" : "�����", node->importanceLevel);
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

void PersonalReadEvent(EVENT** root) 
{
    int t, choice;
    EVENT *node;
    node = *root;
    while(1)
    {
        do 
        {
            printf("%s���� ���� ������ ����ϼ���.\n", node->ownerID);
            printf("��ü ���� ��� : 1\n");
            printf("���� ���� ��� : 2\n");
            printf("ȸ�� ���� ��� : 3\n");
            printf("��Ÿ ���� ��� : 4\n");
            printf("��ȸ ���� : 5\n");
            scanf_s("%d%*c", &choice);
        } while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5);

        if (choice == 5)
        {
            break;
        }

        do
        {
            printf("��ȸ �� �Ⱓ�� ������ �ּ���. \n");
            printf("�Ϸ� : 1, ������ : 2 ��ü : 3 \n");
            scanf_s("%d%*c", &t);
        
        } while (t != 1 && t != 2 && t != 3);

        if (choice == 1)
        {
            printf("%s���� ����\n", node->ownerID);
            InorderNode(node, choice, t);
        }
        else if (choice == 2)
        {
            printf("%s���� ȸ������\n", node->ownerID);
            InorderNode(node, choice, t);
        }
        else if (choice == 3)
        {
            printf("%s���� ��������\n", node->ownerID);
            InorderNode(node, choice, t);
        }
        else if (choice == 4)
        {
            printf("%s���� ��Ÿ����\n", node->ownerID);
            InorderNode(node, choice, t);
        }

    }
}

void PrintEventCom(EVENT* node)
{
    struct tm* tmpStart, * tmpEnd;

    tmpStart = localtime(&(node->start));
    tmpEnd = localtime(&(node->start));
    printf("nodeID: %s ������: %d %d %d %d %d ������: %d %d %d %d %d ����: %s �߿䵵: %d\n", node->nodeID,
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

    printf("�� ������ ����ϼ���.\n");
    InorderNodeCom(node);
}