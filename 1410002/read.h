#include <string.h>
#include <stdlib.h>
#include "schedule.h"
#include <stdio.h>

long long int TimeGet();
void ChkChoice(EVENT* node, int choice);
void PrintEvent(EVENT* node, int choice, int t);
void InorderNode(EVENT* node, int choice, int t);
void PersonalReadEvent(EVENT** root);
void PrintEventCom(EVENT* node, int deptch);
void InorderNodeCom(EVENT* node, int deptch);
void PublicReadEvent(EVENT** root);
