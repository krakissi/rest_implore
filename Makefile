all: rest_implore rest_request

rest_implore: rest_implore.cc
	@g++ -std=c++11 -s rest_implore.cc -o rest_implore

rest_request: rest_request.bash
	@cp rest_request.bash rest_request
	@chmod a+x rest_request
