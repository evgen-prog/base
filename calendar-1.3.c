//from home
#include <stdio.h>
#include <time.h>
#define L_YEAR 366
#define YEAR 365
#define DAY 86400
#define HOUR 3600
#define MIN 60

int main() {
int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int day, hour, min, sec;
int year;
int month_day;
int month_num;
int var, i, mon;
long int buf;
year = 1970;
day = 1;
hour = 0;
min = 0;
sec = 0;

/* Полных лет, дней, минут и остаток секунд в 'buf' */
buf = time(NULL);
if(buf > DAY)
while(buf > DAY){
buf = buf - DAY;
day++;
}
if(buf > HOUR)
while(buf > HOUR){
buf = buf - HOUR;
hour++;
}
if(buf > MIN)
while(buf > MIN){
buf = buf - MIN;
min++;
}
var = YEAR;
if(day > var)
while(day > var){
day = day - var;
year++;
if(year%4 == 0){
month[1] = 29;
var = L_YEAR;
}
else {
var = YEAR;
month[1] = 28;
}
}
sec = buf;

/* Округление времени: 23:59:60 = 1 день */
if(hour == 23)
if(min == 59)
if(sec == 60){
hour = 0;
min = 0;
sec = 0;
day = day + 1;
}
/* День месяца */
i = 0;
mon = month[i];
if(day > mon){
while(day > mon){
i++;
mon = mon + month[i];
}
month_day = month[i] - (mon - day);
}
else
month_day = day;

month_num = i + 1;

printf("Time UTC:\n%d/%d/%d/%d/%d/%d\n", year, month_num, month_day, hour, min, sec);
}
