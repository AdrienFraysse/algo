GXX=g++
CXXFLAGS=-Wall -std=c++11
DEL=del

.PHONY: all clean

all: main.exe 

main.o : main.cpp
	$(GXX) -g $(CXXFLAGS)  -c main.cpp  
	
main.exe : main.o
	$(GXX) -g $(CXXFLAGS)  -o main.exe main.o 

	
	
clean:
	$(DEL) *.o main.exe
