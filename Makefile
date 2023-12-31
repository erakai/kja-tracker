CXX := g++
FLAGS := -std=c++2a -Wall -Werror -g
INC := -I include

BINDIR := bin
BUILDDIR := build
SRCDIR := src
INCLUDEDIR := include
EXEC := $(BINDIR)/kja-tracker

SRC := $(wildcard src/*.cpp) $(wildcard src/**/*.cpp)
OBJS := $(SRC:$(SRCDIR)/%.cpp=$(BUILDDIR)/%.o)
DEP := $(OBJS:%.o=%.d)

all: $(EXEC)

-include $(DEP)

$(EXEC): $(BUILDDIR) $(BINDIR) $(OBJS)
	@echo "Linking..."
	$(CXX) $(FLAGS) $(OBJS) -o $(EXEC)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@echo "Compiling $<"
	@mkdir -p $(@D)
	@$(CXX) $(FLAGS) $(INC) -MMD -c $< -o $@

$(BUILDDIR):
	@echo "Creating build directory..."
	@mkdir $@

$(BINDIR):
	@echo "Creating bin directory..."
	@mkdir $@

.PHONY: clean
clean:
	@echo "Cleaning..."
	rm -rf $(BUILDDIR)/*
	rm -rf $(BINDIR)/*
