#file name : makefile
#created at: Mon Jun  8 08:55:16 2015
#author:  msh

CFLAGS = -g
CC = gcc

TARGETS = run
# OBJS = union-quick-find.o
# OBJS = quick-union-find.o
OBJS = weighted-quick-union-find.o

all: $(TARGETS)

$(TARGETS): $(OBJS)
	$(CC) -o $@ $^
	$(RM) $(OBJS)

clean:
	$(RM) $(OBJS) $(TARGETS)
