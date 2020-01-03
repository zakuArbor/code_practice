#include <stdlib.h>
#include <stdio.h>

struct table {
	int size;
	struct entry **buckets;
};

struct entry {
	int key;
	int value;
	struct entry *next;
};

void print_bucket(struct entry *entry) {
	if (entry) {
		printf("\t%d-%d\n", entry->key, entry->value);
		print_bucket(entry->next);
	}
}
void print_table(struct table *table) {
	if (!table) {
		return;
	}
	for (int i = 0; i < table->size; i++) {
		printf("-> bucket %d:\n", i);
		print_bucket(table->buckets[i]);
	}
}

/*
* Create a table
* 
* Note: there will be n buckets allocated but there are no entries
*
* @param size: an integer representing the number of buckets there are in the hashtable
* @return: a hash table
*/
struct table *create_table(int size) {
	struct table *table = NULL;
	if (!(table = malloc(sizeof(struct table*)))) {
		return NULL;
	}

	table->size = size;
	
	if (!(table->buckets = malloc(size * sizeof(struct entry *)))) {
		free(table);
		return NULL;
	}
	for (int i = 0; i < size; i++) {
		table->buckets[i] = NULL;
	}
	return table;
}

/*
* Delete the bucket and all of the entries in the collision chain
*
* @param curr: the bucket pointer
*/
void destroy_bucket(struct entry *curr) {
	if (curr) {
		destroy_bucket(curr->next);
		free(curr);
	}
}

/*
* Delete the table along with its buckets
*
* @param table: the table pointer
*/
void destroy_table(struct table *table) {
	if (!table) {
		return;
	}
	for (int i = 0; i < table->size; i++) {
		destroy_bucket(table->buckets[i]);
	}
	free(table);
}

int hash(int key, int size) {
	return key % size;
}


struct entry **get_bucket_ptr(struct table *table, int key) {
	return &(table->buckets[hash(key, table->size)]);
}

/*
* Given a table and key, return the bucket the hash function returns
*
* @param table: a struct that represents the hashtable
* @param key: an integer value that represents a key
* @return: return the bucket where the key may be found
*/
struct entry *get_bucket(struct table *table, int key) {
	struct entry **ptr = get_bucket_ptr(table, key);
	if (ptr && *ptr) {
		return *ptr;
	}
	return NULL;
}


/*
* Return the value of the key if exists. Else, return -1
*
* Note: The implementation assumes that the values stored in the hashtable are >= 0
*
* @param table: a struct that represents the hashtable
* @param key: an integer value that represents a key
* @return: return the value of the key if key exists. Else return -1
*/
int find(struct table *table, int key) {
	if (!table) {
		return -1;
	}
    
    int val = -1; //default value

	struct entry *entry = get_bucket(table, key);

	if (!entry) {
		return -1;
	}
	while (entry) {
		if (entry->key == key) {
			val = entry->value;
			break;
		}
		entry = entry->next;
	}
	return val;
}

/*
* Insert the key-value pair to the hashtable. If key exists, update the value
*
* @param table: a struct that represents the hashtable
* @param key: an integer value that represents a key
* @return: return 0 if insert is successful. Else return -1
*/
int insert_entry(struct table *table, int key, int value) {
	if (!table) {
		return 0;
	}
	struct entry **curr;
	curr = get_bucket_ptr(table, key);
	
	while (*curr) {
		if ((*curr)->key == key) {
			(*curr)->value = value;
			return 0;
		}
		curr = &((*curr)->next);
	}
	
	if (!(*curr = malloc(sizeof(struct entry*)))) {
		return -1;
	}
	
	(*curr)->key = key;
	(*curr)->value = value;
	(*curr)->next = NULL;
	
	return 0;
}

/*
* Delete the entry with the given key if exists
*
* @param table: a struct that represents the hashtable
* @param key: an integer value that represents a key
*/
void delete_entry(struct table *table, int key) {
	if (!table) {
		return;
	}

	struct entry **curr = get_bucket_ptr(table, key);
	
	while (*curr && (*curr)->key != key) {
			curr = &(*curr)->next;
	}

	struct entry *tmp = *curr;
	*curr = (*curr)->next;
	free(tmp);
}