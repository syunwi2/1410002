#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "schedule.h"
#include "fileio.h"

int seq_no = 0;

// 퍼블릭파일 저장 
void PublicFileSave(PERSON* User, EVENT** root)
{
	EVENT* ptr, * eof;
	PERSON* userPtr;
	FILE* fp = NULL;
	char fileName[100];

	ptr = *root;
	userPtr = User;

	sprintf(fileName, "%d.dat", userPtr->dept);

	fp = fopen(fileName, "wb");
	if (fp == NULL)
	{
		printf("저장에 실패했습니다. 관리자에게 문의해주세요\n");
		exit(1);
	}

	if (ptr == NULL)
	{
		return;
	}

	InorderSave(fp, ptr);

	eof = (EVENT*)calloc(1, sizeof(EVENT));
	eof->isPublic = -1;

	fwrite(eof, sizeof(EVENT), 1, fp);
	fclose(fp);

}

// 퍼블릭파일 로드
struct EVENT* PublicFileLoad(PERSON* User)
{
	FILE* fp;
	PERSON* userPtr;
	EVENT* root, tmp;
	char fileName[100];

	userPtr = User;

	sprintf(fileName, "%d.dat", userPtr->dept);

	fp = fopen(fileName, "rb");
	if (fp == NULL)
	{
		//printf("ERROR!! 파일이 존재하지 않습니다. 관리자에게 문의 해주세요 \n");
		return;	// 파일이 존재하지 않으면 부모함수로 돌아가라 
	}

	// 이진 트리 생성 필요
	root = NULL;

	while (fread(&tmp, sizeof(tmp), 1, fp))
	{
		if (tmp.isPublic == -1)
		{
			break;
		}
		CreateNewEvent(&root, userPtr->id, tmp.start, tmp.end, tmp.title, tmp.tag, tmp.isPublic, tmp.importanceLevel);
	}

	fclose(fp);

	return root;
}



// 개인파일 저장 
void PrivateFileSave(PERSON* User, EVENT** root)
{
	EVENT* ptr, * eof;
	PERSON* userPtr;
	FILE* fp = NULL;
	char fileName[100];

	ptr = *root;
	// 유저 주소값을 넘겨줘야 한다....
	userPtr = User;

	sprintf(fileName, "%s.dat", userPtr->id);

	fp = fopen(fileName, "wb");

	if (fp == NULL)
	{
		printf("저장에 실패했습니다. 관리자에게 문의해주세요\n");
		exit(1);
	}

	if (ptr == NULL)
	{
		//printf("노드가 존ㅇㅇㅇ재하지 않습니다. \n");
		return;
	}
	
	InorderSave(fp, ptr);

	eof = (EVENT*)calloc(1, sizeof(EVENT));
	eof->isPublic = -1;

	fwrite(eof, sizeof(EVENT), 1, fp);
	fclose(fp);

}

// 개인파일 로드 
EVENT* PrivateFileLoad(PERSON* User)
{
	FILE* fp;
	PERSON* userPtr;
	EVENT* root, tmp;
	char fileName[100];

	userPtr = User;

	sprintf(fileName, "%s.dat", userPtr->id);

	fp = fopen(fileName, "rb");
	if (fp == NULL)
	{
		//printf("ERROR!! 파일이 존재하지 않습니다. 관리자에게 문의 해주세요 \n");
		return;	// 파일이 존재하지 않으면 부모함수로 돌아가라 
	}

	// 이진 트리 생성 필요
	root = NULL;

	while (fread(&tmp, sizeof(tmp), 1, fp))
	{
		if (tmp.isPublic == -1)
		{
			break;
		}
		CreateNewEvent(&root, userPtr->id, tmp.start, tmp.end, tmp.title, tmp.tag, tmp.isPublic, tmp.importanceLevel);
	}

	fclose(fp);

	return root;
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
