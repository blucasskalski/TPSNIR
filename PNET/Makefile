LDFLAGS = -Wall -std=c99 -Wno-write-strings
PROGS    = cliModbus
PROGS2   = cliModbus_prof
CC = gcc

#pour compiler librairie modbus 
LIBMODBUS = modbus.o
MODBUSSRC = modbus.c


libmodbus: $(LIBMODBUS)
$(LIBMODBUS): $(MODBUSSRC)
	$(CC) $(MODBUSSRC)  $(LDFLAGS) -static $(LDLIBS) -c -lm
	ar -q libmodbus.a modbus.o

OBJS = cliModbus_suj.o 
OBJS2 = cliModbus.o 
SRC = cliModbus_suj.c 
SRC2 = cliModbus.c 

#main elev lib ubuntu22
all: $(PROGS)
$(PROGS): $(OBJS)
	$(CC) $(LDFLAGS) $(LDLIBS) -o $@ $(SRC) -L. -lmodbus -lm

all2: $(PROGS2)
$(PROGS2): $(OBJS2)
	$(CC) $(LDFLAGS) $(LDLIBS) -o $@ $(SRC2) -L. -lmodbus -lm

clean:
	rm -f $(PROGS) $(PROGS2) $(OBJS2) $(OBJS) core
