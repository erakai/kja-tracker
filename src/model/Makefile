AR := ar
CXX := g++
FLAGS := -std=c++2a -Wall -Werror -g

BUILD_PATH := ../../build/model
SOURCES := job_app.cpp
OBJS := $(SOURCES:%.cpp=$(BUILD_PATH)/%.o)

LIB := $(BUILD_PATH)/model.a

all: $(BUILD_PATH) $(LIB)

$(LIB): $(OBJS)
	$(AR) rcs $(LIB) $(OBJS) 

$(BUILD_PATH)/%.o: %.cpp
	$(CXX) $(FLAGS) -c $< -o $@

$(BUILD_PATH):
	mkdir $@