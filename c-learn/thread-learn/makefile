#file name : makefile<c-learn>
#created at: Tue Jun  9 11:33:09 2015
#author:  root
# CXXFLAGS = -g
CFLAGS = -g -lpthread
CC = gcc
TARGETS = run

# OBJS = c-func-value.o
# OBJS = square.o
# OBJS = fun-out.o
# OBJS = verify-sequence-bst.o
# OBJS = fork-print.o
# OBJS = large-open-file.o
# OBJS = sprintf-out.o
# OBJS = thread-create.o
# OBJS = thread-mutex.o
# OBJS = thread-wait.o
OBJS = thread-wait2.o

all: $(TARGETS)

$(TARGETS): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)
	$(RM) $(OBJS)
	for i in {1..3}; do echo "i" $$i; ./run; done #make the program run 100 times
	@$(RM) $(TARGETS)
clean:
	$(RM) $(OBJS) $(TARGETS)
