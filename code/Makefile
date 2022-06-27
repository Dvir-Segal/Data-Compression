
test:main_haar.o haar_decode.o haar_c_delta.o haar_binary.o haar_unary.o haar_c_gamma.o haar_fibo.o
	g++ -g main_haar.o haar_decode.o haar_c_delta.o haar_binary.o haar_unary.o haar_c_gamma.o haar_fibo.o -o test

main_haar.o: main_haar.cpp
	g++ -g -c main_haar.cpp

haar_fibo.o: haar_fibo.cpp haar_fibo.hpp 
	g++ -g -c haar_fibo.cpp
haar_c_delta.o: haar_c_delta.cpp haar_c_delta.hpp 
	g++ -g -c haar_c_delta.cpp
haar_binary.o: haar_binary.cpp haar_binary.hpp 
	g++ -g -c haar_binary.cpp
haar_unary.o: haar_unary.cpp haar_unary.hpp 
	g++ -g -c haar_unary.cpp
haar_c_gamma.o: haar_c_gamma.cpp haar_c_gamma.hpp 
	g++ -g -c haar_c_gamma.cpp
haar_decode.o: haar_decode.cpp haar_decode.hpp 
	g++ -g -c haar_decode.cpp
clean:
	rm *.o test

