# Makefile

CC = gcc
CFLAGS = -Wall -Wextra -g
OBJ = queue.o index.o
TARGET = program

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

queue.o: queue.c queue.h
	$(CC) $(CFLAGS) -c queue.c -o queue.o

index.o: index.c queue.h
	$(CC) $(CFLAGS) -c index.c -o index.o

clean:
	rm -f $(OBJ) $(TARGET)
