selection: selection.o
	g++ -o selection selection.o

selection.o: selection.cpp
	g++ -c selection.cpp

clean:
	rm -f selection.o selection.exe
