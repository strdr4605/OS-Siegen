CC=gcc
CFLAGS=-c -Wall -pthread
LDFLAGS=-lpthread
SOURCES=thread_messages.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=thread_messages

.PHONY: all clean
all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	$(RM) *.o *~ $(EXECUTABLE)
