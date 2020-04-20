binary_tree: binary_tree.o
	g++ -o binary_tree binary_tree.o

binary_tree.o: binary_tree.cpp
	g++ -c binary_tree.cpp

clean:
	rm -f binary_tree.o binary_tree.exe
