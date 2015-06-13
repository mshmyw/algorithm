#file name : makefile
#created at: Mon Jun  8 08:55:16 2015
#author:  msh

CXXFLAGS = -g
CC = g++

TARGETS = run
# OBJS = union-quick-find.o
# OBJS = quick-union-find.o
OBJS = trie-tree.o

all: $(TARGETS)

$(TARGETS): $(OBJS)
	$(CC) -o $@ $^
	$(RM) $(OBJS)

clean:
	$(RM) $(OBJS) $(TARGETS)
