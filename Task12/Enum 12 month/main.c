#include <stdio.h>
#include <stdlib.h>


typedef enum {Jan=1,Feb,Mar,Apr,May,Jun,Jul,Aug,Sep,Oct,Nov,Dec}year;


int main()
{
    char monthNames[12][4] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    for(int month=Jan;month<=Dec;month++)
        printf("%s = %i\n",monthNames[month-1],month);
    return 0;
}
