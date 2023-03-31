#include <stdio.h>

void PublicFileSave();
void PublicFileLoad();

int main()
{
	PublicFileLoad();
	// PublicFileSave();

	return 0;
}

void PublicFileSave()
{
	FILE* fp;
	int a = 5;
	fp = fopen("public.dat", "wb");
	if (fp == NULL)
	{
		printf("������ �������� �ʽ��ϴ�. ���ο� ������ �������ּ���! \n");
		exit(1);
	}
	fwrite(&a, sizeof(int), 1, fp);
	fclose(fp);
	return 0;
}


void PublicFileLoad()
{
	FILE* fp;
	int a = 0;

	fp = fopen("public.dat", "rb");
	if (fp == NULL)
	{
		printf("ERROR!! ������ �������� �ʽ��ϴ�. �����ڿ��� ���� ���ּ��� \n");
		return;	// ������ �������� ������ �θ��Լ��� ���ư��� 
	}
	
	fread(&a, sizeof(a), 1, fp);
	printf("%d", a);

	fclose(fp);

	return 0;
}


