#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main(){
 fork();
 printf("Hello\n");
 fork();
 printf("Hello\n");
 fork();
 printf("Hello\n");
}
