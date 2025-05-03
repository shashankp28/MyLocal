CXX = g++
CXXFLAGS = -std=c++17 -O3 -Wall -Wextra -Werror -Icommon

TARGET = $(num)
SRC = answer/$(num).cpp common/common.cpp

# Default target
all: build

build:
	$(CXX) $(CXXFLAGS) $(SRC) -o bin/$(TARGET).out

run: build
	./bin/$(TARGET).out

clean:
	rm -f ./bin/*
