#
# Makefile for src/
#
PWD:=$(shell /bin/pwd)

GCC=g++
CXXFLAGS=-std=c++0x -Wall -fPIC -ggdb -O2

HEADERS=ArrayQueue.h MatchBracket.h ArrayPairSum.h MyBst.h
CPPFILES=ArrayQueue.cpp MatchBracket.cpp MyBst.cpp
OBJS=$(patsubst %.cpp,%.o,$(wildcard $(CPPFILES)))

LIB=libmyalgo.so

TEST_DIR=../test

.phony: all test clean

all: $(OBJS) $(LIB)

%.o : %.cpp %.h
	$(GCC) $(CXXFLAGS) -o $@ -c $<

$(LIB): $(OBJS)
	$(GCC) -shared -Wl,-soname,$(LIB) -fPIC -o $(LIB) $(OBJS)

test: $(OBJS)
	make -C $(TEST_DIR) all

clean:
	rm -f $(OBJS) $(LIB)
	make -C $(TEST_DIR) clean
