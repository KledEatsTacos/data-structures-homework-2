CXX = g++
CXXFLAGS = -std=c++11 -Wall -Iinclude
LDFLAGS =

SRC_DIR = src
OBJ_DIR = lib
BIN_DIR = bin

SRC = $(SRC_DIR)/main.cpp $(SRC_DIR)/LinkedList.cpp $(SRC_DIR)/Node.cpp $(SRC_DIR)/TreeNode.cpp $(SRC_DIR)/TreeDisplayBuffer.cpp
OBJ = $(OBJ_DIR)/main.o $(OBJ_DIR)/LinkedList.o $(OBJ_DIR)/Node.o $(OBJ_DIR)/TreeNode.o $(OBJ_DIR)/TreeDisplayBuffer.o
EXEC = $(BIN_DIR)/program.exe

all: directories $(EXEC)

directories:
	if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
	if not exist $(BIN_DIR) mkdir $(BIN_DIR)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: all
	$(EXEC)

clean:
	del /Q "$(OBJ_DIR)\*.o" "$(BIN_DIR)\*.exe"

.PHONY: all directories run clean