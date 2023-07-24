CC = g++
CFLAGS = -Wall -Wextra -Werror

all: build/main.o build/user.o build/server.o build/chat.o
	$(CC) $(CFLAGS) build/*.o -o bin/messenger
clean:
	rm -f build/* bin/*
build/main.o: src/main.cpp
	$(CC) $(CFLAGS) -c $< -o $@
build/user.o: src/user.cpp
	$(CC) $(CFLAGS) -c $< -o $@
build/server.o: src/server.cpp
	$(CC) $(CFLAGS) -c $< -o $@
build/chat.o: src/chat.cpp
	$(CC) $(CFLAGS) -c $< -o $@