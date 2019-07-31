//Linked List Header File
#include <stdlib.h>
#include <stdio.h>

#ifndef LL_H
#define LL_H

#if !defined(NULL)
#define NULL 0
#endif

struct LinkedList
{
	int head;
	struct LinkedList *next;
};

typedef struct LinkedList LL;

LL* createLL(int *lst, int size) {
	LL *head = NULL;
	LL *curr = NULL;
	LL *prev = NULL;
	for (int i = 0; i < size; i++) {
		printf("Creating node: %d\n", lst[i]);
		curr = malloc(sizeof(LL));
	        if (!curr) {
                	perror("Failed to alloc memory\n");
        	        exit(1);
	        }
		if (!head) {
			head = curr;
			prev = head;
		} else {
			prev->next = curr;
			prev = curr;
		}
		curr->head = lst[i];
		curr = curr->next;
	}
	if (prev) {
		prev->next = NULL;
	}
	return(head);
}

void printLL(LL *ll) {
	LL *curr = ll;
	while (curr) {
		printf("%d", curr->head);
		if (curr->next) {
			printf(" -> ");
		}
		curr = curr->next;
	}
	printf("\n");
}

LL* search(LL *ll, int i) {
	LL *curr = ll;
	while (curr) {
		if (curr->head == i) {
			break;
		}
		curr = curr->next;
	}
	return(curr);
}

void delete(LL *ll, int i) {
	LL *node = ll;
	while (node && node->head != i) {
		node = node->next;
	}
	LL *tmp = node;
	if (tmp) {
		free(tmp);
	}
	node = node->next;	
}

void insert(LL *ll, int i) {
	LL *node = ll;
	while (node && node->head > i) {
		node = node->next;
	}
	LL *tmp = node;
	if (!(node = malloc(sizeof(LL)))) {
		perror("Failed to alloc memory\n");
	}
	node->head = i;
	node->next = tmp;
}
#endif
