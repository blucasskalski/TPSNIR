LDFLAGS = -std=c++11 -Wall -Wno-write-strings
PROGS    = progjbus
PROGS2    = jbus2


#pour compiler librairie JBUS
LIBJBUS    = jbus.o
SRC1 = jbus.cpp rs232.cpp 


libjbus: $(LIBJBUS)
$(LIBJBUS): $(SRC1)
	$(CXX) $(SRC1)  $(LDFLAGS) -static $(LDLIBS) -c

LIBRS    = rs232.o
SRC2LIB = rs232.cpp 


#pour compiler librairie RS
librs: $(LIBRS)
$(LIBRS): $(SRC2LIB)
	$(CXX) $(SRC2LIB)  $(LDFLAGS) -static $(LDLIBS) -c


OBJS = main.o 
OBJS2 = main_jb2.o
SRC = main.cpp 
SRC2 = main_jb2.cpp 

#main elev
all: $(PROGS)
$(PROGS): $(OBJS)
	$(CXX) $(SRC)  $(LDFLAGS) -static $(LDLIBS) -o $@ jbus.o rs232.o

#main complet
all2: $(PROGS2)
$(PROGS2): $(OBJS2)
	$(CXX) $(SRC2) $(LDFLAGS) -static $(LDLIBS) -o $@ jbus.o rs232.o


clean:
	rm -f $(PROGS) $(PROGS2) $(OBJS) core
