#include <stdlib.h>
#include <stdio.h>
#include "ll.h"
#include "test.h"

int main () {
	int list[10];
	int size = 0; //size of the array that is initialized with the right test values	
	int test_num = 0;
	int search_num = 0; //the number to search
	LL *ll = NULL;
	LL *result = NULL;

	printTestHeader(&test_num, "Empty LinkedList");
	ll = createLL(list, 0);
	if ((result = search(ll, 5))) {
		printf("Fail\n");
	}

	printTestHeader(&test_num, "Search head");
	size = 5;
	for (int i = 0; i < size; i++) {
		list[i] = i;
	}
	search_num = 0;
	ll = createLL(list, size);
	result = search(ll, search_num);
	test_result(search_num, result);

	printTestHeader(&test_num, "Search middle");
	search_num = 2;
	ll = createLL(list, size);
        result = search(ll, search_num);
        test_result(search_num, result);
	
	printTestHeader(&test_num, "Search Tail");
	search_num = 4;
        ll = createLL(list, size);
        result = search(ll, search_num);
        test_result(search_num, result);

	return 0;
}
