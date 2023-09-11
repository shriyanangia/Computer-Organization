#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  int num;
  if (argc > 1) {
    num = atoi(argv[1]);
  } else {
    printf("Requires one numeric argument\n");
    exit(1);
  }
  printf("you gave me %d\n", num);
}
