CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: main.o
	$(CC) *.o -o messenger
main.o: main.cpp
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f *.o messenger
