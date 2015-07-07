#A naive makefile to generate the tests file

#WARNING: This makefile contains non-portable commands
#You should use autoconf if portability is required.

CC := g++
CFLAGS := -std=gnu++11 -lcppunit -Wall
INC := -Itest/include -Ilib
RM := rm -f
PWD := $(shell pwd)

all: queuetest

queuetest: test/src/queuetest.cpp
	mkdir -p test/bin/
	$(CC) -o test/bin/$@ $^ $(CFLAGS) $(INC)
	@echo Binary at $(PWD)/test/bin/$@
