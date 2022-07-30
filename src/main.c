#include "select.h"
#include <stdio.h>


static void drive_randomized_select();
static void drive_median_select_by_5();
static void drive_median_select_by_7();


int main(int argc, char *argv[]) {
  drive_randomized_select();
  drive_median_select_by_5();
  drive_median_select_by_7();
}


static void drive_randomized_select() {
  int i;
  int matrix1[3][9] = {{3,9,6,2,1,7,8,4,5}, {11,12,13,14,15,16,17,18,19}, {29,28,27,26,25,24,23,22,21}};
  int matrix2[3][12] = {{18,34,9,22,5,1,26,13,7,78,99,10}, {2,4,15,11,49,98,6,83,7,9,49,21}, {77,51,24,33,5,9,12,78,66,4,39,82}};
  int matrix3[3][15] ={{4,3,52,51,59,38,7,26,15,5,6,27,35,33,1}, {95,98,97,32,21,44,63,9,6,90,70,45,81,2}, {76,49,33,2,35,7,74,68,41,3,4,53,32,43,4}};
  printf("**************************************\n");
  for (i = 0; i < 3; i++) {
    printf("result: %d\n", randomized_select(matrix1[i], 9, i+2));
  }
  for (i = 0; i < 3; i++) {
    printf("result: %d\n", randomized_select(matrix2[i], 12, i+4));
  }
  for (i = 0; i < 3; i++) {
    printf("result: %d\n", randomized_select(matrix3[i], 15, i+6));
  }
}

static void drive_median_select_by_5() {
  int i;
  int matrix1[3][9] = {{3,9,6,2,1,7,8,4,5}, {11,12,13,14,15,16,17,18,19}, {29,28,27,26,25,24,23,22,21}};
  int matrix2[3][12] = {{18,34,9,22,5,1,26,13,7,78,99,10}, {2,4,15,11,49,98,6,83,7,9,49,21}, {77,51,24,33,5,9,12,78,66,4,39,82}};
  int matrix3[3][15] ={{4,3,52,51,59,38,7,26,15,5,6,27,35,33,1}, {95,98,97,32,21,44,63,9,6,90,70,45,81,2}, {76,49,33,2,35,7,74,68,41,3,4,53,32,43,4}};
  printf("**************************************\n");
  for (i = 0; i < 3; i++) {
    printf("result: %d\n", median_select_by_5(matrix1[i], 9, i+2));
  }
  for (i = 0; i < 3; i++) {
    printf("result: %d\n", median_select_by_5(matrix2[i], 12, i+4));
  }
  for (i = 0; i < 3; i++) {
    printf("result: %d\n", median_select_by_5(matrix3[i], 15, i+6));
  }
}

static void drive_median_select_by_7() {
  int i;
  int matrix1[3][9] = {{3,9,6,2,1,7,8,4,5}, {11,12,13,14,15,16,17,18,19}, {29,28,27,26,25,24,23,22,21}};
  int matrix2[3][12] = {{18,34,9,22,5,1,26,13,7,78,99,10}, {2,4,15,11,49,98,6,83,7,9,49,21}, {77,51,24,33,5,9,12,78,66,4,39,82}};
  int matrix3[3][15] ={{4,3,52,51,59,38,7,26,15,5,6,27,35,33,1}, {95,98,97,32,21,44,63,9,6,90,70,45,81,2}, {76,49,33,2,35,7,74,68,41,3,4,53,32,43,4}};
  printf("**************************************\n");
  for (i = 0; i < 3; i++) {
    printf("result: %d\n", median_select_by_7(matrix1[i], 9, i+2));
  }
  for (i = 0; i < 3; i++) {
    printf("result: %d\n", median_select_by_7(matrix2[i], 12, i+4));
  }
  for (i = 0; i < 3; i++) {
    printf("result: %d\n", median_select_by_7(matrix3[i], 15, i+6));
  }
}
