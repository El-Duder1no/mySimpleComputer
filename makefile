EXE = bin/program
TEST = bin/test

DIR_SRC = build/src
DIR_TEST = build/test

FLAGS = -Wall -Werror --std=c++17

OBJ = g++ $(FLAGS) -c $^ -o $@

all: $(EXE) $(TEST)

.PHONY: clean all

$(EXE): $(DIR_SRC)/main.o
	g++ $(FLAGS) $^ -o $@

$(DIR_SRC)/main.o: src/main.cpp
	$(OBJ)

clean:
	rm -rf $(DIR_SRC)/*.o
	rm -rf $(DIR_TEST)/*.o
	rm bin/*.exe
