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
# OBJS = min-money-make-change-ok.o
OBJS = push-water.o

LIB = -lm

all: $(TARGETS)

$(TARGETS): $(OBJS)
	$(CC) -o $@ $^ $(LIB)
	$(RM) $(OBJS)
	@for i in {1..10}; do echo "i=>" $$i; ./run; done #run program 100 times
	@$(RM) $(TARGETS)
clean:
	rm -f $(OBJS) $(TARGETS)
