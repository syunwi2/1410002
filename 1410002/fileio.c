#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "schedule.h"
#include "fileio.h"





// EVENT* head, * tail;
int seq_no = 0;



// �ۺ����� ���� 
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
		printf("��尡 �����Ϥ������� �ʽ��ϴ�. \n");
		return;
	}
	fp = fopen(fileName, "wb");

	if (fp == NULL)
	{
		printf("���忡 �����߽��ϴ�. �����ڿ��� �������ּ���\n");
		exit(1);
	}

	fwrite(&seq_no, sizeof(int), 1, fp);

	InorderSave(fp, ptr);
	fclose(fp);

	printf("���� ������ �Ϸ�Ǿ����ϴ�. \n");

	return 0;
}

// �ۺ����� �ε�
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

			// ó�� ���� �ּҰ� root / �� root���� Ž�� ����
			tmp = newNode;
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


	printf("�� ���� ������ �ε带 �Ϸ��߽��ϴ�.\n");

	return toproot;
}



// �������� ���� 
void PrivateFileSave(PERSON* User, EVENT** root)
{
	EVENT* ptr;
	PERSON* userPtr;
	FILE* fp = NULL;
	char fileName[100];

	ptr = *root;
	// ���� �ּҰ��� �Ѱ���� �Ѵ�....
	userPtr = User;

	sprintf(fileName, "%s.dat", userPtr->id);


	if (ptr == NULL)
	{
		printf("��尡 �������������� �ʽ��ϴ�. \n");
		return;
	}
	fp = fopen(fileName, "wb");

	if (fp == NULL)
	{
		printf("���忡 �����߽��ϴ�. �����ڿ��� �������ּ���\n");
		exit(1);
	}

	fwrite(&seq_no, sizeof(int), 1, fp);

	
	InorderSave(fp, ptr);
	fclose(fp);

	printf("���� ������ �Ϸ�Ǿ����ϴ�. \n");

}

// �������� �ε� 
EVENT* PrivateFileLoad(PERSON* User)
{
	FILE* fp = NULL;
	EVENT* root;
	EVENT* newNode = NULL;
	EVENT* toproot = NULL;
	
	PERSON* ptr = NULL;	// ���������� �ּҰ��� �޾ƿ;� �ϴ°� �³�.....

	ptr = User;

	char fileName[100];


	sprintf(fileName, "%s.dat", ptr->id);	// �ּҰ� �޾ƿͼ� ã��
	
	fp = fopen(fileName, "rb");
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

			// ó�� ���� �ּҰ� root / �� root���� Ž�� ����
			tmp = newNode;
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


	printf("�� ���� ������ �ε带 �Ϸ��߽��ϴ�.\n");


	return toproot;
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
