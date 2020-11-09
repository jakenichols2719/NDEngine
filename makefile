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
ndstruct.o: ndstruct.h ndstruct.cpp
ndstatic.o: ndstatic.h ndstatic.cpp
load.o: load.cpp load.h ndstruct.h
run.o: run.cpp ndgl.h load.h ndstatic.h

# list needed object files as dependencies here
$(EXE): run.o load.o ndstruct.o ndstatic.o
	$(COMP) -o $@ $^ $(LIBS)

clean:
	rm *.o $(EXE)