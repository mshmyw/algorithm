#file name : makefile
#created at: Mon Jun  8 08:55:16 2015
#author:  root

CXXFLAGS = -g
CC = g++
# CFLAGS = -g
# CC = gcc

TARGETS = run
# OBJS = num-seq-sum-zero.o
# OBJS = dfs-binary-tree.o
# OBJS = permutations.o
# OBJS = 2013-1.o
# OBJS = unique-sample.o
# OBJS = regular-match.o
# OBJS = answer-score.o
# OBJS = word-maze.o
# OBJS = fibonacci.o
# OBJS = combinate-sum-2.o
OBJS = stl-list.o
# OBJS = sub-array-sum.o
# OBJS = symbol-trangles.o
# OBJS = buy-book-greed-failed.o

all: $(TARGETS)

$(TARGETS): $(OBJS)
	$(CC) -o $@ $^
	$(RM) $(OBJS)
	@for i in {1..2}; do echo "i" $$i; ./run; done
	@$(RM) $(TARGETS)
clean:
	$(RM) $(OBJS) $(TARGETS)
