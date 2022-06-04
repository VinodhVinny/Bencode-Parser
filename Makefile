CC = g++
CPPFLAGS = -g --std=c++14 -I$(IDIR)
IDIR = include
LIBS = -ljsoncpp

%.o: src/%.cpp
	$(CC) -c -o $@ $< $(CPPFLAGS)

bencode_parser: main.o bencode_decode.o bencode_encode.o
	$(CC) -o $@ $^ $(CPPFLAGS) $(LIBS)

clean:
	rm -rf *.o bencode_parser
