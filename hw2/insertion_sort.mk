insertion_sort: insertion_sort.o
	g++ -o insertion_sort insertion_sort.o

insertion_sort.o: insertion_sort.cpp
	g++ -c insertion_sort.cpp

clean:
	rm -f insertion_sort.o insertion_sort.exe
