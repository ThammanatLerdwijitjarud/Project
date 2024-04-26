compile: main.cpp
	 g++  main.cpp -o animal

run: animal
	 ./animal


clean: animal
	 rm animal