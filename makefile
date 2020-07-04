COMP      := g++ -std=c++11
CPPFLAGs  := -I include
CFLAGS    := -Wall -pedantic -ansi

diary: src/main.cpp src/app.cpp
	$(COMP) $(CPPFLAGs) $(CFLAGS) -o diary src/main.cpp src/app.cpp

.PHONY: clean
clean:
	-rm diary
