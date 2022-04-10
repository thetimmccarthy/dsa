main: main.o AVLTree.o
	clang++ -g main.o AVLTree.o -o main
main.o: main.cpp
	clang++ -c main.cpp

AVLTree.o: AVLTree.cpp AVLTree.h
	clang++ -c AVLTree.cpp

clean: 
	rm *.o main