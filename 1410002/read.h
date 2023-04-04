// 작성자 : 고요한

#include <string.h>
#include <stdlib.h>
#include "schedule.h"
#include <stdio.h>
#include "update.h"


long long int TimeGet();
void ChkChoice(EVENT* node, int choice);
void PrintEvent(EVENT* node, int choice, int t);
void InorderNode(EVENT* node, int choice, int t);
void PersonalReadEvent(EVENT** root);
void PrintEventCom(EVENT* node);
void InorderNodeCom(EVENT* node);
void PublicReadEvent(EVENT** root);
void FindNode(EVENT* node, EVENT** ptr, char* id);
