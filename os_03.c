#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
 pid_t pid;
 for(int i = 0; i < 5; i++){
    pid = fork();
	if(pid < 0){
      perror("Fork Failed");
	  exit(1);
	} 
	else if(pid == 0){
     printf("Child Process %d (PID : %d, Parent PID: %d)\n", i+1, getpid(), getppid());  
	} 
	//else {
	 //wait(NULL);
	 //break;
	//}
	printf("1 ");
 }

return 0;
}
