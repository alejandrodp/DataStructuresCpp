List_Lib = ./src/Lists/
CXX = g++ -std=c++11
TEMP = ./out/temp/
BIN = ./out/bin/
SRC = ./src/
OBJS = SimpleList.o main.o
toRelease = $(TEMP)main.o $(TEMP)SimpleList.o

all: SimpleList.o main.o release clean run

main.o: $(SRC)main.cpp
	@$(CXX) -c -I$(List_Lib) $(SRC)main.cpp -o $(TEMP)main.o
	@echo "Main module compiled!!"

SimpleList.o: $(List_Lib)SimpleList.cpp $(List_Lib)SimpleList.h
	@$(CXX) -c -I$(List_Lib) $(List_Lib)SimpleList.cpp -o $(TEMP)SimpleList.o
	@echo "SimpleList module compiled!!"

release: $(OBJS)
	@$(CXX) -o $(BIN)executeme $(toRelease)
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