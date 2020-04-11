quick_sort: quick_sort.o
	g++ -o quick_sort quick_sort.o

quick_sort.o: quick_sort.cpp
	g++ -c quick_sort.cpp

clean:
	rm -f quick_sort.o quick_sort.exe
