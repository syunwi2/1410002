#include <string.h>
#include <stdlib.h>
<<<<<<< HEAD
#include <stdio.h>
#include "schedule.h"
=======
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
>>>>>>> 35aa98233ad1c8f8141191ff527af6196f50c3ba
