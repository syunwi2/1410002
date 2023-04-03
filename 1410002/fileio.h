#include "schedule.h"
#include "user.h"
#include <string.h>
#include <stdlib.h>

void PublicFileSave(void);
struct EVENT* PublicFileLoad(void);
void PrivateFileSave(PERSON* User);
EVENT* PrivateFileLoad(PERSON* User);