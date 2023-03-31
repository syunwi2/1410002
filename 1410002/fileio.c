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
		printf("파일이 존재하지 않습니다. 새로운 파일을 생성해주세요! \n");
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
		printf("ERROR!! 파일이 존재하지 않습니다. 관리자에게 문의 해주세요 \n");
		return;	// 파일이 존재하지 않으면 부모함수로 돌아가라 
	}
	
	fread(&a, sizeof(a), 1, fp);
	printf("%d", a);

	fclose(fp);

	return 0;
}


