BIN=./bin
DATA=./data
DOC=./doc
INCLUDE=./include
LIB=./lib
OBJ=./obj
SRC=./src
ZIP=./zip

PRJ=practica2
OPT=-Wall -g

all : $(BIN)/intervalo

$(BIN)/intervalo : $(OBJ)/main.o $(LIB)/libintervalo.a
	g++ -o $(BIN)/intervalo $(OBJ)/main.o -lintervalo -L$(LIB)

$(OBJ)/main.o : $(SRC)/main.cpp $(INCLUDE)/intervalo.h
	g++ $(OPT) -c $(SRC)/main.cpp -o $(OBJ)/main.o -I$(INCLUDE)

$(LIB)/libintervalo.a : $(OBJ)/intervalo.o
	ar -rvs $(LIB)/libintervalo.a $(OBJ)/intervalo.o

$(OBJ)/intervalo.o : $(SRC)/intervalo.cpp $(INCLUDE)/intervalo.h
	g++ $(OPT) -c $(SRC)/intervalo.cpp -o $(OBJ)/intervalo.o -I$(INCLUDE)

clean : 
	@echo "Limpiando ..."
	rm -rf $(DOC)/html $(DOC)/latex $(OBJ)/*.o $(BIN)/* $(LIB)/* $(ZIP)/*

doxy :
	doxygen $(DOC)/intervalo.doxy
	firefox $(DOC)/html/index.html

zip : clean
	@echo "Generando ZIP del proyecto " $(PRJ) 
	zip -r $(ZIP)/$(PRJ).zip * 
