#file name : makefile
#created at: Mon Jun  8 08:55:16 2015
#author:  root
CFLAGS = -g
CC = gcc

# CXXFLAGS = -g
# CC = g++

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
# OBJS = permutations.o
# OBJS = merge-lists.o
# OBJS = matrix-clockwise.o
# OBJS = verify-sequence-bst.o
# OBJS = k-min-item.o
# OBJS = last-num-in-circle.o
# OBJS = nine-nums.o
# OBJS = prime-circle.o
# OBJS = huo-na-law.o
# OBJS = maze-path.o
OBJS = rebuild-tree.o

all: $(TARGETS)

$(TARGETS): $(OBJS)
	$(CC) -o $@ $^
	$(RM) $(OBJS)
	@for i in {1..1}; do echo "i" $$i; ./run; done #make the program run 100 times
#	@./run
	@$(RM) $(TARGETS)
clean:
	$(RM) $(OBJS) $(TARGETS)
