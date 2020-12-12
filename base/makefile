COMP=ar rcs
CFLAGS=-Wall
LIB=libnd_base.a

#default rule
default: $(LIB)

#general make rules
.c.o:
	gcc -c $(CFLG) $<
.cpp.o:
	g++ -c $(CFLG) $<

#compile object files here
load.o: load.h load.cpp
ndconst.o: ndconst.h ndconst.cpp
ndstruct.o: ndstruct.h ndstruct.cpp ndconst.o load.o

# list needed object files as dependencies here
$(LIB): load.o ndconst.o ndstruct.o
	$(COMP) $@ $^
	cp $(LIB) ../$(LIB)
	make clean

clean:
	rm $(LIB) *.o