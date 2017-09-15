main: main.o Playground.o Map.o Playground.o Settings.o
	g++ -g -o C-urassic main.o Playground.o Map.o -lm

main.o: Playground.o Map.o
	g++ -g -c Control/main.cpp

Settings.o: Control/Settings.hpp
	g++ -g -c Control/Settings.hpp

MapCharacter.o: Control/MapCharacter.hpp
	g++ -g -c Control/MapCharacter.hpp

Map.o: Model/Map.cpp Model/Map.hpp  Model/Directions.hpp Settings.o
	g++ -g -c Model/Map.cpp 

Playground.o: View/Playground.cpp View/Playground.hpp Settings.o
	g++ -g -c View/Playground.cpp

clean:
	rm *.o C-urassic