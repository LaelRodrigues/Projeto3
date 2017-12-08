RM = rm -rf 

CC=g++ 

INC_DIR = ./include
SRC_DIR = ./src
OBJ_DIR = ./build
LIB_DIR = ./lib
BIN_DIR = ./bin

LIBFLAGS = -lpetfera

CFLAGS	= -Wall -pedantic -std=c++11 
ARCHIVE = ar
PATH_DIR = /usr/local


.PHONY: all init clean debug doxy doc install linux 

linux: init petfera_dinamica

init:
	@mkdir -p $(BIN_DIR)/
	@mkdir -p $(OBJ_DIR)/
	@mkdir -p $(LIB_DIR)/

# Linux
petfera_dinamica: libpetfera.so
	$(CC) $(SRC_DIR)/main.cpp $(CFLAGS) -I$(INC_DIR) -L$(LIB_DIR) $(LIBFLAGS) -o $(BIN_DIR)/$@	

libpetfera.so:
	$(CC) $(CFLAGS) -fPIC -c $(SRC_DIR)/funcionario.cpp -I$(INC_DIR) -o $(OBJ_DIR)/funcionario.o
	$(CC) $(CFLAGS) -fPIC -c $(SRC_DIR)/veterinario.cpp -I$(INC_DIR) -o $(OBJ_DIR)/veterinario.o
	$(CC) $(CFLAGS) -fPIC -c $(SRC_DIR)/tratador.cpp -I$(INC_DIR) -o $(OBJ_DIR)/tratador.o
	$(CC) $(CFLAGS) -fPIC -c $(SRC_DIR)/animal.cpp -I$(INC_DIR) -o $(OBJ_DIR)/animal.o
	$(CC) $(CFLAGS) -fPIC -c $(SRC_DIR)/silvestre.cpp -I$(INC_DIR) -o $(OBJ_DIR)/silvestre.o
	$(CC) $(CFLAGS) -fPIC -c $(SRC_DIR)/nativo.cpp -I$(INC_DIR) -o $(OBJ_DIR)/nativo.o
	$(CC) $(CFLAGS) -fPIC -c $(SRC_DIR)/exotico.cpp -I$(INC_DIR) -o $(OBJ_DIR)/exotico.o
	$(CC) $(CFLAGS) -fPIC -c $(SRC_DIR)/anfibio.cpp -I$(INC_DIR) -o $(OBJ_DIR)/anfibio.o
	$(CC) $(CFLAGS) -fPIC -c $(SRC_DIR)/mamifero.cpp -I$(INC_DIR) -o $(OBJ_DIR)/mamifero.o
	$(CC) $(CFLAGS) -fPIC -c $(SRC_DIR)/reptil.cpp -I$(INC_DIR) -o $(OBJ_DIR)/reptil.o
	$(CC) $(CFLAGS) -fPIC -c $(SRC_DIR)/ave.cpp -I$(INC_DIR) -o $(OBJ_DIR)/ave.o
	$(CC) $(CFLAGS) -fPIC -c $(SRC_DIR)/menu.cpp -I$(INC_DIR) -o $(OBJ_DIR)/menu.o
	$(CC) -shared -fPIC -o $(LIB_DIR)/libpetfera.so $(OBJ_DIR)/funcionario.o $(OBJ_DIR)/veterinario.o $(OBJ_DIR)/tratador.o $(OBJ_DIR)/animal.o $(OBJ_DIR)/silvestre.o $(OBJ_DIR)/nativo.o $(OBJ_DIR)/exotico.o $(OBJ_DIR)/anfibio.o $(OBJ_DIR)/mamifero.o $(OBJ_DIR)/reptil.o $(OBJ_DIR)/ave.o $(OBJ_DIR)/menu.o 	

install: 
	mkdir -p $(PATH_DIR)/include
	mkdir -p $(PATH_DIR)/lib
	cp $(INC_DIR)/funcionario.h $(PATH_DIR)/include/
	cp $(INC_DIR)/veterinario.h $(PATH_DIR)/include/
	cp $(INC_DIR)/tratador.h $(PATH_DIR)/include/
	cp $(INC_DIR)/animal.h $(PATH_DIR)/include/
	cp $(INC_DIR)/silvestre.h $(PATH_DIR)/include/
	cp $(INC_DIR)/nativo.h $(PATH_DIR)/include/
	cp $(INC_DIR)/exotico.h $(PATH_DIR)/include/
	cp $(INC_DIR)/anfibio.h $(PATH_DIR)/include/
	cp $(INC_DIR)/mamifero.h $(PATH_DIR)/include/
	cp $(INC_DIR)/reptil.h $(PATH_DIR)/include/
	cp $(INC_DIR)/ave.h $(PATH_DIR)/include/
	cp $(INC_DIR)/menu.h $(PATH_DIR)/include/
	cp $(LIB_DIR)/libpetfera.so $(PATH_DIR)/lib/
	cp $(LIB_DIR)/libpetfera.so /usr/lib/

uninstall:
	$(RM) $(PATH_DIR)/include/funcionario.h
	$(RM) $(PATH_DIR)/include/veterinario.h
	$(RM) $(PATH_DIR)/include/tratador.h
	$(RM) $(PATH_DIR)/include/animal.h
	$(RM) $(PATH_DIR)/include/silvestre.h
	$(RM) $(PATH_DIR)/include/nativo.h
	$(RM) $(PATH_DIR)/include/exotico.h
	$(RM) $(PATH_DIR)/include/anfibio.h
	$(RM) $(PATH_DIR)/include/mamifero.h
	$(RM) $(PATH_DIR)/include/reptil.h
	$(RM) $(PATH_DIR)/include/ave.h
	$(RM) $(PATH_DIR)/include/menu.h
	$(RM) $(PATH_DIR)/lib/libpetfera.so
	$(RM) usr/lib/libpetfera.so

doxy:
	doxygen -g

doc:
	$(RM) $(DOC_DIR)/*
	doxygen

clean:
	$(RM) $(BIN_DIR)/*
	$(RM) $(OBJ_DIR)/*
	$(RM) $(LIB_DIR)/*