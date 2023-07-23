CC = g++
CFLAGS = -Wall -Wextra -Werror

all: build/main.o
	$(CC) $(CFLAGS) build/*.o -o bin/messenger
clean:
	rm -f build/* bin/*
build/main.o: src/main.cpp
	$(CC) $(CFLAGS) -c $< -o $@
