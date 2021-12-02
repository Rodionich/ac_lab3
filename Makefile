CXX = g++

RM = rm

CFLAGS = -c -Wall

output: main.o
	$(CXX) main.o -o output

main.o: main.cpp
	$(CXX) $(CFLAGS) main.cpp -o main.o

clean:
	$(RM) *.o output