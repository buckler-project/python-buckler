CC      = g++
OBJSFX  = .o
CFLAGS  = -g -Wall -std=c++17 -I/usr/include/python3.7m
SFLAGS  = -shared -fPIC -DPIC
LFLAGS  = -lpython3 -lboost_python3 -lpthread -lboost_filesystem -lboost_system -lyaml-cpp -ldl -lbuckler
SOURCE  = ./src/buckler.cxx
OBJECT  = $(wildcard $(OBJDIR)/*$(OBJSFX))
TARGET  = ./buckler.so

build:
	$(CC) $(SOURCE) -o $(TARGET) $(CFLAGS) $(LFLAGS) $(SFLAGS)

clean:
	rm -rf ./bin/*

rebuild:
	make clean && make build
