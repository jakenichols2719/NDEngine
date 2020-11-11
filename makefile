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
#try to keep this in inheritance order for readability
ndstruct.o: ndstruct.h ndstruct.cpp
load.o: load.cpp load.h ndstruct.o
ndconst.o: ndconst.h ndconst.cpp ndstruct.o
run.o: run.cpp ndgl.h ndstruct.o load.o ndconst.o

# list needed object files as dependencies here
$(EXE): run.o load.o ndstruct.o ndconst.o
	$(COMP) -o $@ $^ $(LIBS)

clean:
	rm *.o $(EXE)