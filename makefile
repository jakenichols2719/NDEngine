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
cdstruct.o: cdstruct.h cdstruct.cpp
load.o: load.cpp load.h cdstruct.h
run.o: run.cpp ndgl.h load.h

# list needed object files as dependencies here
$(EXE): run.o load.o cdstruct.o
	$(COMP) -o $@ $^ $(LIBS)

clean:
	rm *.o $(EXE)