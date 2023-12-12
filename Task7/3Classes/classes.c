#include <stdio.h>
#include <stdlib.h>

int main() {
    int x[10],y[10],z[10];
    int passed,falled,highest=0,lowest=100,sumForAverage;
    for (int i=0;i<10;i++){
        x[i]=rand()%101;
        if (x[i]>=50){
            passed++;
        }else{
            falled++;
        }
        if (x[i]>highest)
            highest = x[i];
        if (x[i]< lowest)
            lowest = x[i];
            sumForAverage += x[i];
    }

     for (int i=0;i<10;i++){
        y[i]=rand()%101;
        if (y[i]>=50){
            passed++;
        }else{
            falled++;
        }
        if (y[i]>highest)
            highest = y[i];
        if (y[i]< lowest)
            lowest = y[i];
            sumForAverage += y[i];
    }

     for (int i=0;i<10;i++){
        z[i]=rand()%101;
        if (z[i]>=50){
            passed++;
        }else{
            falled++;
        }
        if (z[i]>highest)
            highest = z[i];
        if (z[i]< lowest)
            lowest = z[i];
            sumForAverage += z[i];
    }
    
    float average = (float)sumForAverage/30;
    printf("passed = %d \n failed = %d \n highest = %d \n lowest = %d \n average = %f",passed,falled,highest,lowest,average);
    return 0;

}
