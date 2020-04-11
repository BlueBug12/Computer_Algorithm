insertion: insertion.o
	g++ -o insertion insertion.o

insertion.o: insertion.cpp
	g++ -c insertion.cpp

clean:
	rm -f insertion.o insertion.exe
