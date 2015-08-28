# CC = gcc
# OBJS = bit-opera.o

CC = g++
CXXFLAGS = -g

# OBJS = bit-opera.o
OBJS = data-bit.o

TARGETS = run-bit

all: $(TARGETS)
$(TARGETS): $(OBJS)
	$(CC) -o $(TARGETS) $(OBJS)
	./run-bit
	rm $(OBJS) $(TARGETS)
clean:
	rm $(OBJS) $(TARGETS)
