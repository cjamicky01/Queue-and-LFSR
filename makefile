
CC=g++
#CC=g++ -fprofile-arcs -ftest-coverage

project04: main.o lfsr.o queue.o
	$(CC) main.o lfsr.o queue.o -o project04

main.o: main.cpp lfsr.h
	$(CC) -c main.cpp

lfsr.o: lfsr.cpp lfsr.h
	$(CC) -c lfsr.cpp

queue.o: queue.cpp queue.h lfsr.h
	$(CC) -c queue.cpp

clean:
	rm *.o *.gcda *.gcno *.gcov project04



