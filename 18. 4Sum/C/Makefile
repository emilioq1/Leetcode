CC = gcc

CFLAGS = -std=gnu11 -O2 -fsanitize=address -fno-omit-frame-pointer -g -lm
#\ -Wall -Wextra -Werror

TARGET = main
MAIN_SRC = main.c helper/*
BLIND_SRCS = blind_attempt.c
BEST_SRCS = best_solution.c

all: blind

blind:
	$(CC) $(CFLAGS) $(MAIN_SRC) $(BLIND_SRCS)

best:
	$(CC) $(CFLAGS) $(MAIN_SRC) $(BEST_SRCS)

clean:
	rm -f *.out

.PHONY: all clean
