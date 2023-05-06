#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SWAP(a, b) int temp = a; a = b; b = temp;

int partition(int arr[], int begin, int end) {
  int pivot = arr[end];
  int j = begin;

  for (int i = begin; i < end; i++) {
    if (arr[i] <= pivot) {
      SWAP(arr[i], arr[j]);
      j++;
    }
  }

  SWAP(arr[j], arr[end]);
  return j;
}

int quickSelect(int arr[], int begin, int end, int k) {
  if (begin == end) {
    return arr[begin];
  }

  int index = partition(arr, begin, end);

  if (k == index) {
    return arr[k];
  } else if (k < index) {
    return quickSelect(arr, begin, index - 1, k);
  } else {
    return quickSelect(arr, index + 1, end, k);
  }
}

int main(int argc, char *argv[]) {
  int n = 0;
  int *arr = NULL;
  char buffer[1024];

  int k = atoi(argv[2]);
  while (fgets(buffer, 100, stdin)) {
    if (buffer[0] == '\n') {
        break;
    }
    int valor = atoi(buffer);
    n++; 
    arr = (int*) realloc(arr, n * sizeof(int)); 
    arr[n-1] = valor;
  }

  printf("%d", quickSelect(arr, 0, n - 1, k - 1));

  free(arr);

  return 0;
}