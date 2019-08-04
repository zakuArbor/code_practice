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
	int data;
	struct LinkedList *next;
};

typedef struct LinkedList LL;

LL* createLL(int *lst, int size) {
	LL *data = NULL;
	LL *curr = NULL;
	LL *prev = NULL;
	for (int i = 0; i < size; i++) {
		printf("Creating node: %d\n", lst[i]);
		curr = malloc(sizeof(LL));
	        if (!curr) {
                	perror("Failed to alloc memory\n");
        	        exit(1);
	        }
		if (!data) {
			data = curr;
			prev = data;
		} else {
			prev->next = curr;
			prev = curr;
		}
		curr->data = lst[i];
		curr = curr->next;
	}
	if (prev) {
		prev->next = NULL;
	}
	return(data);
}

void freeLL(LL *ll) {
	LL *tmp;
	while (ll) {
		tmp = ll->next;
		free (ll);
		ll = tmp;	
	}
}

void printLL(LL *ll) {
	LL *curr = ll;
	while (curr) {
		printf("%d", curr->data);
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
		if (curr->data == i) {
			break;
		}
		curr = curr->next;
	}
	return(curr);
}

void delete(LL **ll, int i) {
	if (*ll) {
		LL **node_indirect = ll;
		while (*node_indirect && (*node_indirect)->data != i) {
			node_indirect = &((*node_indirect)->next);
		}
		LL *tmp = (*node_indirect)->next;
		if (*node_indirect) {
			printf("trying to delete: %d\n", (*node_indirect)->data);
			*node_indirect = tmp;	
			free(*node_indirect);
			//printf("replaced with: %d\n", node->data);
			printLL(*ll);
		}
	}
}

void insert(LL *ll, int i) {
	LL *node = ll;
	while (node && node->data > i) {
		node = node->next;
	}
	LL *tmp = node;
	if (!(node = malloc(sizeof(LL)))) {
		perror("Failed to alloc memory\n");
	}
	node->data = i;
	node->next = tmp;
}
#endif
