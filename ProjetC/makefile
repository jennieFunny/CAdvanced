# $@ : the current target
# $^ : the current prerequisites
# $< : the first current prerequisite
BIN = ./bin/
SRC = ./src/
INC = ./include/
TEST=./test/


EXEC=myprofiler
CC=gcc
FLAGS=-Wall -ansi

$(BIN)$(EXEC) : main.o draw.o linkedlist.o 
	$(CC) -o $(BIN)$(EXEC) $^ $(FLAGS) -lMLV

main.o : $(SRC)main.c $(INC)draw.h $(INC)linkedlist.h
	$(CC) -c $^ $(FLAGS) -lMLV

draw.o : $(SRC)draw.c $(INC)draw.h $(INC)linkedlist.h
	$(CC) -c $^ $(FLAGS) -lMLV

linkedlist.o : $(SRC)linkedlist.c $(INC)linkedlist.h
	$(CC) -c $^ $(FLAGS)

clean:
	rm -f  *.o $(INC)*.gch a.out