compile: p_test.cpp
	 g++  p_test.cpp -o animal

run: animal
	 ./animal


clean: animal
	 rm animal