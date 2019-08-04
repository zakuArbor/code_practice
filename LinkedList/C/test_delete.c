#include <stdlib.h>
#include <stdio.h>
#include "ll.h"
#include "test.h"

int test_delete(LL *ll, int delete_num) {
	delete(&ll, delete_num);
	printLL(ll);
	if (search(ll, delete_num)) {
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
	int delete_num = 0; //the number to delete
	LL *ll = NULL;

	printTestHeader(&test_num, "Empty LinkedList");
	ll = createLL(list, 0);
	delete(&ll, 5);
	if (ll) {
		printf("Fail\n");
	}
	else {
		printf("Pass\n");
	}

	printTestHeader(&test_num, "Delete head");
	size = 5;
	for (int i = 0; i < size; i++) {
		list[i] = i;
	}
	delete_num = 0;
	ll = createLL(list, size);
	test_delete(ll, delete_num);

	printTestHeader(&test_num, "Delete middle");
	delete_num = 2;
	ll = createLL(list, size);
        test_delete(ll, delete_num);
	
	printTestHeader(&test_num, "Delete Tail");
	delete_num = 4;
        ll = createLL(list, size);
        test_delete(ll, delete_num);

	return 0;
}
