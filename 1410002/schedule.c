#include <stdio.h>
#include "schedule.h"

time_t getTimeT(int year, int mon, int day, int hour, int min) {
	struct tm tmp = { 0 };
	tmp.tm_year = year - 1900;
	tmp.tm_mon = mon - 1;
	tmp.tm_mday = day;
	tmp.tm_hour = hour;
	tmp.tm_min = min;
	return mktime(&tmp);
}