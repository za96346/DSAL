# Makefile

CC = gcc
CFLAGS = -Wall -Wextra -g
OBJ = linkList.o index.o
TARGET = program

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

linkList.o: linkList.c linkList.h
	$(CC) $(CFLAGS) -c linkList.c -o linkList.o

index.o: index.c linkList.h
	$(CC) $(CFLAGS) -c index.c -o index.o

clean:
	rm -f $(OBJ) $(TARGET)
