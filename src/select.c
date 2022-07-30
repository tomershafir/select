#include "select.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SWAP_INT_BY_PTR(ptr1, ptr2) \
  do { int __tmp = (*(ptr2)); \
       (*(ptr2)) = (*(ptr1)); \
       (*(ptr1)) = __tmp; } \
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

/* Sorts the accetped array in place using insertion sort algorithm and returns comparisions metric.
   Note: the accepted array is mutated. */
static int insertion_sort(int *arr, int arr_length);

/* Finds the ith smallest element in the accepted array and returns it and reports comparisions metric.
   Note: the accepted array is mutated. */
int _median_select(int *arr, int arr_length, int i, int comp_metric);

/* Partitions the accepted array by val and returns it's new index and relevant comparisions metric.
   Note: the accepted array is mutated. */
static index_and_comp_metric partition_by(int *arr, int index);

static void index_of(int *arr, int arr_length, int val);

static void report_comp_metric(int num_of_comp);

static void print_arr(int *arr, int arr_length);

/* Finds the ith smallest element in the accepted array and returns it and reports comparisions metric.
   Note: the accepted array is mutated. */
int randomized_select(int *arr, int arr_length, int i) {
  printf("randomized_select() the %dth smallest of ", i);
  print_arr(arr, arr_length);
  return _randomized_select(arr, 0, arr_length - 1, i, 0);
}

/* Finds the ith smallest element in the accepted array and returns it and reports comparisions metric.
   Note: the accepted array is mutated. */
static int _randomized_select(int *arr, int start, int end, int i, int comp_metric) {
  int left_subarr_including_pivot_length;
  index_and_comp_metric wrapper;
  
  if (start == end) {
    report_comp_metric(comp_metric);
    return arr[start];
  }

  wrapper = randomized_partition(arr, start, end);
  comp_metric += wrapper.comp_metric;
  left_subarr_including_pivot_length = wrapper.index - start + 1;
  
  if (left_subarr_including_pivot_length == i) {
    report_comp_metric(comp_metric);
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
      SWAP_INT_BY_PTR(arr + target, arr + j);
    }
  }
  SWAP_INT_BY_PTR(arr + target + 1, arr + end);

  wrapper.index = target + 1;
  wrapper.comp_metric = comp_counter;
  return wrapper;
}

/* Partitions the accepted array by a randomly chosen array element and returns it's new index and relevant comparisions metric.
   Note: the accepted array is mutated. */
static index_and_comp_metric randomized_partition(int *arr, int start, int end) {
  int rndm, rndm_offset;

  srand(time(0));
  rndm = rand();
  /* modulo retains pseudo randomness */
  rndm_offset = rndm % (end - start + 1);
  SWAP_INT_BY_PTR(arr + start + rndm_offset, arr + end);
  return partition(arr, start, end);
}

static void report_comp_metric(int num_of_comp) {
  printf("number of comparisons: %d\n", num_of_comp);
}

/* Finds the ith smallest element in the accepted array and returns it and reports comparisions metric.
   Note: the accepted array is mutated. */
int median_select(int *arr, int arr_length, int i) {

}

/* Finds the ith smallest element in the accepted array and returns it and reports comparisions metric.
   Note: the accepted array is mutated. */
int _median_select(int *arr, int arr_length, int i, int comp_metric) {
  
}

/* Sorts the accetped array in place using insertion sort algorithm and returns comparisions metric.
   Note: the accepted array is mutated. */
static int insertion_sort(int *arr, int arr_length) {

}

/* Partitions the accepted array by val and returns it's new index and relevant comparisions metric.
   Note: the accepted array is mutated. */
static index_and_comp_metric partition_by(int *arr, int val) {

}

static void index_of(int *arr, int arr_length, int val) {

}

static void print_arr(int *arr, int arr_length) {
  int j;
  for(j = 0; j < arr_length; j++) {
    printf("%d ", arr[j]);
  }
  printf("\n");
}
