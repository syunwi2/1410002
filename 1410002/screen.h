#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>		// gotoxy �������
#include <conio.h>
#include "person.h"
#include "schedule.h"
#include "fileio.h"
#include "signin.h"
#include "signup.h"
#include "create.h"


void MainScreen(void);							// ���α׷� ����ȭ��
void gotoxy(int x, int y);						// Ŀ�� �ű�� ���̺귯���Լ�

void Calender();								// �޷� ȣ�� �Լ�
int GetDay(int yyyy, int mm);					// ��¥ �ϼ�
int GetMonth(int yyyy, int mm);					// ��¥ ��
int LeafYear(int yyyy);							// ���� ���
void ScreenCal(int start_day, int day_num);		// �޷� ���
void LogOn(EVENT** personalRoot, EVENT** teamRoot, PERSON user, char(*dept_str)[20]);	// �α׿� �Լ�
void CreateEventScreen(EVENT** personalRoot, EVENT** teamRoot, PERSON* user_ptr);
int checkDate(int year, int month, int day);	// ��¥ �˻� �Լ�