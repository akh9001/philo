#include <stdio.h>
#include <sys/time.h>
#include <time.h>

int main()
{
    struct timeval tv;
    struct timezone tz;
    struct tm *today;
    int zone;

    gettimeofday(&tv,&tz);

    /* get time details */
    today = localtime(&tv.tv_sec);
    printf("It's %d:%0d:%0d.micro %d mili %lu\n",
            today->tm_hour,
            today->tm_min,
            today->tm_sec,
            tv.tv_usec,
            tv.tv_sec * 1000
          );
    /* set time zone value to hours, not minutes */
    zone = tz.tz_minuteswest/60;
    /* calculate for zones east of GMT */
    if( zone > 12 )
        zone -= 24;
    printf("Time zone: GMT %+d\n",zone);
    printf("Daylight Saving Time adjustment: %d\n",tz.tz_dsttime);

    return(0);
}
