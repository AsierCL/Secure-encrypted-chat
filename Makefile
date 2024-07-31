CC = gcc
TARGET = main
INCLUDEDIR = include
SRCDIR = src

SOURCES := $(wildcard $(SRCDIR)/*.c main.c)
OBJECTS := $(SOURCES:.c=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $^ -o $@ -I$(INCLUDEDIR)

%.o: %.c
	$(CC) -c $< -o $@ -I$(INCLUDEDIR)

clean:
	rm -f $(OBJECTS)

cleanall: clean
	rm -f $(TARGET)
