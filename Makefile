CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGETS = task1 task2 task3

all: $(TARGETS)

task1: task1.c
	$(CC) $(CFLAGS) -o task1 task1.c

task2: task2.c
	$(CC) $(CFLAGS) -o task2 task2.c

task3: task3.c
	$(CC) $(CFLAGS) -o task3 task3.c

clean:
	rm -f $(TARGETS)

.PHONY: all clean
