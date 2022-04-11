CPP = g++
AR = ar
STRIP = strip
LDFLAGS = -static

.PHONY: all

all: gettype

gettype: libfmt.a
	$(CPP) gettype.cpp -o gettype $^ $(LDFLAGS)
	$(STRIP) gettype

libfmt.a:
	$(CPP) -c format.cpp
	$(CPP) -c getfmt.cpp
	$(AR) rcs libfmt.a format.o getfmt.o

clean:
	rm gettype
	rm *.o
	rm *.a