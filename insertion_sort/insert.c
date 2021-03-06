#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_arr(int *arr, int len) {
  int num = 0;
  for (int i = 0; i < len; i++) {
    printf("%d ", arr[i]);
    
    if (num == 10) { //% is expensive compared to adding
      printf("\n");
      num = 0;
    }
    num++;
  }
  printf("\n");
}

int is_ordered(int *arr, int *expected, int len) {
  for (int i = 0; i < len; i++) {
    if (arr[i] != expected[i]) {
      return 0;
    }
  }
  return 1;
}

int compare(const void *p1, const void *p2) {
  int *x = (int *)p1;
  int *y = (int *)p2;
  return *x - *y;
}

void insertion_sort(int *arr, int len) {
  for (int curr = 0; curr < len; curr++) {
    int i = curr;
    while (i > 0 && arr[i-1] > arr[i]) {
      //swap
      int tmp = arr[i-1];
      arr[i-1] = arr[i];
      arr[i] = tmp;
      i -= 1;
    }
  }
}

int main() {
  int arr[100];
  int expected[100];
  srand(time(NULL));
  
  int len = rand() % 100; //want to compare a random length of integers

  //set random values to the array
  for (int i = 0; i < len; i++) {
    int num = rand()%10;
    arr[i] = num;
    expected[i] = num; 
  }

  insertion_sort(arr, len);

  printf("==========\n");
  printf("Got:\n");
  printf("==========\n");
  print_arr(arr, len);
  qsort((void *)expected, len, sizeof(int), compare);

  printf("==========\n");
        printf("Expected:\n");
        printf("==========\n");
  print_arr(expected, len);

  if (!is_ordered(arr, expected, len)) {
    fprintf(stderr, "Error: Array is not sorted\n");
  }
  return 0;
}
