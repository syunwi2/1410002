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
		printf("노드가 존재하지 않습니다. \n");
		return;
	}
	fp = fopen("public.dat", "wb");

	if (fp == NULL)
	{
		printf("저장에 실패했습니다. 관리자에게 문의해주세요\n");
		exit(1);
	}
	fwrite(&seq_no, sizeof(int), 1, fp);

	while (ptr)
	{
		fwrite(ptr, sizeof(EVENT), 1, fp);
		ptr = ptr->next;
	}
	fclose(fp);

	printf("일정 저장이 완료되었습니다. \n");

	return 0;
}


void PublicFileLoad(void)
{
	FILE* fp = NULL;
	EVENT* ptr;

	fp = fopen("public.dat", "rb");
	if (fp == NULL)
	{
		printf("ERROR!! 파일이 존재하지 않습니다. 관리자에게 문의 해주세요 \n");
		return;	// 파일이 존재하지 않으면 부모함수로 돌아가라 
	}

	fread(&seq_no, sizeof(int), 1, fp);

	while (1)
	{
		ptr = (EVENT*)malloc(sizeof(EVENT));
		if (ptr == NULL)
		{
			printf("일정 데이터 불러오기를 실패했습니다. 관리자에게 문의하세요. \n");
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


	printf("일정 데이터 로드를 완료했습니다.\n");


	return 0;
}



