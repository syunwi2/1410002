#include <string.h>
#include <stdlib.h>
#include "schedule.h"

void DeleteEvent(EVENT** root, EVENT* node);
EVENT* FindNext(EVENT* node);
void CopyEvent(EVENT* to, EVENT* from);