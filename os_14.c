#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Signal Handler Function
void signal_handler(int sig){
  switch(sig){
    case SIGINT:
	  printf("Received SIGINT (Interrupt from keyboard)\n");
	  break;
	case SIGHUP:
      printf("Received SIGHUP (Terminal Hangup)\n");
	  break;
	case SIGTERM:
	  printf("Received SIGTERM (Terminal Signal)\n");
	  break;
	case SIGQUIT:
	  printf("Received SIGQUIT (Quit Signal)\n");
      exit(0);
  }
}
int main(){
   // Registering signal handler for multiple signals
   signal(SIGINT, signal_handler);
   signal(SIGHUP, signal_handler);
   signal(SIGTERM, signal_handler);
   signal(SIGQUIT, signal_handler);

   printf("Process Running - PID : %d\n", getpid());
   printf("Waiting for signals : Press CTRL+\\ (SIGQUIT) to exit \n");

   while(1){
     pause();
   }

return 0;
}
