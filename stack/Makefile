# Makefile

CC = gcc
CFLAGS = -Wall -Wextra -g
OBJ = stack.o index.o
TARGET = program

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c -o stack.o

index.o: index.c stack.h
	$(CC) $(CFLAGS) -c index.c -o index.o

clean:
	rm -f $(OBJ) $(TARGET)
