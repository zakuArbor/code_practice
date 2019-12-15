#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

/*
* Print all elements in the array
* @param arr: arr is an array of integers
* @param n: the size of the array
*/
void print_arr(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/*
* Sort the array using bubble sort method
*
* Complexity: O(n^2)
*
* @param arr: arr is an array of integers
* @param n: the size of the array
* @return: returns a new sorted array
*/
int *bubble_sort(int *arr, int n) {
    if (arr) {    
        int temp;
        int is_swapped = TRUE;
        while (is_swapped) {
            is_swapped = FALSE;
            for (int i = 1; i < n; i++) {
                if (arr[i-1] > arr[i]) {
                    temp = arr[i-1];
                    arr[i-1] = arr[i];
                    arr[i] = temp;
                    is_swapped = TRUE;
                }
            }
        }
    }
    return arr;
}

int main () {
    int n = 10;
    int *arr = malloc(n * sizeof(int));
    srand(time(0)); 
  
    for(int i = 0; i<n; i++) {
        arr[i] = rand() % 20;
    }

    printf("==Before Sorting==\n");
    print_arr(arr, n);
    printf("\n");

    //START Bubble SORT
    arr = bubble_sort(arr, n);
    printf("==After Sorting==\n");
    print_arr(arr, n);
    printf("\n");

    free(arr);

    return 0;
}