CC = gcc
CFLAGS = -O2
TARGET = main_multilevel.out
SRC = main_multilevel.c queue.c
HEADERS = queue.h

all: $(TARGET)

$(TARGET): $(SRC) $(HEADERS)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all run clean