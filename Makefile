# File:         Makefile
# Maintainer:   Shintaro Kaneko <kaneshin0120@gmail.com>
# Last Change:  28-Mar-2013.

CC = clang
CFLAGS = -Wall -O3
PROGS = cat

all: $(PROGS)

cat: cat.c concatenate.o
	$(CC) $(CFLAGS) $^ -o $@

concatenate.o: concatenate.c
	$(CC) -c $< -o $@

# post-processor
clean:
	rm -vf *.o

purge:
	rm -vf *.o $(PROGS)
