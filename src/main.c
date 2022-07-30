#include "select.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  printf("examine selection by inputs:\n");
  int i;
  
  int a[9][9] = {{3,9,6,2,1,7,8,4,5}, {1,2,3,4,5,6,7,8,9}, {9,8,7,6,5,4,3,2,1}, {8,4,9,2,5,1,6,3,7},
    {2,4,5,1,9,8,6,3,7}, {7,1,4,3,5,9,2,8,6}, {4,3,2,1,9,8,7,6,5}, {5,8,7,2,1,4,3,9,6}, {6,9,3,2,5,7,4,8,1}};
  for (i = 0; i < 9; i++) {
      printf("result: %d\n", randomized_select(a[i], 9, i+1));
  }
}
