#include <stdio.h>
#include "hash.h"

void test_delete(struct table *table, int key) {
	int val = 0;
	delete_entry(table, key);
	if ((val = find(table, key)) != -1) {
		printf("FAILED: Delete key %d failed\n", key);
	}
}

int main () {
	int n = 11;
	struct table *table = create_table(n);
	int val = 0;
	
	//enter entries into the hashtable
	for(int i = 0; i < n; i++) {
		insert_entry(table, i, i*2);
	}

	//test if the entries exist in the hashtable
	for (int i = 0; i < n; i++) {
		val = find(table, i);
		if (val != i*2) {
			printf("FAILED: Insert failed at key %d. Expected %d but got %d\n", i, i*2, val);
		}
	}

	/********** UPDATE TEST ***********/
	//test setup
	if ((val = find(table, 1)) == 5) {
		printf("FAILED: Update test setup failed at key %d. Expected %d before test but got %d\n", 1, 5, val);
	}
	insert_entry(table, 1, 5);

	//test update
	if ((val = find(table, 1)) != 5) {
		printf("FAILED: Update failed at key %d. Expected %d but got %d\n", 1, 5, val);
	}
	
	//revert changes assuming update test passed
	insert_entry(table, 1, 2);

	/***** COLLISION CHECK TEST ****/
	for (int i = n; i < 100; i++) {
		insert_entry(table, i, i*2);
	}

	//key 0, 11, 22, 33, 44, 55, 66, 77, 88, 99 should be in bucket 0
	//key 5, 16, 21 ... should be in bucket 5
	for (int i = 0; i < 100; i+= 11) {
		val = find(table, i);
		if (val != i*2) {
			printf("FAILED: Collision failed in bucket %d for key %d. Expected %d but got %d\n", 0, i, i*2, val);
		}
	}

	for (int i = 5; i < 100; i+= 11) {
		val = find(table, i);
		if (val != i*2) {
			printf("FAILED: Collision failed in bucket %d for key %d. Expected %d but got %d\n", 5, i, i*2, val);
		}
	}

	/**** DELETE TEST ****/
	//TEST 1: Delete a head of a bucket
	int key = 0; //the head entry in bucket 0
	test_delete(table, key);
	//TEST 2: Delete some entry in the collision chain
	key = 56; //some entry somewhere in between the head and tail of the bucket 1's collision chain
	test_delete(table, key);
	//TEST 3: Delete a tail entry of a bucket
	key = 98; //tail entry of bucket 10 (98 % 11 == 10)
	test_delete(table, key);
	
	destroy_table(table);

	return 0;
}