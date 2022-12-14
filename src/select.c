#include "select.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


#define SWAP_INT_BY_PTR(ptr1, ptr2) \
  do { int __tmp = (*(ptr2)); \
       (*(ptr2)) = (*(ptr1)); \
       (*(ptr1)) = __tmp; } \
  while (0)


typedef struct value_and_comp_metric {
  int value;
  int comp_metric;
} value_and_comp_metric;

/* Finds the ith smallest element in the accepted array and returns it and reports comparisions metric.
   Note: the accepted array is mutated. */
static int _randomized_select(int *arr, int start, int end, int i, int comp_metric);

/* Partitions the accepted array by a randomly chosen array element and returns it's new index and relevant comparisions metric.
   Note: the accepted array is mutated. */
static value_and_comp_metric randomized_partition(int *arr, int start, int end);

/* Partitions the accepted array by arr[end] and returns it's new index and relevant comparisions metric.
   Note: the accepted array is mutated. */
static value_and_comp_metric partition(int *arr, int start, int end);

/* Finds the ith smallest element in the accepted array and returns it and reports comparisions metric.
   Note: the accepted array is mutated. */
int _median_select(int *arr, int arr_length, int i, int comp_metric, int seed);

/* Finds the median of medians of the accepted array. */
value_and_comp_metric find_median_of_medians(int *arr, int arr_length, int comp_metric, int seed);

/* Sorts the accetped array in place using insertion sort algorithm and returns comparisions metric.
   Note: the accepted array is mutated. */
static int insort(int *arr, int arr_length);

/* Partitions the accepted array by val and returns it's new index and relevant comparisions metric.
   Note: the accepted array is mutated. */
static value_and_comp_metric partition_by(int *arr, int start, int end, int val);

static value_and_comp_metric index_of(int *arr, int start, int end, int val);

static void report_comp_metric(int comp_metric);

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
  value_and_comp_metric wrapper;
  
  if (start == end) {
    report_comp_metric(comp_metric);
    return arr[start];
  }

  wrapper = randomized_partition(arr, start, end);
  comp_metric += wrapper.comp_metric;
  left_subarr_including_pivot_length = wrapper.value - start + 1;
  
  if (i == left_subarr_including_pivot_length) {
    report_comp_metric(comp_metric);
    return arr[wrapper.value];
  }

  if (i < left_subarr_including_pivot_length) {
    return _randomized_select(arr, start, wrapper.value - 1, i, comp_metric);
  } else {
    return _randomized_select(arr, wrapper.value + 1, end, i - left_subarr_including_pivot_length, comp_metric);
  }
}

/* Partitions the accepted array by a randomly chosen array element and returns it's new index and relevant comparisions metric.
   Note: the accepted array is mutated. */
static value_and_comp_metric randomized_partition(int *arr, int start, int end) {
  int rndm, rndm_offset;

  srand(time(0));
  rndm = rand();
  /* modulo retains pseudo randomness */
  rndm_offset = rndm % (end - start + 1);
  SWAP_INT_BY_PTR(arr + start + rndm_offset, arr + end);
 
  return partition(arr, start, end);
}

/* Partitions the accepted array by arr[end] and returns it's new index and relevant comparisions metric.
   Note: the accepted array is mutated. */
static value_and_comp_metric partition(int *arr, int start, int end) {
  int pivot, target, j;
  int comp_metric = 0;
  value_and_comp_metric wrapper;

  pivot = arr[end];
  target = start - 1;
  for (j = start; j < end; j++) {
    comp_metric++;
    if (arr[j] <= pivot) {
      target++;
      SWAP_INT_BY_PTR(arr + target, arr + j);
    }
  }
  SWAP_INT_BY_PTR(arr + target + 1, arr + end);

  wrapper.value = target + 1;
  wrapper.comp_metric = comp_metric;
  return wrapper;
}

/* Finds the ith smallest element in the accepted array and returns it and reports comparisions metric.
   Note: the accepted array is mutated. */
int median_select_by_5(int *arr, int arr_length, int i) {
  printf("median_select_by_5() the %dth smallest of ", i);
  print_arr(arr, arr_length);
  return _median_select(arr, arr_length, i, 0, 5);
}

/* Finds the ith smallest element in the accepted array and returns it and reports comparisions metric.
   Note: the accepted array is mutated. */
int median_select_by_7(int *arr, int arr_length, int i) {
  printf("median_select_by_7() the %dth smallest of ", i);
  print_arr(arr, arr_length);
  return _median_select(arr, arr_length, i, 0, 7);
}

/* Finds the ith smallest element in the accepted array and returns it and reports comparisions metric.
   Note: the accepted array is mutated. */
int _median_select(int *arr, int arr_length, int i, int comp_metric, int seed) {
  value_and_comp_metric median_wrapper;
  value_and_comp_metric index_wrapper;
  int left_subarr_including_pivot_length;

  median_wrapper = find_median_of_medians(arr, arr_length, comp_metric, seed);
  comp_metric += median_wrapper.comp_metric;
  
  index_wrapper = partition_by(arr, 0, arr_length - 1, median_wrapper.value);
  comp_metric += index_wrapper.comp_metric;

  left_subarr_including_pivot_length = index_wrapper.value + 1;

  if (i == left_subarr_including_pivot_length) {
    report_comp_metric(comp_metric);
    return median_wrapper.value;
  }
  
  if (i < left_subarr_including_pivot_length) {
    return _median_select(arr, left_subarr_including_pivot_length - 1, i, comp_metric, seed);
  } else {
    return _median_select(arr + left_subarr_including_pivot_length, arr_length - left_subarr_including_pivot_length, i - left_subarr_including_pivot_length, comp_metric, seed);
  }
}

/* Finds the median of medians of the accepted array. */
value_and_comp_metric find_median_of_medians(int *arr, int arr_length, int comp_metric, int seed) {
  int num_of_medians, i, medians_index, subarr_length;
  int *medians;
  value_and_comp_metric wrapper, tmp;
  
  num_of_medians = (int) ceil((double) arr_length/seed);
  medians = (int *) malloc(num_of_medians * sizeof(int));
  medians_index = 0;
  
  if (arr_length <= seed) {
    wrapper.value = arr[(int) floor(arr_length/2.0)];
    wrapper.comp_metric = comp_metric;
    return wrapper;
  } 

  for (i = 0; i < arr_length; i+= seed) {
    subarr_length = (arr_length - i < seed ? arr_length - i : seed);

    comp_metric += insort(arr + i, subarr_length);

    medians[medians_index++] = arr[i + (int) floor(subarr_length/2.0)];
  }

  tmp = find_median_of_medians(medians, num_of_medians, comp_metric, seed);
  free(medians);
  return tmp;
}

/* Sorts the accetped array in place using insertion sort algorithm and returns comparisions metric.
   Note: the accepted array is mutated. */
static int insort(int *arr, int arr_length) {
  int i, j, key;
  int comp_metric;

  comp_metric = 0;
  for (i = 1; i < arr_length; i++) {
    key = arr[i];
    j = i-1;
    while (j > -1 && key < arr[j]) {
      comp_metric++;
      arr[j+1] = arr[j];
      j--;
    }
    if (j > -1) {
      comp_metric++;
    }
    arr[j+1] = key;
  }
  return comp_metric;
}

/* Partitions the accepted array by val and returns it's new index and relevant comparisions metric.
   Note: the accepted array is mutated. */
static value_and_comp_metric partition_by(int *arr, int start, int end, int val) {
  value_and_comp_metric wrapper, tmp;

  tmp = index_of(arr, start, end, val);
  SWAP_INT_BY_PTR(arr + tmp.value, arr + end);

  wrapper = partition(arr, start, end);
  /* wrapper.comp_metric += tmp.comp_metric; */
  return wrapper;
}

static value_and_comp_metric index_of(int *arr, int start, int end, int val) {
  int j;
  int comp_metric = 0;
  value_and_comp_metric wrapper;

  for (j = start; j <= end; j++) {
    comp_metric++;
    if(arr[j] == val) {
      wrapper.value = j;
      wrapper.comp_metric = comp_metric;
      return wrapper;
    }
  }

  wrapper.value = -1;
  wrapper.comp_metric = comp_metric;
  return wrapper;
}


static void print_arr(int *arr, int arr_length) {
  int j;
  for(j = 0; j < arr_length; j++) {
    printf("%d ", arr[j]);
  }
  printf("\n");
}

static void report_comp_metric(int comp_metric) {
  printf("number of comparisons: %d\n", comp_metric);
}
