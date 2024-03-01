CFLAGS=-Wall -Wextra -pedantic -std=c99 -O3

.PHONY: all run clean

all: run

run: tile
	./tile

clean:
	rm -f tile
