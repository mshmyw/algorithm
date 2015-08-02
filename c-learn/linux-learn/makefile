#file name : makefile<c-learn>
#created at: Tue Jun  9 11:33:09 2015
#author:  root
# CXXFLAGS = -g
# CFLAGS = -g -lpthread
CFLAGS = -g
CC = gcc
TARGETS = run
TARGET1 = server
TARGET2 = client
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
OBJ፡S = epoll-learn.o
# OBJS = thread-wait2.o
OBJS1 = server.o
OBJS2 = client.o

all: $(TARGETS)
$(TARGETS): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)
	$(RM) $(OBJS)
	for i in {1..3}; do echo "i" $$i; ./run; done #make the program run 100 times
	@$(RM) $(TARGETS)

$(TARGET1): $(OBJS1)
	$(CC) -o $@ $^ $(CFLAGS)
	$(RM) $(OBJS1)
	echo $(IP)
	for i in {1..3}; do echo "i" $$i; ./$(TARGET1); done #make the program run 100 times
	@$(RM) $(TARGET1)

$(TARGET2): $(OBJS2)
	$(CC) -o $@ $^ $(CFLAGS)
	$(RM) $(OBJS2)
	for i in {1..3}; do echo "i" $$i; ./$(TARGET2); done #make the program run 100 times
#	@$(RM) $(TARGET2)

clean:
	$(RM) $(OBJS) $(TARGETS) $(TARGET1) $(TARGET2)
