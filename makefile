all: main

main: main.o helpers.o
	@echo "linking object files"
	@g++ -o main main.o helpers.o

main.o: main.cpp
	@echo "compiling main.cpp"
	@g++ -c main.cpp

helpers.o: helpers.cpp
	@echo "compiling helpers.cpp"
	@g++ -c helpers.cpp


clean:
	@echo "removing object files"
	@rm *.o
