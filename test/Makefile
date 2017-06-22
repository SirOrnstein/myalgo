#Makefile for the unit test app

PWD:=$(shell /bin/pwd)

GCC=g++
CXXFLAGS=-std=c++0x -Wall -ggdb -O0

GTEST_PATH=$(PWD)/gtest
CXXFLAGS+=-I$(GTEST_PATH)/include -L$(GTEST_PATH)/lib

SRC_DIR=$(PWD)/../src
CXXFLAGS+=-I$(SRC_DIR) -L$(SRC_DIR)
CXXFLAGS+=-DGTEST_LINKED_AS_SHARED_LIBRARY=1

#always assuming the shared lib in src dir already built
SRC_LIB=$(SRC_DIR)/libmyalgo.so
LIBS=-lgtest -lgtest_main -lmyalgo

TEST_HEADER=testMyAlgo.h
TEST_CPPFILE=testRunner.cpp
OBJ=testRunner.o
PROG=gtestRunner

TEST_PRINT_FILE=Result.txt

.phony: all runtest clean

all: runtest

$(OBJ): $(TEST_CPPFILE) $(TEST_HEADER)
	$(GCC) $(CXXFLAGS) -o $@ -c $<

$(PROG): $(OBJ) $(SRC_LIB)
	$(GCC) $(CXXFLAGS) -o $@ $< $(LIBS)

runtest: $(PROG)
	@export LD_LIBRARY_PATH=$(GTEST_PATH)/lib:$(SRC_DIR); ./$(PROG)

clean:
	rm -f $(OBJ) $(PROG) $(TEST_PRINT_FILE)
