EXE = bin/SimpleComputer

DIR_SRC = build

CC = g++
FLAGS = -Wall -Werror --std=c++17

.PHONY: clean run

all: $(EXE) run

$(EXE): $(DIR_SRC)/main.o $(DIR_SRC)/libmySimpleComputer.a
	$(CC) $(FLAGS) -o $@ $^ -Lbuild -lmySimpleComputer

$(DIR_SRC)/main.o: src/main.cpp
	$(CC) $(FLAGS) -c $^ -o $@

$(DIR_SRC)/mySimpleComputer.o: src/mySimpleComputer.cpp
	$(CC) $(FLAGS) -c $^ -o $@

$(DIR_SRC)/libmySimpleComputer.a: $(DIR_SRC)/mySimpleComputer.o
	ar cr $(DIR_SRC)/libmySimpleComputer.a $(DIR_SRC)/mySimpleComputer.o

run:
	./bin/SimpleComputer

clean:
	rm -f $(DIR_SRC)/*.o
	rm -f $(EXE)