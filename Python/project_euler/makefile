CXX = g++
CXXFLAGS = -std=c++17 -O3 -Wall -Wextra -Werror -Icommon

TARGET = $(num)
SRC = answer/$(num).cpp common/common.cpp
HEADERS = common/BigInt.hpp

BIN_DIR = bin
OUT = $(BIN_DIR)/$(TARGET).out

# Default target
all: build

build:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

run: build
	./$(OUT)

clean:
	rm -f $(BIN_DIR)/*
