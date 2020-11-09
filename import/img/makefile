COMP=g++
CFLAGS=-Wall
EXE=import
LIBS=-lglut -lGLU -lGL -lm

#default rule
default: $(EXE)

#general make rules
.c.o:
	gcc -c $(CFLG) $< $(LIBS)
.cpp.o:
	g++ -c $(CFLG) $< $(LIBS)

#compile object files here
import.o: import.cpp

# list needed object files as dependencies here
$(EXE): import.o
	$(COMP) -o $@ $^ $(LIBS)

clean:
	rm *.o $(EXE)