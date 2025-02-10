#include<stdio.h>
#include<unistd.h>

int main(){
 //printf("\n");
 if(fork() || fork()){
  fork();
  //printf("%d\n", getppid());
  printf("1 ");
 }

return 0;
}









