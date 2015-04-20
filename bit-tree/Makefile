CC=gcc

#make can auto know the *.c file, here we just change the OBJS1
OBJS1 = binary-tree.o stack.o queue.o
# OBJS2=syn-flood.o
# OBJS3=udp-flood.o
# OBJS = $(OBJS1) $(OBJS2) $(OBJS3)

#here also should be changed with your purpose for target 
TARGETS=run-tree

all: $(TARGETS)

# $(TARGETS): $(OBJS)
# 	$(CC) -o $(TARGETS) $(OBJS)

run-tree: $(OBJS1)
	$(CC) -o run-tree $(OBJS1)


clean:
	rm $(OBJS1) $(TARGETS)
