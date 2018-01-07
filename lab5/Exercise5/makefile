JAVAC=javac
sources = $(wildcard *.java)
classes = $(sources:.java=.class)

all: $(classes)

clean :
	$(RM) *.class
run:
	java MultithreadedCharPrinting

%.class : %.java
	$(JAVAC) $<
