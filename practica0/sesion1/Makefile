main: main.o fibonacci-iterative.o fibonacci-recursive.o
	g++ -pg -o main main.o fibonacci-iterative.o fibonacci-recursive.o

main.o: main.c fibonacci.h
	g++ -pg -c main.c

fibonacci-iterative.o: fibonacci-iterative.c fibonacci.h
	g++ -pg -c fibonacci-iterative.c

fibonacci-recursive.o: fibonacci-recursive.c fibonacci.h
	g++ -pg -c fibonacci-recursive.c

clean:
	rm *.o