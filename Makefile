OBJETOS = Categoria.o Comentario.o Desarrollador.o Estadistica.o Individual.o \
Usuario.o Jugador.o Multijugador.o Suscripcion.o Transmision.o Partida.o Sistema.o Videojuego.o ISistema.o \
DtFecha.o main.o List.o ListIterator.o ListNode.o OrderedDictionary.o OrderedKey.o OrderedDictionaryEntry.o \
ICollectible.o ICollection.o IDictionary.o IIterator.o IKey.o Integer.o String.o StringKey.o

DEF = ./ICollection/interfaces/ICollectible.h ./ICollection/interfaces/IKey.h ./ICollection/interfaces/IIterator.h \
./ICollection/interfaces/ICollection.h ./ICollection/interfaces/IDictionary.h ./ICollection/interfaces/OrderedKey.h \
./ICollection/collections/OrderedDictionaryEntry.h ./ICollection/collections/ListNode.h \
./ICollection/collections/List.h ./ICollection/collections/ListIterator.h ./ICollection/collections/OrderedDictionary.h \
./ICollection/Integer.h ./ICollection/String.h ./ICollection/StringKey.h ./classes/headers/Tipo.h ./datatypes/headers/DtFecha.h \
./classes/headers/Usuario.h ./classes/headers/Categoria.h ./classes/headers/Desarrollador.h \
./classes/headers/Estadistica.h ./classes/headers/Individual.h \
./classes/headers/Jugador.h ./classes/headers/Transmision.h ./classes/headers/Videojuego.h \
./classes/headers/Suscripcion.h ./classes/headers/Comentario.h ./classes/headers/Multijugador.h \
./classes/headers/ISistema.h ./classes/headers/Sistema.h ./classes/headers/Fabrica.h \
./classes/headers/MetodoPago.h ./classes/headers/Valor.h

CC = g++
OPCIONES = -c -Wall

all: Laboratorio_4

Laboratorio_4: $(OBJETOS)
	$(CC) $(OBJETOS) -o Laboratorio_4

main.o: main.cpp Makefile ./classes/headers/Fabrica.h $( ./classes/headers/)
	$(CC) $(OPCIONES) main.cpp

Transmision.o: ./classes/headers/Transmision.h ./classes/sources/Transmision.cpp
	$(CC) $(OPCIONES) ./classes/sources/Transmision.cpp

Videojuego.o: ./classes/headers/Videojuego.h ./classes/sources/Videojuego.cpp
	$(CC) $(OPCIONES) ./classes/sources/Videojuego.cpp

Sistema.o: ./classes/headers/Sistema.h ./classes/sources/Sistema.cpp
	$(CC) $(OPCIONES) ./classes/sources/Sistema.cpp

ISistema.o: ./classes/headers/ISistema.h ./classes/sources/ISistema.cpp
	$(CC) $(OPCIONES) ./classes/sources/ISistema.cpp

Jugador.o: ./classes/headers/Jugador.h ./classes/sources/Jugador.cpp
	$(CC) $(OPCIONES) ./classes/sources/Jugador.cpp

Partida.o: ./classes/headers/Partida.h ./classes/sources/Partida.cpp
	$(CC) $(OPCIONES) ./classes/sources/Partida.cpp

Usuario.o: ./classes/headers/Usuario.h ./classes/sources/Usuario.cpp
	$(CC) $(OPCIONES) ./classes/sources/Usuario.cpp

Multijugador.o: ./classes/headers/Multijugador.h ./classes/sources/Multijugador.cpp
	$(CC) $(OPCIONES) ./classes/sources/Multijugador.cpp

Suscripcion.o: ./classes/headers/Suscripcion.h ./classes/headers/Valor.h ./classes/headers/MetodoPago.h ./classes/sources/Suscripcion.cpp 
	$(CC) $(OPCIONES) ./classes/sources/Suscripcion.cpp

Comentario.o: ./classes/headers/Comentario.h ./classes/sources/Comentario.cpp
	$(CC) $(OPCIONES) ./classes/sources/Comentario.cpp

Categoria.o: ./classes/headers/Categoria.h ./classes/sources/Categoria.cpp
	$(CC) $(OPCIONES) ./classes/sources/Categoria.cpp

Individual.o: ./classes/headers/Individual.h ./classes/sources/Individual.cpp
	$(CC) $(OPCIONES) ./classes/sources/Individual.cpp

Desarrollador.o: ./classes/headers/Desarrollador.h ./classes/sources/Desarrollador.cpp
	$(CC) $(OPCIONES) ./classes/sources/Desarrollador.cpp

Estadistica.o: ./classes/headers/Estadistica.h ./classes/sources/Estadistica.cpp
	$(CC) $(OPCIONES) ./classes/sources/Estadistica.cpp

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

StringKey.o: ./ICollection/StringKey.h ./ICollection/StringKey.cpp
	$(CC) $(OPCIONES) ./ICollection/StringKey.cpp

clean:
	rm -rf *o Laboratorio_4

rebuild:
	make clean
	make