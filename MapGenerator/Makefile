gen: cursor.o room.o main.o
	g++ -o gen cursor.o room.o main.o

main.o: main.cpp main.h
	g++ -c main.cpp

room.o: room.cpp room.h define.h
	g++ -c room.cpp

cursor.o: cursor.cpp cursor.h
	g++ -c cursor.cpp
