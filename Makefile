CC      = g++
OBJSFX  = .o
CFLAGS  = -g -Wall -std=c++17 -I/usr/include/python3.7m
SFLAGS  = -shared -fPIC -DPIC
LFLAGS  = -lboost_python -lpthread -lboost_filesystem -lboost_system -ldl 
OBJDIR  = lib/buckler/obj
SOURCE  = ./src/buckler.cxx
OBJECT  = $(wildcard $(OBJDIR)/*$(OBJSFX))
TARGET  = ./bin/buckler


test:
	g++ -fPIC -I/usr/include/python3.7m -lboost_python3 -shared -o ./bin/simple.so ./src/buckler.cxx

build:
	$(CC) $(SOURCE) $(OBJECT) $(IFLAGS) $(CFLAGS) $(LFLAGS) -o $(TARGET)

run: $(TARGET)
	$(TARGET)

clean:
	rm -f $(TARGET) $(TRUE_TARGET) $(FALSE_TARGET) 

rebuild:
	make clean && make build
