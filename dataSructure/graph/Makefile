# Makefile

CC = gcc
CFLAGS = -Wall -Wextra -g
OBJ = graph.o index.o
TARGET = program

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

graph.o: graph.c graph.h
	$(CC) $(CFLAGS) -c graph.c -o graph.o

index.o: index.c graph.h
	$(CC) $(CFLAGS) -c index.c -o index.o

clean:
	rm -f $(OBJ) $(TARGET)
