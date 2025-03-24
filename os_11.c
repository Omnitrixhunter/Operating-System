#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]){
  int fd[2];
  // fd[0] -> read
  // fd[1] -> write
  if(pipe(fd) == -1){
    printf("Error occured : opening the pipe\n");
	return 1;
  }
  int id = fork();
  if(id == -1){
    printf("Error occured : fork");
	return 4;
  }
  else if(id == 0){
    close(fd[0]);
	int x;
	printf("Input a number : ");
	scanf("%d", &x);
	if(write(fd[1], &x, sizeof(int)) == -1){
      printf("Error occured : writing to pipe\n");
	  return 2;
	}
	close(fd[1]);
  }
  else {
    close(fd[1]);
	int y;
	if(read(fd[0], &y, sizeof(int)) == -1){
	  printf("Error occured : reading the pipe\n");
	  return 3;
	}
    close(fd[0]);
	printf("Got from child process %d\n", y);
  }
}
