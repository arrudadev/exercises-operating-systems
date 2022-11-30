#include <stdio.h>
#include <unistd.h>

void info() {
  fork();
  printf("ID do filho: %d\n", getpid());
  printf("ID do filho: %d\n", getppid());
}