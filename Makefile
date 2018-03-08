List_Lib = ./src/Lists/
CXX = g++ -std=c++11 -Wall
TEMP = ./out/temp/
BIN = ./out/bin/
SRC = ./src/
OBJS = $(TEMP)BinaryTree.o $(TEMP)main.o

tbt: BinaryTree.o main.o release run clean

tsl: SimpleList.o main.o release run clean

tdl: DoubleList.o main.o release run clean

main.o: $(SRC)main.cpp
	@$(CXX) -c $(SRC)main.cpp -o $(TEMP)main.o
	@echo "Main module compiled!!"

SimpleList.o: $(List_Lib)SimpleList.cpp $(List_Lib)SimpleList.h
	@$(CXX) -c $(List_Lib)SimpleList.cpp -o $(TEMP)SimpleList.o
	@echo "SimpleList module compiled!!"

DoubleList.o: $(List_Lib)DoubleList.cpp $(List_Lib)DoubleList.h
	@$(CXX) -c $(List_Lib)DoubleList.cpp -o $(TEMP)DoubleList.o
	@echo "DoubleList module compiled!!"

BinaryTree.o: ./src/Trees/BinaryTree.cpp ./src/Trees/BinaryTree.h
	@$(CXX) -c ./src/Trees/BinaryTree.cpp -o $(TEMP)BinaryTree.o
	@echo "BinaryTree module compiled!!"

release: $(OBJS)
	@$(CXX) -o $(BIN)executeme $(OBJS)
	@echo "Binary file compiled!!"

.PHONY: clean
clean:
	@rm -rf $(TEMP)*.*
	@echo "Temp data cleaned"

.PHONY: run
run: 
	@echo "Executing program..."
	@echo ""
	@$(BIN)executeme