#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void zero_last(int* arr, int len) 
{
  /* Your solution here */
}

bool arrays_equal(int* a1, int* a2, int len)
{
  for (int i=0; i<len; i++) {
    if (a1[i] != a2[i]) return false;
  }
  return true;
}

int main() 
{
  int a1[4] = {-1,-2,-2,4}; // input
  int a1_exp[4] = {-1,-2,-2,4}; // expected contents of a1 after calling zero_last
  zero_last(a1, 4);
  if (!arrays_equal(a1, a1_exp, 4)) {
    printf("FAILED TEST 1\n");
    exit(1);
  }

  int a2[5] = {0,4,3,2,1};
  int a2_exp[5] = {4,3,2,1,0};
  zero_last(a2, 5);
  if (!arrays_equal(a2, a2_exp, 5)) {
    printf("FAILED TEST 2\n");
    exit(1);
  }

  int a3[6] =  {5, -1, 10, 0, 11, 0};
  int a3_exp[6] = {5,-1,10,11,0,0};
  zero_last(a3, 6);
  if (!arrays_equal(a3, a3_exp, 6)) {
    printf("FAILED TEST 3\n");
    exit(1);
  }

  int a4[9] = {0, 0, -4, 5, -6, 7, 0, 4, 3};
  int a4_exp[9] = {-4,5,-6,7,4,3,0,0,0};
  zero_last(a4, 9);
  if (!arrays_equal(a4, a4_exp, 9)) {
    printf("FAILED TEST 4\n");
    exit(1);
  }

  int a5[3] = {1,0,0};
  int a5_exp[3] = {1,0,0};
  zero_last(a5, 3);
  if (!arrays_equal(a5, a5_exp, 3)) {
    printf("FAILED TEST 5\n");
    exit(1);
  }

  int a6[11] = {0,0,0,0,0,0,1,0,0,0,0};
  int a6_exp[11] = {1,0,0,0,0,0,0,0,0,0,0};
  zero_last(a6, 11);
  if (!arrays_equal(a6, a6_exp, 11)) {
    printf("FAILED TEST 5\n");
    exit(1);
  }

  /* We will test your code on additional test
     cases, so make sure it really works. (e.g., you can
     add more of your own test cases, just copy one of the
     above ones and modify it).
     */

  printf("Tests pass for zero_last\n");
}



