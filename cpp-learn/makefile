#file name : makefile<c-learn>
#created at: Tue Jun  9 11:33:09 2015
#author:  root

CXXFLAGS = -g
CC = g++
# CFLAGS = -g
# CC = gcc

TARGETS = run

# OBJS = c-func-value.o
# OBJS = square.o
# OBJS = fun-out.o
# OBJS = verify-sequence-bst.o
# OBJS = fork-print.o
# OBJS = virtual-destruct.o
# OBJS = map-erase.o
OBJS = sub-array-sum.o

all: $(TARGETS)

$(TARGETS): $(OBJS)
	$(CC) -o $@ $^
	$(RM) $(OBJS)
	for i in {1..3}; do echo "i" $$i; ./run; done #make the program run 100 times
	@$(RM) $(TARGETS)
clean:
	$(RM) $(OBJS) $(TARGETS)
