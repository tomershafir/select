#include "select.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  printf("Compare selection by best case, worst case and avg case inputs:\n");
  int a[] = {9,3,6,2,1,7,8};
  printf("result: %d\n", randomized_select(a, 8, 4));
}
