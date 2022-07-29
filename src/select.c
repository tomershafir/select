#include "select.h"
#include <stdio.h>
#include <stdlib.h>

#define SWAP_BY_PTR(ptr1, ptr2) \
  do { (*(ptr1)) += (*(ptr2)); \
       (*(ptr2)) = (*(ptr1)) - (*(ptr2)); \
       (*(ptr1)) = (*(ptr2)) - (*(ptr1)); } \
  while (0)

typedef struct index_and_comp_metric {
  int index;
  int comp_metric;
} index_and_comp_metric;

/* Partitions the accepted array by arr[end] and returns it's new index and relevant comparisions metric.
   Note: the accepted array is mutated. */
static index_and_comp_metric partition(int *arr, int start, int end);

/* Partitions the accepted array by a randomly chosen array element and returns it's new index and relevant comparisions metric.
   Note: the accepted array is mutated. */
static index_and_comp_metric randomized_partition(int *arr, int start, int end);

/* Finds the ith smallest element in the accepted array and returns it and reports comparisions metric.
   Note: the accepted array is mutated. */
static int _randomized_select(int *arr, int start, int end, int i, int comp_metric);

/* Reports the accepted number of comparisions to stdout. */
static void report_comp_metric(int num_of_comp, char *funcname);

/* Sorts the accetped array in place using insertion sort algorithm.
   Note: the accepted array is mutated. */
/*static void insertion_sort(int *arr, int arr_length);*/

/* Finds the ith smallest element in the accepted array and returns it and reports comparisions metric.
   Note: the accepted array is mutated. */
int randomized_select(int *arr, int arr_length, int i) {
  return _randomized_select(arr, 0, arr_length - 1, i, 0);
}

/* Finds the ith smallest element in the accepted array and returns it and reports comparisions metric.
   Note: the accepted array is mutated. */
static int _randomized_select(int *arr, int start, int end, int i, int comp_metric) {
  int left_subarr_including_pivot_length;
  index_and_comp_metric wrapper;
  
  if (start == end) {
    report_comp_metric(comp_metric, "randomized_select");
    return arr[start];
  }

  wrapper = randomized_partition(arr, start, end);
  comp_metric += wrapper.comp_metric;
  left_subarr_including_pivot_length = wrapper.index - start + 1;
  
  if (left_subarr_including_pivot_length == i) {
    report_comp_metric(comp_metric, "randomized_select");
    return arr[wrapper.index];
  }

  if (i < left_subarr_including_pivot_length) {
    return _randomized_select(arr, start, wrapper.index - 1, i, comp_metric);
  } else {
    return _randomized_select(arr, wrapper.index + 1, end, i - left_subarr_including_pivot_length, comp_metric);
  }
}

/* Partitions the accepted array by arr[end] and returns it's new index and relevant comparisions metric.
   Note: the accepted array is mutated. */
static index_and_comp_metric partition(int *arr, int start, int end) {
  int pivot, target, j;
  int comp_counter = 0;
  index_and_comp_metric wrapper;

  pivot = arr[end];
  target = start - 1;
  for (j = start; j < end; j++) {
    comp_counter++;
    if (arr[j] <= pivot) {
      target++;
      SWAP_BY_PTR(arr + target, arr + j);
    }
  }
  SWAP_BY_PTR(arr + target + 1, arr + end);

  wrapper.index = target + 1;
  wrapper.comp_metric = comp_counter;
  return wrapper;
}

/* Partitions the accepted array by a randomly chosen array element and returns it's new index and relevant comparisions metric.
   Note: the accepted array is mutated. */
static index_and_comp_metric randomized_partition(int *arr, int start, int end) {
  int random_offset;

  /* modulo retains pseudo randomness */
  random_offset = rand() % (end - start);
  SWAP_BY_PTR(arr + start + random_offset, arr + end);
  return partition(arr, start, end);
}

/* Reports the accepted number of comparisions to stdout. */
static void report_comp_metric(int num_of_comp, char *funcname) {
  printf("Number of comparisons by %s is %d\n", funcname, num_of_comp);
}

/* Finds the ith smallest element in the accepted array and returns it and reports comparisions metric.
   Note: the accepted array is mutated. */
int median_select(int *arr, int arr_length, int i) {

}
