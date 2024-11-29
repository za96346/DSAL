# Makefile

CC = gcc
CFLAGS = -Wall -Wextra -g
OBJ = hashTable.o index.o
TARGET = program

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

hashTable.o: hashTable.c hashTable.h
	$(CC) $(CFLAGS) -c hashTable.c -o hashTable.o

index.o: index.c hashTable.h
	$(CC) $(CFLAGS) -c index.c -o index.o

clean:
	rm -f $(OBJ) $(TARGET)
