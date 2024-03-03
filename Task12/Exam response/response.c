#include <stdio.h>


int main(){
int num_questions=25;
char correct[25];
printf("Input key to the items\n");
for (int i=0; i<num_questions; i++){
  scanf(" %c",&correct[i]);
}
for (int i=1; i<=3; i++){
   char answer;
   int right_count=0;
   int wrong[25]={0};
   int x;
  printf("\ninput response of student- %i \n",i);
  for(int j=0; j<num_questions;j++){
     scanf(" %c",&answer);
     if (answer==correct[j]){
        right_count++;
     }else{
        wrong[j]=1;
     }

  }
  printf("student-%i\n",i);
  printf("score is %i out of %i \n",right_count,num_questions);
  printf("Response to the item below are wrong\n");
  for(int i=0;i<num_questions;i++){
    if (wrong[i]==1)printf("%i   ",(i+1));
  }

}
return 0;
}
