GXX=g++
CXXFLAGS=-Wall -std=c++11
DEL=del

.PHONY: all clean

all: main.exe 


%.o : %.cpp
	$(GXX) -g $(CXXFLAGS)  -c $*.cpp  
	

	
main.exe : main.o arbre.o noeud.o
	$(GXX) -g $(CXXFLAGS)  -o $@ $^

	
	
clean:
	$(DEL) *.o main.exe
