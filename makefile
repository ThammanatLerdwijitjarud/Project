compile: main.cpp 
	 g++  main.cpp NODE.h LL.h file.cpp -o animal

run: animal
	 ./animal


clean: animal
	 rm animal