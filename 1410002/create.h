#include <string.h>
#include <stdlib.h>
#include "schedule.h"

void CreateNewEvent(EVENT** root, char* id, time_t start, time_t end, char* title, TAG tag, int isPublic, int imPortanceLevel);
void InsertEvent(EVENT** root, EVENT* newNode);