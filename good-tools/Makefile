#
# Warning: you may need more libraries than are included here on the
# build line.  The agent frequently needs various libraries in order
# to compile pieces of it, but is OS dependent and we can't list all
# the combinations here.  Instead, look at the libraries that were
# used when linking the snmpd master agent and copy those to this
# file.
#

CC=gcc

#make can auto know the *.c file, here we just change the OBJS1
OBJS1=icmp-flood-ok.o
OBJS2=syn-flood.o
OBJS3=udp-flood.o
OBJS4=rurf-flood-ok.o
OBJS5=papasmurf-good.o
OBJS6=fraggle.o
OBJS = $(OBJS1) $(OBJS2) $(OBJS3) $(OBJS4) $(OBJS5) $(OBJS6)

#here also should be changed with your purpose for target 
TARGETS=run-icmp run-syn run-udp run-rurf run-papasmurf run-fraggle

BUILDLIBS=`net-snmp-config --libs`

all: $(TARGETS)

# $(TARGETS): $(OBJS)
# 	$(CC) -o $(TARGETS) $(OBJS)
run-icmp: $(OBJS1)
	$(CC) -o run-icmp $(OBJS1)

run-syn: $(OBJS2)
	$(CC) -o run-syn $(OBJS2)

run-udp: $(OBJS3)
	$(CC) -o run-udp $(OBJS3)

run-rurf: $(OBJS4)
	$(CC) -o run-rurf $(OBJS4)

run-papasmurf: $(OBJS5)
	$(CC) -o run-papasmurf $(OBJS5)

run-fraggle: $(OBJS6)
	$(CC) -o run-fraggle $(OBJS6)
clean:
	rm $(OBJS) $(TARGETS)
