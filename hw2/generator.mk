generator: generator.o
	g++ -o generator generator.o

generator.o: generator.cpp
	g++ -c generator.cpp

clean:
	rm -f generator.o generator.exe
