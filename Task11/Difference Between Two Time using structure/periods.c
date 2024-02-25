#include <stdio.h>


typedef struct {
  unsigned int hours;
  unsigned int minutes;
  unsigned int seconds;
}time_period;


void time_difference(time_period x,time_period y){
    unsigned int hours= x.hours-y.hours;
    unsigned int minutes= x.minutes-y.minutes;
    unsigned int seconds= x.seconds-y.seconds;
    printf("TIME DIFFERENCE:%u:%u:%u - %u:%u:%u = %u:%u:%u",x.hours,x.minutes,x.seconds,y.hours,y.minutes,y.seconds,hours,minutes,seconds);
}


void main()
{
printf("Enter start time :\n");
printf("Enter hours, minutes and seconds respectively:")
time_period start;
scanf("%u%u%u",&start.hours,&start.minutes,&start.seconds);
printf("Enter stop time\n");
printf("Enter hours, minutes and seconds respectively:")
time_period stop;
scanf("%u%u%u",&stop.hours,&stop.minutes,&stop.seconds);
time_difference(start,stop);

}
