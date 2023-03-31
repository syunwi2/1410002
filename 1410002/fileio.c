#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "schedule.h"
#include "fileio.h"




EVENT* head, * tail;
int seq_no = 0;

int main()
{

	test();

	PublicFileSave();


	return 0;
}

void PublicFileSave(void)
{
	EVENT* ptr;
	FILE* fp = NULL;

	
	ptr = head;

	if (ptr == NULL)
	{
		printf("��尡 �������� �ʽ��ϴ�. \n");
		return;
	}
	fp = fopen("public.dat", "wb");

	if (fp == NULL)
	{
		printf("���忡 �����߽��ϴ�. �����ڿ��� �������ּ���\n");
		exit(1);
	}
	fwrite(&seq_no, sizeof(int), 1, fp);

	while (ptr)
	{
		fwrite(ptr, sizeof(EVENT), 1, fp);
		ptr = ptr->next;
	}
	fclose(fp);

	printf("���� ������ �Ϸ�Ǿ����ϴ�. \n");

	return 0;
}


void PublicFileLoad(void)
{
	FILE* fp = NULL;
	EVENT* ptr;

	fp = fopen("public.dat", "rb");
	if (fp == NULL)
	{
		printf("ERROR!! ������ �������� �ʽ��ϴ�. �����ڿ��� ���� ���ּ��� \n");
		return;	// ������ �������� ������ �θ��Լ��� ���ư��� 
	}

	fread(&seq_no, sizeof(int), 1, fp);

	while (1)
	{
		ptr = (EVENT*)malloc(sizeof(EVENT));
		if (ptr == NULL)
		{
			printf("���� ������ �ҷ����⸦ �����߽��ϴ�. �����ڿ��� �����ϼ���. \n");
		}

		if (fread(ptr, sizeof(EVENT), 1, fp) != 1)
		{
			break;
		}

		if (head == NULL)
		{
			head = tail = ptr;
		}
		else
		{
			tail->next = ptr;
			tail = ptr;
		}
	}

	fclose(fp);

	free(ptr);


	printf("���� ������ �ε带 �Ϸ��߽��ϴ�.\n");


	return 0;
}



