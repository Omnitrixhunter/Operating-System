#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
  pid_t pid = fork();
  
  if(pid < 0){
     perror("Fork failed");
     exit(1);
  }
  else if(pid == 0){
     execlp("ls", "ls", "-l", NULL);
     perror("execlp failed");
     exit(1);
  }
  else{
     wait(NULL);
     printf("Parent continuing execution");
  } 
  return 0;
}
