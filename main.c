#include "common.h"
#include "datetime.h"
#include "timeutils.h"
#include "color.h"

int main(int argc, char **argv)
{
	char *actual_date = getdatefmt();
	char *next_date;

	if (!(next_date = get_nextdate(actual_date)))
	{
		fprintf(stderr, ERR "An error ocurred.\n");
		exit(EXIT_FAILURE);
	}

	printf(LG_GRN "Today:" LG_BLU " %s\n", actual_date);
	printf(GRN "Tomorrow:" BLU " %s\n" RESET, next_date);

	return 0;
}
