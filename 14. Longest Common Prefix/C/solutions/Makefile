CC = gcc

CFLAGS = -std=gnu11 -O2 -fsanitize=address -fno-omit-frame-pointer -g 
#\ -Wall -Wextra -Werror

TARGET = test
DIVIDE_SRCS = test.c divide_and_conquer.c
BINARY_SRCS = test.c binary_search.c
TRIE_SRCS = test.c trie.c

all: divide binary trie

divide:
	$(CC) $(CFLAGS) $(DIVIDE_SRCS) -o divide.out

binary:
	$(CC) $(CFLAGS) $(BINARY_SRCS) -o binary.out

trie:
	$(CC) $(CFLAGS) $(TRIE_SRCS) -o trie.out

clean:
	rm -f *.out

.PHONY: all clean
