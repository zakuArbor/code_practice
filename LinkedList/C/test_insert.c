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
	int insert_num = 0; //the number to insert
	LL *ll = NULL;
	LL *expected = NULL;

	printTestHeader(&test_num, "Empty LinkedList: Insert a node");
	insert_num = 5;
	ll = createLL(list, 0);
	testInsert(ll, insert_num);
	
	printTestHeader(&test_num, "Insert a node before the head");
	size = 6;
	for (int i = 1; i < size; i++) {
		list[i] = i;
	}
	insert_num = 0;
	ll = createLL(&(list[1]), size - 1); //size - 1 to not include the first element (i.e. head)
	expected = createLL(list, size);
	insert(&ll, insert_num);
	assert(expected, ll);
	
	printTestHeader(&test_num, "Insert in the middle");
	printf("Linked List before insertion: ");
	size = 4;
	list[0] = 0;
	list[1] = 1;
	list[2] = 3;
	list[3] = 4;
	insert_num = 2;
	ll = createLL(list, size);
	printLL(ll);
        testInsert(ll, insert_num);
	
	printTestHeader(&test_num, "Add Tail");
	insert_num = 5;
        ll = createLL(list, size);
        testInsert(ll, insert_num);

	return 0;
}
