SRC = main.cpp
OBJ = main.o
BIN = test

$(BIN):$(OBJ)
	g++ $< -o $@

%.o:%.cpp
	g++ -g -c $< -o $@

clean:
	rm -f $(BIN)
	rm -f $(OBJ)