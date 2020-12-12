COMP=g++
CFLAGS=-Wall
EXE=run

#default rule
default: $(EXE)

#general make rules
.c.o:
	gcc -c $(CFLG) $<
.cpp.o:
	g++ -c $(CFLG) $<

#compile object files here
run.o: run.cpp

# list needed object files as dependencies here
$(EXE): run.o libnd_base.a
	$(COMP) -o $@ $^ -L. -lnd_base -lGL -lGLU -lglut

clean:
	rm $(EXE) *.o
