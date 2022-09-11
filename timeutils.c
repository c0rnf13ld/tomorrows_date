#include "datetime.h"
#include "timeutils.h"
#include "color.h"

int leap_year = 0;

int is_leapyear(int year)
{
	if (year % 4 == 0)
	{
		leap_year = 1;
		return 1;
	}
	return 0;
}

int checkdate(struct datetime *date_t)
{
	if (date_t->month < 1 || date_t->month > 12 || date_t->day < 1 || date_t->day > 31)
	{
		return -1;
	}
	else
	{
		switch (date_t->month)
		{
			case JANUARY: case MARCH: case MAY: case JULY: case AUGUST: case OCTUBER: case DECEMBER:
				date_t->max_day = 31;
				break;

			case APRIL: case JUNE: case SEPTEMBER: case NOVEMBER:
				date_t->max_day = 30;
				if (date_t->day > date_t->max_day)
				{
					return -2;
				}
				break;

			case 2:
				if (is_leapyear(date_t->year))
				{
					date_t->max_day = 29;
				}
				else
				{
					date_t->max_day = 28;
				}
				if (date_t->day > date_t->max_day)
				{
					return -2;
				}
				break;

			default:
				return -1;
				break;
		}
	}
	return 0;
}

char *get_nextdate(char *actual_date)
{
	struct datetime date_t;
	struct datetime next_date_t;

	int out;

	char *next_date;
	if (!(next_date = malloc(DATE_FMT_BUF * sizeof(char))))
	{
		perror(PERR);
		exit(EXIT_FAILURE);
	}

	date_t.day = get_actualday(actual_date);
	date_t.month = get_actualmon(actual_date);
	date_t.year = get_actualyear(actual_date);

	next_date_t = date_t;

	if ((out = checkdate(&date_t)))
	{
		if (out == -2)
		{
			fprintf(stderr, ERR "Error while checking date, check the day.\n" RESET);
			exit(EXIT_FAILURE);
		}
		fprintf(stderr, ERR "Error while checking date, check the month and the day.\n" RESET);
		exit(EXIT_FAILURE);
	}

	if (date_t.day == date_t.max_day)
	{
		if (date_t.month == DECEMBER)
		{
			next_date_t.month = 1;
			next_date_t.day = 1;
			next_date_t.year += 1;
		}
		else
		{
			next_date_t.month += 1;
			next_date_t.day = 1;
		}
	}
	else
	{
		next_date_t.day += 1;
	}

	snprintf(next_date, DATE_FMT_BUF, "%02d/%02d/%d", next_date_t.day, next_date_t.month, next_date_t.year);

	return next_date;
}

int get_actualday(char *actual_date)
{
	int actual_day;

	if (!sscanf(actual_date, "%d", &actual_day))
	{
		fprintf(stderr, ERR "Bad time format.\n" RESET);
		exit(EXIT_FAILURE);
	}

	return actual_day;
}

int get_actualmon(char *actual_date)
{
	int actual_mon;

	sscanf(actual_date, "%*d/%d", &actual_mon);

	return actual_mon;
}

int get_actualyear(char *actual_date)
{
	int actual_year;

	sscanf(actual_date, "%*d%*[^0-9]%*d%*[^0-9]%d", &actual_year);

	return actual_year;
}

