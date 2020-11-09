COMP=g++
CFLAGS=-Wall
EXE=run
LIBS=-lglut -lGLU -lGL -lm

#default rule
default: $(EXE)

#general make rules
.c.o:
	gcc -c $(CFLG) $< $(LIBS)
.cpp.o:
	g++ -c $(CFLG) $< $(LIBS)

#compile object files here
run.o: run.cpp ndgl.h

# list needed object files as dependencies here
$(EXE): run.o
	$(COMP) -o $@ $^ $(LIBS)

clean:
	rm *.o $(EXE)