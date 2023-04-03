#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "schedule.h"
#include "fileio.h"





// EVENT* head, * tail;
int seq_no = 0;



// 퍼블릭파일 저장 
void PublicFileSave(PERSON* User, EVENT** root)
{
	EVENT* ptr;
	FILE* fp = NULL;
	PERSON* userPtr = NULL;
	char fileName[100];
	
	userPtr = User;

	sprintf(fileName, "%d.dat", userPtr->dept);
	
	ptr = *root;

	if (ptr == NULL)
	{
		printf("노드가 존재하ㄴㄴㄴ지 않습니다. \n");
		return;
	}
	fp = fopen(fileName, "wb");

	if (fp == NULL)
	{
		printf("저장에 실패했습니다. 관리자에게 문의해주세요\n");
		exit(1);
	}

	fwrite(&seq_no, sizeof(int), 1, fp);

	InorderSave(fp, ptr);
	fclose(fp);

	printf("일정 저장이 완료되었습니다. \n");

	return 0;
}

// 퍼블릭파일 로드
struct EVENT* PublicFileLoad(PERSON* User)
{
	FILE* fp = NULL;
	EVENT* root;
	EVENT* newNode = NULL;
	EVENT* toproot = NULL;

	PERSON* userPtr = NULL;
	char fileName[100];

	userPtr = User;

	sprintf(fileName, "%d.dat", userPtr->dept);


	fp = fopen(fileName, "rb");
	if (fp == NULL)
	{
		printf("ERROR!! 파일이 존재하지 않습니다. 관리자에게 문의 해주세요 \n");
		return;	// 파일이 존재하지 않으면 부모함수로 돌아가라 
	}

	fread(&seq_no, sizeof(int), 1, fp);

	while (1)
	{
		root = (EVENT*)malloc(sizeof(EVENT));
		if (root == NULL)
		{
			printf("일정 데이터 불러오기를 실패했습니다. 관리자에게 문의하세요. \n");
		}

		if (fread(root, sizeof(EVENT), 1, fp) != 1)
		{
			break;
		}

		if (newNode == NULL)
		{
			newNode = root;
			toproot = newNode;
		}
		else
		{
			/*tail->next = ptr;
			tail = ptr;*/
			EVENT* tmp;

			// 처음 들어온 주소가 root / 이 root부터 탐색 시작
			tmp = newNode;
			while (1)
			{	
				// 시작일 비교, 탐색중인 노드보다 삽입할 노드의 시작일이 빠른 경우
				if (newNode->start < tmp->start)
				{
					// 현재 노드 이전 일정 없으면 그냥 삽입
					if (tmp->prev == NULL)
					{
						tmp->prev = newNode;
						newNode->parent = tmp;
						break;
					}
					// 현재 탐색중인 노드보다 이전 일정이 있으면 해당 노드를 기준으로 다시 탐색
					else
					{
						tmp = tmp->prev;
					}
				}
				// 탐색중인 노드보다 삽입할 노드의 시작일이 느린 경우
				else
				{
					// 현재 노드 이후 일정이 없으면 그냥 삽입
					if (tmp->next == NULL)
					{
						tmp->next = newNode;
						newNode->parent = tmp;
						break;
					}
					// 현재 탐색중인 노드보다 이전 일정이 있으면 해당 노드를 기준으로 다시 탐색
					else
					{
						tmp = tmp->next;
					}
				}
			}
		}
	}

	fclose(fp);

	free(root);


	printf("팀 일정 데이터 로드를 완료했습니다.\n");

	return toproot;
}



// 개인파일 저장 
void PrivateFileSave(PERSON* User, EVENT** root)
{
	EVENT* ptr;
	PERSON* userPtr;
	FILE* fp = NULL;
	char fileName[100];

	ptr = *root;
	// 유저 주소값을 넘겨줘야 한다....
	userPtr = User;

	sprintf(fileName, "%s.dat", userPtr->id);


	if (ptr == NULL)
	{
		printf("노드가 존ㅇㅇㅇ재하지 않습니다. \n");
		return;
	}
	fp = fopen(fileName, "wb");

	if (fp == NULL)
	{
		printf("저장에 실패했습니다. 관리자에게 문의해주세요\n");
		exit(1);
	}

	fwrite(&seq_no, sizeof(int), 1, fp);

	
	InorderSave(fp, ptr);
	fclose(fp);

	printf("일정 저장이 완료되었습니다. \n");

}

// 개인파일 로드 
EVENT* PrivateFileLoad(PERSON* User)
{
	FILE* fp = NULL;
	EVENT* root;
	EVENT* newNode = NULL;
	EVENT* toproot = NULL;
	
	PERSON* ptr = NULL;	// 유저데이터 주소값을 받아와야 하는게 맞네.....

	ptr = User;

	char fileName[100];


	sprintf(fileName, "%s.dat", ptr->id);	// 주소값 받아와서 찾기
	
	fp = fopen(fileName, "rb");
	if (fp == NULL)
	{
		printf("ERROR!! 파일이 존재하지 않습니다. 관리자에게 문의 해주세요 \n");
		return;	// 파일이 존재하지 않으면 부모함수로 돌아가라 
	}

	fread(&seq_no, sizeof(int), 1, fp);

	while (1)
	{
		root = (EVENT*)malloc(sizeof(EVENT));
		if (root == NULL)
		{
			printf("일정 데이터 불러오기를 실패했습니다. 관리자에게 문의하세요. \n");
		}

		if (fread(root, sizeof(EVENT), 1, fp) != 1)
		{

			break;
		}

		if (newNode == NULL)
		{
			newNode = root;
			toproot = newNode;
		}
		else
		{
			/*tail->next = ptr;
			tail = ptr;*/
			EVENT* tmp;

			// 처음 들어온 주소가 root / 이 root부터 탐색 시작
			tmp = newNode;
			while (1)
			{
				// 시작일 비교, 탐색중인 노드보다 삽입할 노드의 시작일이 빠른 경우
				if (newNode->start < tmp->start)
				{
					// 현재 노드 이전 일정 없으면 그냥 삽입
					if (tmp->prev == NULL)
					{
						tmp->prev = newNode;
						newNode->parent = tmp;
						break;
					}
					// 현재 탐색중인 노드보다 이전 일정이 있으면 해당 노드를 기준으로 다시 탐색
					else
					{
						tmp = tmp->prev;
					}
				}
				// 탐색중인 노드보다 삽입할 노드의 시작일이 느린 경우
				else
				{
					// 현재 노드 이후 일정이 없으면 그냥 삽입
					if (tmp->next == NULL)
					{
						tmp->next = newNode;
						newNode->parent = tmp;
						break;
					}
					// 현재 탐색중인 노드보다 이전 일정이 있으면 해당 노드를 기준으로 다시 탐색
					else
					{
						tmp = tmp->next;
					}
				}
			}
		}
	}

	fclose(fp);

	free(root);


	printf("내 일정 데이터 로드를 완료했습니다.\n");


	return toproot;
}

// 재귀로 노드 파일에 저장
void InorderSave(FILE* fp, EVENT* node)
{
	if (node == NULL)
	{
		return;
	}
	InorderSave(fp, node->prev);
	fwrite(node, sizeof(EVENT), 1, fp);
	InorderSave(fp, node->next);
}
