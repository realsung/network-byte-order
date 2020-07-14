all: add-nbo

add-nbo: byte_order.o main.o
	g++ -o add-nbo byte_order.o main.o

byte_order.o: byte_order.h byte_order.cpp
	g++ -c -o byte_order.o byte_order.cpp

main.o: main.cpp byte_order.h
	g++ -c -o main.o main.cpp

clear:
	rm -f add-nbo *.o