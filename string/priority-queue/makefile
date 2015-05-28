CC = gcc
CFLAGS = -Wall -g
TARGET = run
OBJS = priority-queue.o \
priority-queue-main.o get-k-min-element.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
	$(RM) $(OBJS)

clean:
	$(RM) $(TARGET)
