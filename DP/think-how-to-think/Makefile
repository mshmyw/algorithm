CFLAGS = -g # c
CC = gcc
# CXXFLAGS =  -g -DEBUG # c++
# CC = g++

TARGETS = run

 # OBJS = optimize-bst.o
# OBJS = lis-iter.o
# OBJS = longest-increase-subsequence.o
# OBJS = lis-iter-msh.o
# OBJS = str-similar-degree.o
# OBJS = 8-queens.o
# OBJS = rmq.o
# OBJS = lca.o
# OBJS = jump-game.o
# OBJS = stock-II.o
OBJS = unique-bst.o

LIB = -lm

all: $(TARGETS)

$(TARGETS): $(OBJS)
	$(CC) -o $@ $^ $(LIB)
	$(RM) $(OBJS)
	./run
	@$(RM) $(TARGETS)
clean:
	rm -f $(OBJS) $(TARGETS)
