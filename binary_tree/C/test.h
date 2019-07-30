#include <stdio.h>

void printBorder() {
        printf("======================\n");
}

void printArray(int *array, int size) {
        for (int i = 0; i < size; i++) {
                printf(" %d ", array[i]);
        }
}

void printTestName(int test, char *test_name) {
        printBorder();
        printf("%d. %s: ", test, test_name);
}
