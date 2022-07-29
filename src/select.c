#include "select.h"
#include <stdio.h>
#include <stdlib.h>

#define SWAP_BY_PTR(ptr1, ptr2) \
  do { (*(ptr1)) += (*(ptr2)); \
       (*(ptr2)) = (*(ptr1)) - (*(ptr2)); \
       (*(ptr1)) = (*(ptr2)) - (*(ptr1)); } \
  while (0)

/* Partitions the accepted array by arr[end].
   Note: the accepted array is mutated. */
static int partition(int *arr, int start, int end);
/* Partitions the accepted array by a randomly chosen array element.
   Note: the accepted array is mutated. */
static int randomized_partition(int *arr, int start, int end);

/* Reports the accepted number of comparisions to stdout. */
static void report_comp_metric(int num_of_comp, char *funcname);

/* Sorts the accetped array in place using insertion sort algorithm.
   Note: the accepted array is mutated. */
/*static void insertion_sort(int *arr, int arr_length);*/

/* Finds the ith smallest element in the accepted array and returns it.
   Note: the accepted array is mutated. */
int randomized_select(int *arr, int start, int end, int i) {
  if (start == end) {
    return arr[start];
  }
  int index = randomized_partition(arr, start, end);
  int left_subarr_including_pivot_length = index - start + 1;
  if (left_subarr_including_pivot_length == i) {
    return arr[index];
  }
  if (i < left_subarr_including_pivot_length) {
    randomized_select(arr, start, index - 1, i);
  } else {
    randomized_select(arr, index + 1, end, i - left_subarr_including_pivot_length);
  }
}

/* Partitions the accepted array by arr[end].
   Note: the accepted array is mutated. */
static int partition(int *arr, int start, int end) {
  int pivot = arr[end];
  int target = start - 1;
  for (int j = start; j < end; j++) {
    if (arr[j] <= pivot) {
      target++;
      SWAP_BY_PTR(arr + target, arr + j);
    }
  }
  SWAP_BY_PTR(arr + target + 1, arr + end);
  return target + 1;
}

/* Partitions the accepted array by a randomly chosen array element.
   Note: the accepted array is mutated. */
static int randomized_partition(int *arr, int start, int end) {
  /* modulo retains pseudo randomness */
  int random_offset = rand() % (end - start);
  SWAP_BY_PTR(arr + start + random_offset, arr + end);
  return partition(arr, start, end);
}

/* Reports the accepted number of comparisions to stdout. */
static void report_comp_metric(int num_of_comp, char *funcname) {
  printf("Number of comparisons for %s id %d", funcname, num_of_comp);
}

/* Finds the ith smallest element in the accepted array and returns it.
   Note: the accepted array is mutated. */
int median_select(int *arr, int start, int end, int i) {

}
