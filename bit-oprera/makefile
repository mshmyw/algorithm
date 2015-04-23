CC = gcc
OBJS = bit-opera.o
TARGETS = run-bit

all: $(TARGETS)
$(TARGETS): $(OBJS)
	$(CC) -o $(TARGETS) $(OBJS)

clean:
	rm $(OBJS) $(TARGETS)
