
test:main_haar.o haar_delta.o haar_decode.o
	g++ -g main_haar.o haar_delta.o haar_decode.o -o test

main_haar.o: main_haar.cpp
	g++ -g -c main_haar.cpp

haar_delta.o: haar_c_delta.cpp haar_c_delta.hpp 
	g++ -g -c haar_c_delta.cpp

haar_decode.o: haar_decode.cpp haar_decode.hpp 
	g++ -g -c haar_decode.cpp
clean:
	rm *.o test

