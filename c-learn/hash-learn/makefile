#file name : makefile<c-learn>
#created at: Tue Jun  9 11:33:09 2015
#author:  root
# CXXFLAGS = -g
CFLAGS = -g
CC = g++

TARGETS = run
# OBJS = c-func-value.o
# OBJS = square.o
OBJS = two-sum.o

all: $(TARGETS)

$(TARGETS): $(OBJS)
	$(CC) -o $@ $^
	$(RM) $(OBJS)
	./run
	@$(RM) $(TARGETS)
clean:
	$(RM) $(OBJS) $(TARGETS)
