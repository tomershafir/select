#include "select.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  printf("examine selection by inputs:\n");
  int a[] = {9,3,6,2,1,7,8,4};
  printf("result: %d\n", randomized_select(a, 8, 7));
}
