OBJETOS = Asignacion.o Asignatura.o AsistenciaDiferida.o AsistenciaOnline.o Clase.o \
Usuario.o Docente.o Estudiante.o Monitoreo.o Practico.o Sistema.o Teorico.o Mensaje.o ISistema.o \
DtFecha.o main.o \
List.o ListIterator.o ListNode.o OrderedDictionary.o OrderedKey.o OrderedDictionaryEntry.o \
ICollectible.o ICollection.o IDictionary.o IIterator.o IKey.o Integer.o String.o 

DEF = ./ICollection/interfaces/ICollectible.h ./ICollection/interfaces/IKey.h ./ICollection/interfaces/IIterator.h ./ICollection/interfaces/ICollection.h ./ICollection/interfaces/IDictionary.h ./ICollection/interfaces/OrderedKey.h ./ICollection/collections/OrderedDictionaryEntry.h ./ICollection/collections/ListNode.h ./ICollection/collections/List.h ./ICollection/collections/ListIterator.h ./ICollection/collections/OrderedDictionary.h ./ICollection/Integer.h ./ICollection/String.h ./classes/headers/Tipo.h ./datatypes/headers/DtFecha.h ./classes/headers/Usuario.h ./classes/headers/Asignacion.h ./classes/headers/AsistenciaDiferida.h ./classes/headers/AsistenciaOnline.h ./classes/headers/Mensaje.h ./classes/headers/Clase.h ./classes/headers/Docente.h ./classes/headers/Practico.h ./classes/headers/Teorico.h ./classes/headers/Monitoreo.h ./classes/headers/Asignatura.h ./classes/headers/Estudiante.h ./classes/headers/ISistema.h ./classes/headers/Sistema.h ./classes/headers/Fabrica.h

CC = g++
OPCIONES = -c -Wall

all: Lab4PA2021

Lab4PA2021: $(OBJETOS)
	$(CC) $(OBJETOS) -o Lab4PA2021

main.o: main.cpp Makefile ./classes/headers/Fabrica.h $( ./classes/headers/)
	$(CC) $(OPCIONES) main.cpp

Practico.o: ./classes/headers/Practico.h ./classes/sources/Practico.cpp
	$(CC) $(OPCIONES) ./classes/sources/Practico.cpp

Teorico.o: ./classes/headers/Teorico.h ./classes/sources/Teorico.cpp
	$(CC) $(OPCIONES) ./classes/sources/Teorico.cpp

Sistema.o: ./classes/headers/Sistema.h ./classes/sources/Sistema.cpp
	$(CC) $(OPCIONES) ./classes/sources/Sistema.cpp

ISistema.o: ./classes/headers/ISistema.h ./classes/sources/ISistema.cpp
	$(CC) $(OPCIONES) ./classes/sources/ISistema.cpp

Docente.o: ./classes/headers/Docente.h ./classes/sources/Docente.cpp
	$(CC) $(OPCIONES) ./classes/sources/Docente.cpp

Usuario.o: ./classes/headers/Usuario.h ./classes/sources/Usuario.cpp
	$(CC) $(OPCIONES) ./classes/sources/Usuario.cpp

Estudiante.o: ./classes/headers/Estudiante.h ./classes/sources/Estudiante.cpp
	$(CC) $(OPCIONES) ./classes/sources/Estudiante.cpp

Monitoreo.o: ./classes/headers/Monitoreo.h ./classes/headers/Estudiante.h ./classes/sources/Monitoreo.cpp
	$(CC) $(OPCIONES) ./classes/sources/Monitoreo.cpp

Asignatura.o: ./classes/headers/Asignatura.h ./classes/sources/Asignatura.cpp
	$(CC) $(OPCIONES) ./classes/sources/Asignatura.cpp

Asignacion.o: ./classes/headers/Asignacion.h ./classes/sources/Asignacion.cpp ./classes/headers/Tipo.h
	$(CC) $(OPCIONES) ./classes/sources/Asignacion.cpp

Clase.o: ./classes/headers/Clase.h ./classes/sources/Clase.cpp
	$(CC) $(OPCIONES) ./classes/sources/Clase.cpp

Mensaje.o: ./classes/headers/Mensaje.h ./classes/sources/Mensaje.cpp
	$(CC) $(OPCIONES) ./classes/sources/Mensaje.cpp

AsistenciaDiferida.o: ./classes/headers/AsistenciaDiferida.h ./classes/sources/AsistenciaDiferida.cpp
	$(CC) $(OPCIONES) ./classes/sources/AsistenciaDiferida.cpp

AsistenciaOnline.o: ./classes/headers/AsistenciaOnline.h ./classes/sources/AsistenciaOnline.cpp
	$(CC) $(OPCIONES) ./classes/sources/AsistenciaOnline.cpp

DtFecha.o: ./datatypes/headers/DtFecha.h ./datatypes/sources/DtFecha.cpp
	$(CC) $(OPCIONES) ./datatypes/sources/DtFecha.cpp

List.o: ./ICollection/collections/List.h ./ICollection/collections/List.cpp
	$(CC) $(OPCIONES) ./ICollection/collections/List.cpp

ListIterator.o: ./ICollection/collections/ListIterator.h ./ICollection/collections/ListIterator.cpp
	$(CC) $(OPCIONES) ./ICollection/collections/ListIterator.cpp

ListNode.o: ./ICollection/collections/ListNode.h ./ICollection/collections/ListNode.cpp
	$(CC) $(OPCIONES) ./ICollection/collections/ListNode.cpp

OrderedDictionary.o: ./ICollection/collections/OrderedDictionary.h ./ICollection/collections/OrderedDictionary.cpp
	$(CC) $(OPCIONES) ./ICollection/collections/OrderedDictionary.cpp

OrderedDictionaryEntry.o: ./ICollection/collections/OrderedDictionaryEntry.h ./ICollection/collections/OrderedDictionaryEntry.cpp
	$(CC) $(OPCIONES) ./ICollection/collections/OrderedDictionaryEntry.cpp

OrderedKey.o: ./ICollection/interfaces/OrderedKey.h ./ICollection/interfaces/OrderedKey.cpp
	$(CC) $(OPCIONES) ./ICollection/interfaces/OrderedKey.cpp

ICollectible.o: ./ICollection/interfaces/ICollectible.h ./ICollection/interfaces/ICollectible.cpp
	$(CC) $(OPCIONES) ./ICollection/interfaces/ICollectible.cpp

ICollection.o: ./ICollection/interfaces/ICollection.h ./ICollection/interfaces/ICollection.cpp
	$(CC) $(OPCIONES) ./ICollection/interfaces/ICollection.cpp

IDictionary.o: ./ICollection/interfaces/IDictionary.h ./ICollection/interfaces/IDictionary.cpp
	$(CC) $(OPCIONES) ./ICollection/interfaces/IDictionary.cpp

IIterator.o: ./ICollection/interfaces/IIterator.h ./ICollection/interfaces/IIterator.cpp
	$(CC) $(OPCIONES) ./ICollection/interfaces/IIterator.cpp

IKey.o: ./ICollection/interfaces/IKey.h ./ICollection/interfaces/IKey.cpp
	$(CC) $(OPCIONES) ./ICollection/interfaces/IKey.cpp

Integer.o: ./ICollection/Integer.h ./ICollection/Integer.cpp
	$(CC) $(OPCIONES) ./ICollection/Integer.cpp

String.o: ./ICollection/String.h ./ICollection/String.cpp
	$(CC) $(OPCIONES) ./ICollection/String.cpp

clean:
	rm -rf *o Lab4PA2021

rebuild:
	make clean
	make
