CC = g++
CPPFLAGS = -Wall -g -std=c++11
OBJ_FILES = main.o queue.o stack.o party.o ./helpers/getters.o

# make will generate ./main using .o files
main: $(OBJ_FILES)

./helpers/getters.o: ./helpers/getters.h

main.o: main.h

queue.o: queue.h

stack.o: stack.h

party.o: party.h

leak:
	valgrind --leak-check=full ./main
	
# .PHONY: because clean is not associatd with any specific files
.PHONY: clean
clean:
	$(info -- CLEANING DIRECTORY -- )
	rm -f *.o
	rm -f main
