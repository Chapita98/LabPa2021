OBJETOS = A.o B.o C.o main.o

HEADERS = A.h B.h C.h

CC = g++
OPCIONES = -c -Wall

all: DependenciaCircular

DependenciaCircular: $(OBJETOS)
	$(CC) $(OBJETOS) -o DependenciaCircular

main.o: main.cpp Makefile $(HEADERS)
	$(CC) $(OPCIONES) main.cpp

A.o: A.cpp $(HEADERS)
	$(CC) $(OPCIONES) A.cpp
	
B.o: B.cpp $(HEADERS)
	$(CC) $(OPCIONES) B.cpp

C.o: C.cpp $(HEADERS)
	$(CC) $(OPCIONES) C.cpp

.PHONY: clean
clean:
	rm -rf *o DependenciaCircular

rebuild:
	make clean
	make



