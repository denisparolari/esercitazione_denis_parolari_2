g++ -c Floor.cpp -o floor.o
ar rcs libfloor.a floor.o 

g++ -c Room.cpp -o room.o
ar rcs libroom.a room.o 

g++ -c Building.cpp -o building.o
ar rcs libbuilding.a building.o 

g++ -c main.cpp -o main.o
g++ -o main.exe main.o -L. -lfloor -lroom -lbuilding