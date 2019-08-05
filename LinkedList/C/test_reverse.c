#include <stdlib.h>
#include <stdio.h>
#include "ll.h"
#include "test.h"

int testInsert(LL *ll, int insert_num) {
	insert(&ll, insert_num);
	#ifdef VERBOSE
	printLL(ll);
	#endif
	if (!search(ll, insert_num)) {
                printf("Fail\n");
		return(1);
        }
        printf("Pass\n");
	return(0);
}

int main () {
	int list[10];
	int size = 0; //size of the array that is initialized with the right test values	
	int test_num = 0;
	LL *ll = NULL;
	LL *expected = NULL;

	printTestHeader(&test_num, "Reverse Empty LinkedList");
	ll = createLL(list, 0);
	if (!(reverse_list(ll))) {
		printf("Pass\n");
	}
	else {
		printf("Fail\n");
	}
	
	printTestHeader(&test_num, "Reverse One node");
	size = 1;
	for (int i = 0; i < size; i++) {
		list[i] = i;
	}
	ll = createLL(list, size);
	expected = createLL(list, size);
	ll = reverse_list(ll);
	assert(expected, ll);
	
	printTestHeader(&test_num, "Reverse 3 nodes linked list");
	printf("Linked List before insertion: ");
	size = 3;
	list[0] = 0;
	list[1] = 1;
	list[2] = 2;
	ll = createLL(list, size);
	if (expected) {
		free(expected);
	}
	list[0] = 2;
	list[1] = 1;
	list[2] = 0;
	ll = reverse_list(ll);
	expected = createLL(list, size);
	printf("After: ");
	printLL(ll);
	assert(expected, ll);
	return 0;
}
