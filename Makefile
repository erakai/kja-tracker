CXX := g++
FLAGS := -std=c++2a -Wall -Werror -g

LIBS := build/model/model.a build/db/db.a

all: 
	$(MAKE) -C src/model all
	$(MAKE) -C src/db all
	$(CXX) $(FLAGS) -o build/main src/main.cpp $(LIBS) 

clean:
	rm -rf build/*