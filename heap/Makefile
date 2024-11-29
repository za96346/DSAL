# Makefile

CC = gcc
CFLAGS = -Wall -Wextra -g
OBJ = heap.o index.o
TARGET = program

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

heap.o: heap.c heap.h
	$(CC) $(CFLAGS) -c heap.c -o heap.o

index.o: index.c heap.h
	$(CC) $(CFLAGS) -c index.c -o index.o

clean:
	rm -f $(OBJ) $(TARGET)
