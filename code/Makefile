
test:main_haar.o haar.o haar_decode.o
	g++ -g main_haar.o haar.o haar_decode.o -o test

main_haar.o: main_haar.cpp
	g++ -g -c main_haar.cpp

haar.o: haar.cpp haar.hpp 
	g++ -g -c haar.cpp

haar_decode.o: haar_decode.cpp haar_decode.hpp 
	g++ -g -c haar_decode.cpp
clean:
	rm *.o test

