#include<stdio.h>
#include<unistd.h>

int main(){
pid_t ret_value;
printf("\nThe Process ID is %d\n", getpid());

ret_value = fork();
if(ret_value < 0){
     //fork has failed
	 printf("\nFork Failure\n");
}
else if(ret_value == 0){
     //child process
	 printf("\nChild Process\n");
	 printf("The Process ID is %d\n", getpid());
	 //sleep(20);
}
else{
     //parent process
	 //wait();
	 printf("Parent Process\n");
	 printf("The Process ID is %d\n", getpid());
	 //sleep(30);
}

return 0;
}
