EXE = bin/SimpleComputer

DIR_SRC = build

CC = g++
FLAGS = -Wall -Werror --std=c++17

.PHONY: clean run

all: $(EXE)

$(EXE): $(DIR_SRC)/main.o $(DIR_SRC)/libmySimpleComputer.a $(DIR_SRC)/libmyTerm.a $(DIR_SRC)/libmyBigChars.a $(DIR_SRC)/libprintConsole.a 
	$(CC) $(FLAGS) -o $@ $^ -Lbuild -lmySimpleComputer -Lbuild -lmyTerm \
	-Lbuild -lmyBigChars -Lbuild -lmySimpleComputer -lmyTerm -lprintConsole 

$(DIR_SRC)/main.o: src/main.cpp
	$(CC) $(FLAGS) -c $^ -o $@

$(DIR_SRC)/mySimpleComputer.o: src/mySimpleComputer.cpp
	$(CC) $(FLAGS) -c $^ -o $@

$(DIR_SRC)/libmySimpleComputer.a: $(DIR_SRC)/mySimpleComputer.o
	ar cr $(DIR_SRC)/libmySimpleComputer.a $(DIR_SRC)/mySimpleComputer.o

$(DIR_SRC)/myTerm.o: src/myTerm.cpp
	$(CC) $(FLAGS) -c $^ -o $@

$(DIR_SRC)/libmyTerm.a: $(DIR_SRC)/myTerm.o
	ar cr $(DIR_SRC)/libmyTerm.a $(DIR_SRC)/myTerm.o

$(DIR_SRC)/myBigChars.o: src/myBigChars.cpp
	$(CC) $(FLAGS) -c $^ -o $@

$(DIR_SRC)/libmyBigChars.a: $(DIR_SRC)/myBigChars.o
	ar cr $(DIR_SRC)/libmyBigChars.a $(DIR_SRC)/myBigChars.o

$(DIR_SRC)/printConsole.o: src/printConsole.cpp
	$(CC) $(FLAGS) -c $^ -o $@

$(DIR_SRC)/libprintConsole.a: $(DIR_SRC)/printConsole.o
	ar cr $(DIR_SRC)/libprintConsole.a $(DIR_SRC)/printConsole.o 

run:
	clear
	./bin/SimpleComputer

clean:
	rm -f $(DIR_SRC)/*.o
	rm -f $(DIR_SRC)/*.a
	rm -f $(EXE)
