#include "schedule.h"
#include "user.h"
#include <string.h>
#include <stdlib.h>

void PublicFileSave(PERSON* User);
struct EVENT* PublicFileLoad(PERSON* User);
void PrivateFileSave(PERSON* User);
EVENT* PrivateFileLoad(PERSON* User);