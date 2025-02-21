#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

printf("PTD of ex1.c = %d\n", getpid());
char *args[] = {"Nagi", "Rin", "Isagi", NULL};
execv("./ex2", args);
printf("Back to ex1.c");

return 0;
}
