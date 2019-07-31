#include <stdio.h>

void printTestHeader(int *test_num, char *name) {
	(*test_num)++;
	printf("**********\n");
	printf("Test Case %d: %s\n", *test_num, name);
	printf("----------\n");
}

int assert(LL *expected, LL *result) {
	LL *exp = expected;
	LL *res = result;
	while (expected && result) {
		if (expected->head != result->head) {
			printf("Expected: %d\nGot: %d\n", exp->head, res->head);
			return(1);
		}
	}
	if (exp != res) {
		printf("Length Mismatch\n");
		return(1);
	}
	printf("PASS\n");
	return(0);
}

int check_result(int *list, int size, LL *result) {
	printLL(result);
	LL *res = result;
	int i = 0;
	while (i < size && res) {
		if (res->head != list[i]) {
			printf("Expected: %d\nGot: %d\n", list[i], res->head);
		}
		i++;
		res = res->next;
	}
	if (res || i != size) {
		printf("Length Mismatch\n");
		printf("%d\n", i);
                return(1);
	}
	printf("PASS\n");
        return(0);
}

int test_result(int i, LL *ll) {
	if (ll && ll->head == i) {
		printf("Pass\n");
		return(0);
	}
	printf("Fail\n");
	return(1);
}
