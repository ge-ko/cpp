# cd <projects>/cpp/
# $ tree <project>/
# <project>/
# ├── bin/				# binary files, like executables
#     ├── <project>		# runs the program
#     └── test			# runs the tests
# ├── build/			# build output filrs, like object files
# ├── include/			# project include files
# ├── lib/				# external libs to link to
# ├── main/
#     ├── main.cpp		# main function of the program
#     └── test.cpp		# main unit test file
# ├── main/main.cpp		# main function
# ├── src/				# project source code
# ├── test/				# unit tests
# └── Makefile			# this make file

# project name
PROJECT=type-name

# important settings
SHELL=/bin/sh
.SUFFIXES:
.SUFFIXES: .cpp .h .hpp .o
CC=g++
CFLAGS=-g -std=c++11 -Wall -pedantic
LDFLAGS=
TESTFLAGS=--reporter compact --success
SRCEXT=cpp
ROOTDIR=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))

# project folders
BINDIR=bin
BUILDDIR=build
INCLUDE=include
LIB=lib
MAINDIR=main
SRCDIR=src
TESTDIR=test

# file sets
SOURCES=$(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
TESTS=$(shell find $(TESTDIR) -type f -name *.$(SRCEXT))
MAIN=$(MAINDIR)/main.$(SRCEXT)
MAIN_TEST=$(MAINDIR)/test.$(SRCEXT)
OBJECTS=$(patsubst $(SRCDIR)/%,$(BUILDDIR)/$(SRCDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
MAIN_OBJECT=$(BUILDDIR)/$(MAINDIR)/main.o
MAIN_TEST_OBJECT=$(BUILDDIR)/$(MAINDIR)/test.o
TEST_OBJECTS=$(patsubst $(TESTDIR)/%,$(BUILDDIR)/$(TESTDIR)/%,$(TESTS:.$(SRCEXT)=.o))
TARGET=$(BINDIR)/$(PROJECT).app
TEST_TARGET=$(BINDIR)/test.app

#project targets
.PHONY: all check clean

all: $(TARGET)
	@mkdir -p $(BINDIR)
	@mkdir -p $(BUILDDIR)
	@mkdir -p $(INCLUDE)
	@mkdir -p $(LIB)
	@mkdir -p $(MAINDIR)
	@mkdir -p $(SRCDIR)
	@mkdir -p $(TESTDIR)

check: $(TEST_TARGET)
	./$(TEST_TARGET) $(TESTFLAGS)

clean:
	$(RM) -r $(BUILDDIR)/$(SRCDIR) $(BUILDDIR)/$(MAINDIR) $(BUILDDIR)/$(TESTDIR) $(TARGET) $(TEST_TARGET)

$(TARGET): $(OBJECTS) $(MAIN_OBJECT)
	$(CC) $^ -o $@ -L $(LIB)

$(TEST_TARGET): $(OBJECTS) $(TEST_OBJECTS) $(MAIN_TEST_OBJECT)
	$(CC) $^ -o $@ -L $(LIB)

$(BUILDDIR)/$(SRCDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)/$(SRCDIR)
	$(CC) $(CFLAGS) -I $(INCLUDE) -c -o $@ $<
	
$(BUILDDIR)/$(MAINDIR)/%.o: $(MAINDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)/$(MAINDIR)
	$(CC) $(CFLAGS) -I $(INCLUDE) -c -o $@ $<

$(BUILDDIR)/$(TESTDIR)/%.o: $(TESTDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)/$(TESTDIR)
	$(CC) $(CFLAGS) -I $(INCLUDE) -c -o $@ $<
