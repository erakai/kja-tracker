CXX := g++
FLAGS := -std=c++2a -Wall -Werror -g
INC := -I include

BINDIR := bin
BUILDDIR := build
SRCDIR := src
EXEC := $(BINDIR)/kja-tracker

SRC := $(wildcard src/*.cpp) $(wildcard src/**/*.cpp)
OBJS := $(SRC:$(SRCDIR)/%.cpp=$(BUILDDIR)/%.o)

all: $(EXEC)

$(EXEC): $(BUILDDIR) $(BINDIR) $(OBJS)
	@echo "Linking..."
	$(CXX) $(FLAGS) $(OBJS) -o $(EXEC)

$(BUILDDIR):
	@echo "Creating build directory..."
	@mkdir $@

$(BINDIR):
	@echo "Creating bin directory..."
	@mkdir $@

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@echo "Compiling $^"
	@mkdir -p $(@D)
	@$(CXX) $(FLAGS) $(INC) -c $< -o $@

.PHONY: clean
clean:
	@echo "Cleaning..."
	rm -r $(BUILDDIR)/* $(BINDIR)/*
