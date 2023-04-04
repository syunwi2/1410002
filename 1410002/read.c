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
    struct tm tmpStart, tmpEnd;

    tmpStart = *(localtime(&(node->start)));
    tmpEnd = *(localtime(&(node->end)));

    if (choice == 1 )
    {

        printf("\t\t\tnodeID �� %s \n\t\t\t��������������������������������\n\t\t\t������  �� %d�� %.2d�� %d�� %d:%d\n\t\t\t������  �� %d�� %.2d�� %d�� %d:%d\n\t\t\t����    �� %s\n\t\t\t�������Φ� %s\n\t\t\t�߿䵵  �� %d / 5\n\n\n", node->nodeID,
                                                  tmpStart.tm_year + 1900, tmpStart.tm_mon + 1, tmpStart.tm_mday, tmpStart.tm_hour, tmpStart.tm_min,
                                                  tmpEnd.tm_year + 1900, tmpEnd.tm_mon + 1, tmpEnd.tm_mday, tmpEnd.tm_hour, tmpEnd.tm_min,
                                                  node->title, (node->isPublic == 1)? "����": "�����", node->importanceLevel);
    }
    else if (choice == 2 && node->tag == 0)
    {
        printf("\t\t\tnodeID �� %s \n\t\t\t��������������������������������\n\t\t\t������  �� %d�� %.2d�� %d�� %d:%d\n\t\t\t������  �� %d�� %.2d�� %d�� %d:%d\n\t\t\t����    �� %s\n\t\t\t�������Φ� %s\n\t\t\t�߿䵵  �� %d / 5\n\n\n", node->nodeID,
                                                    tmpStart.tm_year + 1900, tmpStart.tm_mon + 1, tmpStart.tm_mday, tmpStart.tm_hour, tmpStart.tm_min,
                                                    tmpEnd.tm_year + 1900, tmpEnd.tm_mon + 1, tmpEnd.tm_mday, tmpEnd.tm_hour, tmpEnd.tm_min,
                                                    node->title, (node->isPublic == 1) ? "����" : "�����", node->importanceLevel);
    }
    else if (choice == 3 && node->tag == 1)
    {
        printf("\t\t\tnodeID �� %s \n\t\t\t��������������������������������\n\t\t\t������  �� %d�� %.2d�� %d�� %d:%d\n\t\t\t������  �� %d�� %.2d�� %d�� %d:%d\n\t\t\t����    �� %s\n\t\t\t�������Φ� %s\n\t\t\t�߿䵵  �� %d / 5\n\n\n", node->nodeID,
                                                    tmpStart.tm_year + 1900, tmpStart.tm_mon + 1, tmpStart.tm_mday, tmpStart.tm_hour, tmpStart.tm_min,
                                                    tmpEnd.tm_year + 1900, tmpEnd.tm_mon + 1, tmpEnd.tm_mday, tmpEnd.tm_hour, tmpEnd.tm_min,
                                                    node->title, (node->isPublic == 1) ? "����" : "�����", node->importanceLevel);
    }
    else if (choice == 4 && node->tag == 2)
    {
        printf("\t\t\tnodeID �� %s \n\t\t\t��������������������������������\n\t\t\t������  �� %d�� %.2d�� %d�� %d:%d\n\t\t\t������  �� %d�� %.2d�� %d�� %d:%d\n\t\t\t����    �� %s\n\t\t\t�������Φ� %s\n\t\t\t�߿䵵  �� %d / 5\n\n\n", node->nodeID,
                                                    tmpStart.tm_year + 1900, tmpStart.tm_mon + 1, tmpStart.tm_mday, tmpStart.tm_hour, tmpStart.tm_min,
                                                    tmpEnd.tm_year + 1900, tmpEnd.tm_mon + 1, tmpEnd.tm_mday, tmpEnd.tm_hour, tmpEnd.tm_min,
                                                    node->title, (node->isPublic == 1) ? "����" : "�����", node->importanceLevel);
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
    
    if ((*root) == NULL)
    {
        printf("\n                         ������ �������� �ʽ��ϴ�.");
        return;
    }
    textcolor(14);
    gotoxy(27, 13);
    printf("==================================");
    gotoxy(27, 14);
    printf("        2. ���� ���� ��ȸ         ");
    gotoxy(27, 15);
    printf("==================================");

    textcolor(15);

    while(1)
    {
        do 
        {

            gotoxy(27, 17);
            printf("%s���� ���� ������ ����ϼ���.", (*root)->ownerID);
            gotoxy(27, 18);
            printf("                                            ");
            gotoxy(27, 19);
            printf("       1.  ��ü ���� ���      ");
            gotoxy(27, 20);
            printf("       2.  ���� ���� ���       ");
            gotoxy(27, 21);
            printf("       3.  ȸ�� ���� ���       ");
            gotoxy(27, 22); 
            printf("       4.  ��Ÿ ���� ���      ");
            gotoxy(0, 23);
            printf("                                                                                                         ");
            gotoxy(27, 23);
            printf("       5.  ��ȸ ����                         \n");
            printf("                                                                           ");

            gotoxy(27, 25);
            textcolor(14);
            printf("�� ���ϴ� �۾���ȣ�� �Է����ּ���. : ");
            printf("                    \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");


            scanf_s("%d%*c", &choice);
        } while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5);

        if (choice == 5)
        {
            break;
        }

  
        system("cls");
        gotoxy(27, 3);
        printf("==================================");
        gotoxy(27, 4);
        printf("        2. ���� ���� ��ȸ         ");
        gotoxy(27, 5);
        printf("==================================");
        printf("\n");
        printf("\n");
        printf("                             ��ȸ �� �Ⱓ�� ������ �ּ���. \n\n");
        textcolor(15);
        printf("                               1.�Ϸ�  2.������  3.��ü   \n\n");
        textcolor(14);
        printf("                             ��    ��ȸ �Ⱓ   :    ");


        do
        {
            printf("                    \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
            scanf_s("%d%*c", &t);
        
        } while (t != 1 && t != 2 && t != 3);

        textcolor(15);
        printf("\n");
        printf("\n");        
        if (choice == 1)
        {
            printf(" \t\t\t\t      %s���� ����\n", (*root)->ownerID);
            printf("                           �������������������������������������������������������������������� \n");
            InorderNode((*root), choice, t);
        }
        else if (choice == 2)
        {
            printf(" \t\t\t\t   %s���� ���� ����\n", (*root)->ownerID);
            printf("                           �������������������������������������������������������������������� \n");
            InorderNode((*root), choice, t);
        }
        else if (choice == 3)
        {
            printf(" \t\t\t\t   %s���� ȸ�� ����\n", (*root)->ownerID);
            printf("                           �������������������������������������������������������������������� \n");
            InorderNode((*root), choice, t);
        }
        else if (choice == 4)
        {
            printf(" \t\t\t\t   %s���� ��Ÿ ����\n", (*root)->ownerID);
            printf("                           �������������������������������������������������������������������� \n");
            InorderNode((*root), choice, t);
        }

        printf("\n");
        printf("\n");
        printf("                             ������ �����Ͻðų� �����ϰڽ��ϱ�? \n\n");
        textcolor(15);
        printf("                               1.����  2.����  3.�ٽ� ��ȸ   \n\n");
        textcolor(14);
        printf("                             ��  ���� ���� / ���� ���� :    ");
        textcolor(15);

        textcolor(14);
        do 
        {   
            printf("                    \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
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
            printf("������ ��� ��ȣ ���� : \n");
            scanf_s("%d%*c", &findnum);
            sprintf(findid, "%.6d", findnum);

            node = *root, ptr = NULL;
            FindNode(node, &ptr, findid);
            //while (node != NULL)
            //{
            //    if (strcmp(node->nodeID, findid) < 0)
            //    {
            //        node = node->next;
            //    }
            //    else if (strcmp(node->nodeID, findid) > 0)
            //    {
            //        node = node->prev;
            //    }
            //    else
            //    {
            //        ptr = node;
            //        break;
            //    }
            //}
            DeleteEvent(root, ptr);
            //ptr = NULL;

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
    printf("\t\t\tnodeID �� %s \n\t\t\t��������������������������������\n\t\t\t������  �� %d�� %.2d�� %d�� %d:%d\n\t\t\t������  �� %d�� %.2d�� %d�� \n\t\t\t����    �� %s\n\t\t\t�������Φ� %s\n\t\t\t�߿䵵  �� %d / 5\n\n\n", 
        node->nodeID, tmpStart->tm_year + 1900, tmpStart->tm_mon + 1, tmpStart->tm_mday, tmpStart->tm_hour, tmpStart->tm_min,
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

void FindNode(EVENT* node, EVENT** ptr, char* id)
{
    if (node == NULL)
    {
        return;
    }

    FindNode(node->prev, ptr, id);

    if (strcmp(node->nodeID, id) == 0)
    {
        *ptr = node;
    }

    FindNode(node->next, ptr, id);
}