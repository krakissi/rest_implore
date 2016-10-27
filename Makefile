all: rest_implore

rest_implore: rest_implore.cc
	@g++ -std=c++11 -s rest_implore.cc -o rest_implore
