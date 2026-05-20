CXX = g++ 
CXXFLAGS = -I./include -Wall

all: derle

derle:
	$(CXX) $(CXXFLAGS) -c src/Konum.cpp -o lib/Konum.o
	$(CXX) $(CXXFLAGS) -c src/Labirent.cpp -o lib/Labirent.o
	$(CXX) $(CXXFLAGS) lib/Konum.o lib/Labirent.o src/Test.cpp -o bin/Test.exe

calistir:
	bin/Test.exe

temizle:
	del /Q lib\*.o bin\Test.exe

