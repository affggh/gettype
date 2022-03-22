CPP = g++
STRIP = strip

.PHONY: all

all:
	$(CPP) gettype.cpp -o gettype -static
	$(STRIP) gettype

clean:
	rm gettype