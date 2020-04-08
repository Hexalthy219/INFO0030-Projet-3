### 
## Makefile
## INFO0030: Projet 2
## 
### 

## Variables

# Tools & flags
CC=gcc
CFLAGS=--std=c99 --pedantic -Wall -W -Wmissing-prototypes `pkg-config --cflags --libs gtk+-2.0`
LD=gcc
LDFLAGS=`pkg-config --cflags --libs gtk+-2.0`

# Files
EXEC=calculatrice
MODULES=main.c 
OBJECTS=main.o 

# Documentation
DOC= 

# Librairie

AR=ar
RANLIB=ranlib
LIBFILE=lib


## Rules

all: $(EXEC)

calculatrice: $(OBJECTS)
	$(LD) -o $(EXEC) $(OBJECTS) $(LDFLAGS)

main.o: main.c
	$(CC) -c main.c -o main.o $(CFLAGS)


doc:all_doc clean_latex

all_doc: $(DOC)
	doxygen $(DOC)
	mkdir -p doc
	mv html doc/html
	mv latex doc/latex

clean_latex:
	rm -r doc/latex/

clean_doc:
	rm -r doc

lib: libpnm.a
	mkdir -p lib
	mv libpnm.a lib/libpnm.a

libpnm.a:pnm.o
	$(AR) rv $@ $?
	$(RANLIB) $@

clean_lib:
	rm -r lib/

archive:
	tar -zcvf 

clean:
	rm -f *.o $(EXEC)

