#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "schedule.h"
#include "fileio.h"




EVENT* head, * tail;
int seq_no = 0;


// �ۺ����� ���� 
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
		if (ptr->isPublic)
		{
			fwrite(ptr, sizeof(EVENT), 1, fp);
		}
		ptr = ptr->next;
	}
	fclose(fp);

	printf("���� ������ �Ϸ�Ǿ����ϴ�. \n");

	return 0;
}

// �ۺ����� �ε�
returvoid PublicFileLoad(void)
{
	FILE* fp = NULL;
	EVENT* root;
	EVENT* newNode = NULL;


	fp = fopen("public.dat", "rb");
	if (fp == NULL)
	{
		printf("ERROR!! ������ �������� �ʽ��ϴ�. �����ڿ��� ���� ���ּ��� \n");
		return;	// ������ �������� ������ �θ��Լ��� ���ư��� 
	}

	fread(&seq_no, sizeof(int), 1, fp);

	while (1)
	{
		root = (EVENT*)malloc(sizeof(EVENT));
		if (root == NULL)
		{
			printf("���� ������ �ҷ����⸦ �����߽��ϴ�. �����ڿ��� �����ϼ���. \n");
		}

		if (fread(root, sizeof(EVENT), 1, fp) != 1)
		{
			break;
		}

		if (head == NULL)
		{
			head = tail = root;
		}
		else
		{
			/*tail->next = ptr;
			tail = ptr;*/
			EVENT* tmp;

			// ó�� ���� �ּҰ� root / �� root���� Ž�� ����
			tmp = head;
			while (1)
			{	
				// ������ ��, Ž������ ��庸�� ������ ����� �������� ���� ���
				if (newNode->start < tmp->start)
				{
					// ���� ��� ���� ���� ������ �׳� ����
					if (tmp->prev == NULL)
					{
						tmp->prev = newNode;
						newNode->parent = tmp;
						break;
					}
					// ���� Ž������ ��庸�� ���� ������ ������ �ش� ��带 �������� �ٽ� Ž��
					else
					{
						tmp = tmp->prev;
					}
				}
				// Ž������ ��庸�� ������ ����� �������� ���� ���
				else
				{
					// ���� ��� ���� ������ ������ �׳� ����
					if (tmp->next == NULL)
					{
						tmp->next = newNode;
						newNode->parent = tmp;
						break;
					}
					// ���� Ž������ ��庸�� ���� ������ ������ �ش� ��带 �������� �ٽ� Ž��
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


	printf("���� ������ �ε带 �Ϸ��߽��ϴ�.\n");

}



// �������� ���� 
PrivateFileSave(void)
{
	EVENT* ptr;
	FILE* fp = NULL;
	char fileName[100];

	sprintf(fileName, "%s.dat", ptr->ownerID);

	ptr = head;

	if (ptr == NULL)
	{
		printf("��尡 �������� �ʽ��ϴ�. \n");
		return;
	}
	fp = fopen(fileName, "wb");

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

// �������� �ε� 
void PrivateFileLoad(void)
{
	FILE* fp = NULL;
	EVENT* ptr;

	char fileName[100];

	sprintf(fileName, "%s.dat", ptr->ownerID);
	
	fp = fopen(fileName, "rb");
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



