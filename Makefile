CXX := g++
FLAGS := -std=c++2a -Wall -Werror -g

LIBS := build/model/model.a

all: 
	$(MAKE) -C src/model all
	$(CXX) $(FLAGS) -o build/main src/main.cpp $(LIBS) 

clean:
	rm -rf build/*