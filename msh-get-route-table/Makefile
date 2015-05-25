
CC = gcc

CFLAGS = -Wall -g

TARGETS=runsnmp

OBJS=get-route-table.o msh_ipRouteTable.o \
topology-discovery.o topology-queue.o

LIBPATH = -I./include -L.
LIB = -lnetsnmp

all: $(TARGETS)

$(TARGETS): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^  $(LIBPATH) $(LIB)
	$(RM) $(OBJS)
clean:
	rm -f $(OBJS) $(TARGETS)
