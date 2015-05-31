
CC = g++

CFLAGS = -Wall -g

TARGETS = run

OBJS = optimize-bst.o


LIBPATH = -I./include -L.
LIB = -lnetsnmp

all: $(TARGETS)

$(TARGETS): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^  $(LIBPATH) $(LIB)
	$(RM) $(OBJS)
clean:
	rm -f $(OBJS) $(TARGETS)
