# EXE = bin/program
# TEST = bin/test

# DIR_SRC = build/src
# DIR_TEST = build/test

# FLAGS = -Wall -Wextra -Werror --std=c++17
# CPPFLAGS = -MMD

# OBJ = g++ $(FLAGS) -c $^ -o $@

# all: $(EXE)

# .PHONY: clean all

# $(EXE): $(DIR_SRC)/main.o $(DIR_SRC)/libmySimpleComputer.a
# 	g++ $(FLAGS) $^ -o $@

# $(DIR_SRC)/main.o: src/main.cpp
# 	g++ $(FLAGS) $(CPPFLAGS) -o $@ $<

# $(DIR_SRC)/libmySimpleComputer.a: $(DIR_SRC)/mySimpleComputer.o
# 	ar rcs $@ $^

# $(DIR_SRC)/mySimpleComputer.o: src/mySimpleComputer.cpp
# 	$(OBJ) $(FLAGS) $(CPPFLAGS) -o $@ $<

# clean:
# 	rm -rf $(DIR_SRC)/*.o
# 	rm -rf $(DIR_TEST)/*.o
# 	rm bin/*.exe

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