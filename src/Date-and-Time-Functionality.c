#include <stdio.h>
#include <time.h>

void InitializationAndConversionBetweenTypes(void) {
  time_t now; // var to hold the time now

  now = time(NULL); // u can get it like this

  time(&now); // or this. same as previous line
  
  printf("%s", ctime(&now));

  /* Converting time_t to struct tm */
  printf("Local: %s", asctime(localtime(&now)));
  printf("  UTC: %s", asctime(gmtime(&now)));

  /* Converting struct tm to time_t */
  struct tm some_time = {
    .tm_year=82,   // years since 1900
    .tm_mon=3,     // months since January -- [0, 11]
    .tm_mday=12,   // day of the month -- [1, 31]
    .tm_hour=12,   // hours since midnight -- [0, 23]
    .tm_min=00,    // minutes after the hour -- [0, 59]
    .tm_sec=04,    // seconds after the minute -- [0, 60]
    .tm_isdst=-1,  // Daylight Saving Time flag
  };

  time_t some_time_epoch;

  some_time_epoch = mktime(&some_time);

  printf("%s", ctime(&some_time_epoch));
  printf("Is DST: %d\n", some_time.tm_isdst);

}

void FormattedDateOutput(void) {
  char s[128];
  time_t now = time(NULL);

  // %c: print date as per current locale
  strftime(s, sizeof s, "%c", localtime(&now));
  puts(s); // Thu Nov 11 15:58:32 2021

  // %A: full weekday name
  // %B: full month name
  // %d: day of the month
  strftime(s, sizeof s, "%A, %B %d", localtime(&now));
  puts(s); // Thursday, November 11

  // %I: hour (12 hour clock)
  // %M: minute
  // %S: second
  // %p: AM or PM
  strftime(s, sizeof s, "It's %I:%M:%S %p", localtime(&now));
  puts(s); // It's 04:01:06 PM

  strftime(s, sizeof s, "ISO 8601: %FT%T%z", localtime(&now));
  puts(s); // ISO 8601: 2021-11-11T16:02:16+0300
}

int main(void) {
  InitializationAndConversionBetweenTypes();
  FormattedDateOutput();
  return 0;
}

