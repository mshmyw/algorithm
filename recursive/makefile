#file name : makefile
#created at: Mon Jun  8 08:55:16 2015
#author:  root

CFLAGS = -g
CC = gcc
TARGETS = run
# OBJS = num-seq-sum-zero.o
# OBJS = dfs-binary-tree.o
# OBJS = permutations.o
# OBJS = 2013-1.o
# OBJS = unique-sample.o
# OBJS = regular-match.o
# OBJS = answer-score.o
OBJS = word-maze.o

all: $(TARGETS)

$(TARGETS): $(OBJS)
	$(CC) -o $@ $^
	$(RM) $(OBJS)
	./run
	@$(RM) $(TARGETS)
clean:
	$(RM) $(OBJS) $(TARGETS)
