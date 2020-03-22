BIN=./bin
DATA=./data
DOC=./doc
INCLUDE=./include
LIB=./lib
OBJ=./obj
SRC=./src
ZIP=./zip

OPT=-Wall -g

all : $(BIN)/circulomedio

$(BIN)/circulomedio : $(OBJ)/central.o $(LIB)/libformas.a
	g++ -o $(BIN)/circulomedio $(OBJ)/central.o -Llib/ -lformas

$(OBJ)/central.o: $(SRC)/central.cpp $(INCLUDE)/punto.h $(INCLUDE)/circulo.h
	g++ $(OPT) -c $(SRC)/central.cpp -o $(OBJ)/central.o -Iinclude

$(LIB)/libformas.a: $(OBJ)/punto.o $(OBJ)/circulo.o
	ar rsv $(LIB)/libformas.a $(OBJ)/punto.o $(OBJ)/circulo.o

$(OBJ)/punto.o: $(SRC)/punto.cpp $(INCLUDE)/punto.h
	g++ $(OPT) -c $(SRC)/punto.cpp -o $(OBJ)/punto.o -Iinclude/

$(OBJ)/circulo.o: $(SRC)/circulo.cpp $(INCLUDE)/circulo.h $(INCLUDE)/punto.h
	g++ $(OPT) -c $(SRC)/circulo.cpp -o $(OBJ)/circulo.o -Iinclude/


clean:
	@echo "Limpiando..."
	rm $(OBJ)/*.o $(LIB)/*.a $(BIN)/*

doxy:
	doxygen doc/circulomedio.doxy
	firefox $(DOC)/html/index.html &

zip: clean
	zip -r zip/practica2.zip *
