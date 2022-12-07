CXX = g++
CXXFLAGS = -g -Wall -Wextra

.PHONY: all
all : LibrarySearchSystem

LibrarySearchSystem: librarySystem.cpp Book.o
	$(CXX) $(CXXFLAGS) -o $@ $^

Book.o: Book.cpp Book.h
	$(CXX) $(CXXFLAGS) -c $<

.PHONY : clean

clean:
	rm *~ *.o LibrarySearchSystem