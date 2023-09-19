LDFLAGS = -Wall -std=c99 -Wno-write-strings
PROGS    = cliModbus
CC = gcc

#pour compiler librairie modbus 
LIBMODBUS = modbus.o
MODBUSSRC = modbus.c


libmodbus: $(LIBMODBUS)
$(LIBMODBUS): $(MODBUSSRC)
	$(CC) $(MODBUSSRC)  $(LDFLAGS) -static $(LDLIBS) -c -lm
	ar -q libmodbus.a modbus.o

OBJS = cliModbus_suj.o 
SRC = cliModbus_suj.c 

#main elev lib ubuntu18
all: $(PROGS)
$(PROGS): $(OBJS)
	$(CC) $(LDFLAGS) $(LDLIBS) -o $@ $(SRC) -L. -lmodbus -lm

clean:
	rm -f $(PROGS) $(OBJS) core
