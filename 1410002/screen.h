#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>		// gotoxy �������
#include <conio.h>

#include "person.h"
#include "schedule.h"
#include "signin.h"
#include "signup.h"
#include "create.h"


void MainScreen(void);							// ���α׷� ����ȭ��
//void DrawMap(void);							// ȭ�� �׵θ� �׸� 
void gotoxy(int x, int y);						// Ŀ�� �ű�� ���̺귯���Լ�

void Calender();								// �޷� ȣ�� �Լ�
int GetDay(int yyyy, int mm);					// ��¥ �ϼ�
int GetMonth(int yyyy, int mm);					// ��¥ ��
int LeafYear(int yyyy);							// ���� ���
void ScreenCal(int start_day, int day_num);		// �޷� ���
int checkDate(int year, int month, int day);	// ��¥ �˻� �Լ�