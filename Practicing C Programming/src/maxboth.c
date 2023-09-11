#include <stdio.h>
#include <stdlib.h>

int max_both(int* x, int xlen, int* y, int ylen) {
  /* Your solution here; replace this code with yours */
  return -2630;
}

int main() 
{

  int a1[7] = {2,4,6,8,10,12,14};
  int b1[4] = {7,7,5,4};

  // checks both orders of arguments since order doesn't matter
  // || means "or"
  if (max_both(a1,7,b1,4) != 4 || max_both(b1,4,a1,7) != 4) {
    printf("FAILED TEST 1\n");
    exit(1);
  }

  int a2[4] = {2,4,6,8};
  int b2[3] = {3,5,7};
  if (max_both(a2,4,b2,3) != -1 || max_both(b2,3,a2,4) != -1) {
    printf("FAILED TEST 2\n");
    exit(1);
  }

  int a3[5] = {7,6,22,4,4};
  int b3[5] = {4,5,5,25,6};
  if (max_both(a3,5,b3,5) != 6 || max_both(b3,5,a3,5) != 6) {
    printf("FAILED TEST 3\n");
    exit(1);
  }

  int a4[7] = {10,20,30,40,50,60,70};
  int b4[5] = {50,40,70,60,10};
  if (max_both(a4,7,b4,5) != 70 || max_both(b4,5,a4,7) != 70) {
    printf("FAILED TEST 4\n");
    exit(1);
  }

  /* We will test your code on additional test
     cases, so make sure it really works. (e.g., you can
     add more of your own test cases, just copy one of the
     above ones and modify it).
     */

  printf("Tests passed for max_both\n");
}

