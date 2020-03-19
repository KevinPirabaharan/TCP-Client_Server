all: server client
test: server client client2 client3 client4 client5 client6

CC          =	gcc
# Flags that are sent to the compiler  change the std if you wish
CFLAGS      =	-Wall -std=c99 -pedantic -g -pthread

#add a second target to build a different program with the same library
server: src/server.c
	$(CC) $(CFLAGS) src/server.c -o bin/server

client: src/client.c
	$(CC) $(CFLAGS) src/client.c -o bin/client

client2: src/client.c
	$(CC) $(CFLAGS) src/client.c -o bin/client2

client3: src/client.c
	$(CC) $(CFLAGS) src/client.c -o bin/client3

client4: src/client.c
	$(CC) $(CFLAGS) src/client.c -o bin/client4

client5: src/client.c
	$(CC) $(CFLAGS) src/client.c -o bin/client5

client6: src/client.c
	$(CC) $(CFLAGS) src/client.c -o bin/client6

clean:
	rm -r bin/*
