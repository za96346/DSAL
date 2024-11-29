# Makefile

CC = gcc
CFLAGS = -Wall -Wextra -g
OBJ = tree.o index.o
TARGET = program

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

tree.o: tree.c tree.h
	$(CC) $(CFLAGS) -c tree.c -o tree.o

index.o: index.c tree.h
	$(CC) $(CFLAGS) -c index.c -o index.o

clean:
	rm -f $(OBJ) $(TARGET)
