#Makefile for the Particle Simulator

#Compiling into object files
Game.o: Game.cpp 
	g++ -c Game.cpp  -IC:\Users\jacob\OneDrive\Documents\SFML-2.5.1\include -DSFML_STATIC

Main.o: Main.cpp
	g++ -c Main.cpp  -IC:\Users\jacob\OneDrive\Documents\SFML-2.5.1\include -DSFML_STATIC

particle.o: particle.cpp
	g++ -c particle.cpp  -IC:\Users\jacob\OneDrive\Documents\SFML-2.5.1\include -DSFML_STATIC

gravitySource.o: gravitySource.cpp
	g++ -c gravitySource.cpp  -IC:\Users\jacob\OneDrive\Documents\SFML-2.5.1\include -DSFML_STATIC

helpscreen.o: helpscreen.cpp
	g++ -c helpscreen.cpp -IC:\Users\jacob\OneDrive\Documents\SFML-2.5.1\include -DSFML_STATIC

#Linking object files and building executable
game: Game.o Main.o particle.o gravitySource.o helpscreen.o
	g++ Main.o gravitySource.o particle.o Game.o helpscreen.o -o game.exe -L"C:\Users\jacob\OneDrive\Documents\SFML-2.5.1\lib" -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows




