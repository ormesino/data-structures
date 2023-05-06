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
  char input[1024];

  fgets(input, sizeof(input), stdin);

  char *token = strtok(input, " ");
  while (token != NULL) {
    n++; 
    arr = (int*) realloc(arr, n * sizeof(int));
    arr[n-1] = strtol(token, NULL, 10);
    token = strtok(NULL, " ");
  }

  int k = atoi(argv[2]);

  printf("O %d menor número da lista é: %d\n", k, quickSelect(arr, 0, n - 1, k - 1));

  free(arr);

  return 0;
}