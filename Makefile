CC = g++
OPCIONES = -std=c++11 -g -Wall -Werror

DEPENDENCIAS = definiciones.h \
Arribo.h Barco.h BarcoPasajeros.h BarcoPesquero.h Puerto.h \
DtArribo.h DtBarco.h DtBarcoPasajeros.h DtBarcoPesquero.h DtPuerto.h DtFecha.h

OBJETOS = main.o metodos.o \
Arribo.o Barco.o BarcoPasajeros.o BarcoPesquero.o Puerto.o \
DtArribo.o DtBarco.o DtBarcoPasajeros.o DtBarcoPesquero.o DtPuerto.o DtFecha.o

// En proceso

clean:
	rm -f $(OBJETOS) main

rebuild:
	make clean
	make



