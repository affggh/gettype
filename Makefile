CPP = g++
AR = ar
STRIP = strip
CFLAGS = -O2 -std=c++17
LDFLAGS =

.PHONY: all

all: gettype

gettype: libfmt.a
	@echo "    GEN   gettype"
	@$(CPP) $(CFLAGS) gettype.cpp -o gettype $^ $(LDFLAGS)
	@echo "    STRIP gettype"
	@$(STRIP) gettype

libfmt.a:
	@echo "    CPP   format.o"
	@$(CPP) $(CFLAGS) -c format.cpp
	@echo "    CPP   getfmt.o"
	@$(CPP) $(CFLAGS) -c getfmt.cpp
	@echo "    AR    libfmt.a"
	@$(AR) rcs libfmt.a format.o getfmt.o

clean:
	@rm *.o
	@rm *.a
	@rm gettype