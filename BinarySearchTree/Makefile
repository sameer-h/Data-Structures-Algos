all: run-trees

run-trees: BSTree.o BSTree_main.o
	g++ -std=c++11 BSTree.o BSTree_main.o -o run-trees

BSTree.o: BSTree.cpp BSTree.h
	g++ -std=c++11 -c BSTree.cpp

BSTree_main: BSTree_main.cpp BSTree.h
	g++ -std=c++11 -c BSTree_main.cpp

clean:
	rm *.o run-trees