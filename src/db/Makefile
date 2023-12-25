AR := ar
CXX := g++
FLAGS := -std=c++2a -Wall -Werror -g

BUILD_PATH := ../../build/db
SOURCES := app_store.cpp
OBJS := $(SOURCES:%.cpp=$(BUILD_PATH)/%.o)

LIB := $(BUILD_PATH)/db.a

all: $(BUILD_PATH) $(LIB)

$(LIB): $(OBJS)
	$(AR) rcs $(LIB) $(OBJS) 

$(BUILD_PATH)/%.o: %.cpp
	$(CXX) $(FLAGS) -c $< -o $@

$(BUILD_PATH):
	mkdir $@