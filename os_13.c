#include <stdlib.h> 
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <signal.h>

int main(int argc, char* argv[]){
  int pid = fork();
  if(pid == -1) return 1;
  if(pid == 0){
    while(1){
      printf("-------\n");
	  usleep(1000000);
	}
  }
  else{
    sleep(10);
    kill(pid, SIGKILL);
    wait(NULL);
  }

return 0;
}
