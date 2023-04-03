#include "schedule.h"
#include "person.h"
#include <string.h>
#include <stdlib.h>

void PublicFileSave(PERSON* User, EVENT** root);
struct EVENT* PublicFileLoad(PERSON* User);
void PrivateFileSave(PERSON* User, EVENT** root);
EVENT* PrivateFileLoad(PERSON* User);
void InorderSave(FILE* fp, EVENT* node);