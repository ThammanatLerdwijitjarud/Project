compile: main.cpp 
	 g++  main.cpp NODE.h -o animal

run: animal
	 ./animal


clean: animal
	 rm animal