
CC = gcc

CFLAGS = -Wall -g

TARGETS = run

# OBJS=get-route-table.o msh_ipRouteTable.o \
# topology-discovery.o topology-queue.o
# OBJS = str-zip.o
# OBJS = young-table.o
# OBJS = odd-even-classify.o
# OBJS = perfect-shuffle.o
OBJS = get-common-item-from-two-set.o
LIBPATH = -I./include -L.
LIB = -lnetsnmp

all: $(TARGETS)

$(TARGETS): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^  $(LIBPATH) $(LIB)
	$(RM) $(OBJS)
clean:
	rm -f $(OBJS) $(TARGETS)
