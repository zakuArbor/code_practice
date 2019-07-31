#include <stdlib.h>
#include <stdio.h>
#include "ll.h"
#include "test.h"

int main () {
	int list[10];
	int size = 0; //size of the array that is initialized with the right test values	
	int test_num = 0;

	printTestHeader(&test_num, "Empty LinkedList");
	LL *result = createLL(list, 0);
	assert(NULL, result);
	if (result)
		free(result);

	printTestHeader(&test_num, "Length 5 LinkedList");
	size = 5;
	for (int i = 0; i < size; i++) {
		list[i] = i;
	}
	result = createLL(list, size);
	check_result(list, size, result);
	freeLL(result);		
		
	return 0;
}
