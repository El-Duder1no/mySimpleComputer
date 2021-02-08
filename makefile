program: main.o libmySimpleComputer.a
	g++ -Wall -Werror -o program main.o -L. -lmySimpleComputer

main.o: src/main.cpp
	g++ -Wall -Werror -c src/main.cpp -o main.o

mySimpleComputer.o: src/mySimpleComputer.cpp
	g++ -Wall -Werror -c src/mySimpleComputer.cpp -o mySimpleComputer.o

libmySimpleComputer.a: mySimpleComputer.o
	ar cr libmySimpleComputer.a mySimpleComputer.o

clean:
	rm -f *.o *.a program