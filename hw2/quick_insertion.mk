quick_insertion: quick_insertion.o
	g++ -o quick_insertion quick_insertion.o

quick_insertion.o: quick_insertion.cpp
	g++ -c quick_insertion.cpp

clean:
	rm -f quick_insertion.o quick_insertion.exe
