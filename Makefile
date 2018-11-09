CC      = g++
OBJSFX  = .o
CFLAGS  = -g -Wall -std=c++17 -I/usr/include/python3.7m
SFLAGS  = -shared -fPIC -DPIC
LFLAGS  = -lboost_python3 -lpthread -lboost_filesystem -lboost_system -ldl 
OBJDIR  = lib/buckler/obj
SOURCE  = ./src/buckler.cxx
OBJECT  = $(wildcard $(OBJDIR)/*$(OBJSFX))
TARGET  = ./bin/buckler.so


build:
	$(CC) $(SOURCE) $(OBJECT) -o $(TARGET) $(IFLAGS) $(CFLAGS) $(LFLAGS) $(SFLAGS)

run: $(TARGET)
	$(TARGET)

clean:
	rm -f $(TARGET) $(TRUE_TARGET) $(FALSE_TARGET) 

rebuild:
	make clean && make build
