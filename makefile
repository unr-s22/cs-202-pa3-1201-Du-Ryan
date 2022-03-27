pa3: main.o header.o
	g++ main.o header.o -o pa3

main.o: main.cpp
	g++ -c main.cpp

header.o: header.cpp
	g++ -c header.cpp

clean:
	rm *.o pa3
