CXX := g++
FLAGS := -std=c++2a -Wall -Werror -g

LIBS := build/model/model.a build/db/db.a build/interface/interface.a

all: 
	$(MAKE) -C src/model all
	$(MAKE) -C src/db all
	$(MAKE) -C src/interface all
	$(CXX) $(FLAGS) -o build/main src/main.cpp $(LIBS) 

clean:
	rm -rf build/*