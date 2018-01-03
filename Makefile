GXX=g++
CXXFLAGS=-Wall -pedantic -std=c++14
DEL=del

.PHONY: all clean

all: huff.exe 

.o : .cpp
	$(GXX) -g $(CXXFLAGS)  -c .cpp
	
.exe : .o
	$(GXX) -g $(CXXFLAGS)  -c 

	
	
clean:
	$(DEL) *.o 
