#include "read.h"
#include <stdbool.h>

void PrintEvent(EVENT* node, int choice) {
    if (choice == 1)
    {
        printf("%s %d %d %s %d %d\n", node->ownerID, node->start, node->end, node->title, node->isPublic, node->importanceLevel);
    }
    else if (choice == 2 && node->tag == 0)
    {
        printf("%s %d %d %s %d %d\n", node->ownerID, node->start, node->end, node->title, node->isPublic, node->importanceLevel);
    }
    else if (choice == 3 && node->tag == 1)
    {
        printf("%s %d %d %s %d %d\n", node->ownerID, node->start, node->end, node->title, node->isPublic, node->importanceLevel);
    }
    else if (choice == 4 && node->tag == 2)
    {
        printf("%s %d %d %s %d %d\n", node->ownerID, node->start, node->end, node->title, node->isPublic, node->importanceLevel);
    }
}

void InorderNode(EVENT* node, int choice) {
    if (node == NULL)
    {
        printf("일정이 존재 하지 않습니다.");
        return;
    }
    InorderNode(node->prev, choice);
    PrintEvent(node, choice);
    InorderNode(node->next, choice);
}

void ReadEvent(EVENT* root) {
    int choice = 0;
    do {
        printf("개인 일정을 출력하세요.\n");
        printf("전체 일정 출력 : 1\n");
        printf("개인 일정 출력 : 2\n");
        printf("회사 일정 출력 : 3\n");
        printf("기타 일정 출력 : 4\n");
        scanf_s("%d", &choice);
    } while (choice != 1 && choice != 2 && choice != 3 && choice != 4);

    //EVENT* current = root;

    if (choice == 1)
    {
        printf("%s님의 일정", root->ownerID);
        InorderNode(root, choice);
    }
    else if (choice == 2)
    {
        printf("%s님의 회사일정", root->ownerID);
        InorderNode(root, choice);
    }
    else if (choice == 3)
    {
        printf("%s님의 개인일정", root->ownerID);
        InorderNode(root, choice);
    }
    else if (choice == 4)
    {
        printf("%s님의 기타일정", root->ownerID);
        InorderNode(root, choice);
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