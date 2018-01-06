CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=buffer_to_file.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=buffer_to_file

.PHONY: all clean
all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	$(RM) *.o *~ $(EXECUTABLE) myfile.txt
