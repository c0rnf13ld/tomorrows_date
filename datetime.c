#include "datetime.h"

char *getdatefmt()
{

	char *ptr = (char *)malloc(DATE_FMT_BUF * sizeof(char));

	time_t t = time(NULL);
	struct tm *datetime_t = localtime(&t);

	datetime_t->tm_year += 1900;
	datetime_t->tm_mon += 1;

	snprintf(ptr, DATE_FMT_BUF, "%02d/%02d/%d", datetime_t->tm_mday, datetime_t->tm_mon, datetime_t->tm_year);

	return ptr;
}
