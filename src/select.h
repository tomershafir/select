#ifndef _SELECT_H
#define _SELECT_H

/* Finds the ith smallest element in the accepted array and returns it and reports comparisions metric.
   Note: the accepted array is mutated. */
int randomized_select(int *arr, int arr_length, int i);

/* Finds the ith smallest element in the accepted array and returns it and reports comparisions metric.
   Note: the accepted array is mutated. */
int median_select_by_5(int *arr, int arr_length, int i);

/* Finds the ith smallest element in the accepted array and returns it and reports comparisions metric.
   Note: the accepted array is mutated. */
int median_select_by_7(int *arr, int arr_length, int i);
#endif
