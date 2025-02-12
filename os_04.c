#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main(){
 int pid, status;
 pid = fork();
 
 if(pid == -1){
  printf("Fork Unsuccessful");
  exit(1);
 }
 else if(pid == 0){
  printf("Child");
  exit(2);
 }
 else{
  wait(&status);
  printf("Parent");
  exit(3);
 }
}
