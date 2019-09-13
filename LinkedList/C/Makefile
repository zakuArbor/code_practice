CC = gcc
CFLAGS += -std=gnu11 -Wall -Werror -g3 -O3 -DNDEBUG
LDFLAGS += -lm

all:test_search test_delete test_create test_insert

test_search: test_search.o
	$(CC) $^ -o $@ $(LDFLAGS)

test_delete: test_delete.o
	$(CC) $^ -o $@ $(LDFLAGS)

test_create: test_create.o
	$(CC) $^ -o $@ $(LDFLAGS)

test_insert: test_insert.o
	$(CC) $^ -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o test_search test_delete test_create test_insert
