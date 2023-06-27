#include "sort.h"

void swap_ints(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void bubble_sort(int *array, size_t size) {
  size_t i, len = size;
  bool swapped = true;

  while (swapped) {
    swapped = false;
    for (i = 0; i < len - 1; i++) {
      if (array[i] > array[i + 1]) {
        swap_ints(array + i, array + i + 1);
        swapped = true;
      }
    }
    len--;
  }
}

