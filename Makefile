
test:main_haar.o haar.o
	g++ -g main_haar.o haar.o -o test

main_haar.o: main_haar.cpp
	g++ -g -c main_haar.cpp

haar.o: haar.cpp haar.hpp 
	g++ -g -c haar.cpp

clean:
	rm *.o test

