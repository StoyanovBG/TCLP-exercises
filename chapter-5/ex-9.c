#include <stdio.h>

static char year_month_days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static char leap_year_month_days[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

static char *daytab[2] = {year_month_days, leap_year_month_days};

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pda);

int main(void)
{
    int day_f = day_of_year(2008, 14, 23);
    printf("%d\n", day_f);

    int day_r = day_of_year(2008, 6, 23);
    printf("%d\n", day_r);

    int month, day2;
    month_day(2022, 256, &month, &day2);
    printf("%d %d\n", month, day2);

    month_day(2001, 64, &month, &day2);
    printf("%d %d\n", month, day2);

    return 0;
}

int day_of_year(int year, int month, int day)
{
    int leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    if (month > 12){
        printf("betweeen 1 and 12\n");
        return -1;
    }
    if (day > daytab[leap][month]){
        printf("%d month max %d days\n", month, daytab[leap][month]);
        return -2;
    }
    int i;
    for (i = 1; i < month; i++){
        day += daytab[leap][i];
    }
    return day;
}
void month_day(int year, int yearday, int *pmonth, int *pda)
{
    int leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    if ((!leap && yearday > 365) || (leap && yearday > 366))
    {
        *pmonth = 0;
        *pda = 0;
        printf("year %d  %d days\n", year, leap ? 366 : 365);
        return;
    }
    int i;
    for (i = 0; yearday > daytab[leap][i]; i++){
        yearday -= daytab[leap][i];
    }
    *pmonth = i;
    *pda = yearday;
}
