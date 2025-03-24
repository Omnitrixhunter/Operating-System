#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

int main(){
  int p1[2]; // Child to Parent
  int p2[2]; // Parent to Child

  if(pipe(p1) == -1){ return 1; }
  if(pipe(p2) == -1){ return 1; }

  int pid = fork();

  if(pid == -1){ return 2; }
  
  if(pid == 0){
    // Child Process
	close(p1[0]);
	close(p2[1]);
	
	int x;
	if(read(p2[0], &x, sizeof(x)) == -1){ return 3; } // or exit(3);
    printf("Recieved %d\n", x);
	x *= 7;
	if(write(p1[1], &x, sizeof(x)) == -1){ return 4; }
	printf("CWrote %d\n", x);
     
	close(p1[1]);
	close(p2[0]);
  }
  else {
    // Parent Process
	close(p1[1]);
	close(p2[0]);

	srand(time(NULL));
	int y = rand() % 10;
	if(write(p2[1], &y, sizeof(y)) == -1){ return 5; }
	printf("PWrote %d\n", y);
	if(read(p1[0], &y, sizeof(y)) == -1){ return 6; }
	printf("Result : %d\n", y);

	close(p1[0]);
	close(p2[1]);
	wait(NULL);
  }
  close(p1[0]);
  close(p1[1]);
  return 0;
}
