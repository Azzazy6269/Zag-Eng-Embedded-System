#include <stdio.h>
#include <stdlib.h>

unsigned char **ptrNames =NULL;
unsigned int *ptrScores = NULL;
char check=0;
int main()
{
    ptrScores = (unsigned int*)calloc(50,sizeof(unsigned int ));
    ptrNames = (unsigned char**)calloc(50,sizeof(unsigned char *));
    for(int i=0; i<50;i++){
        ptrNames[i]=(unsigned char*)calloc(10,sizeof(unsigned char));
    }
    for(int i=0;i<50;i++){
    printf("Enter student name :");
    scanf("%s",ptrNames[i]);
    printf("Enter student score : ");
    scanf ("%u",ptrScores[i]);
    printf("More data? 1 to stop . others to continue : ");
    scanf("%c",&check);
    if(check == "1")break;
    }


    return 0;
}
