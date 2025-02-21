#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
  pid_t pid = fork();
  int status;
  
  if(pid < 0){
     perror("Fork failed");
     exit(1);
  }
  else if(pid == 0){
     printf("Child PID : %d\n", getpid());
     exit(7);
  }
  else{
     wait(&status);
     if(WIFEEXITED(status))
       printf("Child exited with status : %d\n", WEXITSTATUS(status));
     else if(WIFSIGNALED(status))
       printf("Child terminated by signal : %d\n", WTERMSIG(status));
  } 
  return 0;
}
