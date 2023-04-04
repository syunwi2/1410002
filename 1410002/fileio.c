#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "schedule.h"
#include "fileio.h"

int seq_no = 0;

// �ۺ����� ���� 
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
		printf("���忡 �����߽��ϴ�. �����ڿ��� �������ּ���\n");
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

// �ۺ����� �ε�
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
		//printf("ERROR!! ������ �������� �ʽ��ϴ�. �����ڿ��� ���� ���ּ��� \n");
		return;	// ������ �������� ������ �θ��Լ��� ���ư��� 
	}

	// ���� Ʈ�� ���� �ʿ�
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



// �������� ���� 
void PrivateFileSave(PERSON* User, EVENT** root)
{
	EVENT* ptr, * eof;
	PERSON* userPtr;
	FILE* fp = NULL;
	char fileName[100];

	ptr = *root;
	// ���� �ּҰ��� �Ѱ���� �Ѵ�....
	userPtr = User;

	sprintf(fileName, "%s.dat", userPtr->id);

	fp = fopen(fileName, "wb");

	if (fp == NULL)
	{
		printf("���忡 �����߽��ϴ�. �����ڿ��� �������ּ���\n");
		exit(1);
	}

	if (ptr == NULL)
	{
		//printf("��尡 �������������� �ʽ��ϴ�. \n");
		return;
	}
	
	InorderSave(fp, ptr);

	eof = (EVENT*)calloc(1, sizeof(EVENT));
	eof->isPublic = -1;

	fwrite(eof, sizeof(EVENT), 1, fp);
	fclose(fp);

}

// �������� �ε� 
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
		//printf("ERROR!! ������ �������� �ʽ��ϴ�. �����ڿ��� ���� ���ּ��� \n");
		return;	// ������ �������� ������ �θ��Լ��� ���ư��� 
	}

	// ���� Ʈ�� ���� �ʿ�
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

// ��ͷ� ��� ���Ͽ� ����
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
