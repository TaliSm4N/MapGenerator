gen: log.o cursor.o room.o main.o
	g++ -o gen log.o cursor.o room.o main.o

main.o: main.cpp main.h
	g++ -c main.cpp

room.o: room.cpp room.h define.h
	g++ -c room.cpp

cursor.o: cursor.cpp cursor.h
	g++ -c cursor.cpp

log.o: log.cpp log.h
	g++ -c log.cpp
