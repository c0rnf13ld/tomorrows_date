#ifndef _TIME_UTILS_H_
#define _TIME_UTILS_H_

#define 			DAY_BUF				3
#define				MON_BUF				3
#define				YEAR_BUF			5

enum daysWith31
{
	JANUARY = 1,
	MARCH = 3,
	MAY = 5,
	JULY = 7,
	AUGUST = 8,
	OCTUBER = 10,
	DECEMBER = 12
};

enum dayWith30
{
	APRIL = 4,
	JUNE = 6,
	SEPTEMBER = 9,
	NOVEMBER = 11
};

struct datetime
{
	int day, max_day, month, year;
};

extern int			leap_year;

int 			is_leapyear(int);
int				checkdate(struct datetime *);
char 			*get_nextdate(char *);

int 			get_actualday(char *);
int				get_actualmon(char *);
int				get_actualyear(char *);


#endif //_TIME_UTILS_H_
