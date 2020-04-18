### 
## Makefile
## INFO0030: Projet 3
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
MODULES=main.c calculatrice.c 
OBJECTS=main.o calculatrice.o

# Documentation
DOC = calculatrice.c calculatrice.h main.c


## Rules

#compilation
all: $(EXEC)

calculatrice: $(OBJECTS)
	$(LD) -o $(EXEC) $(OBJECTS) $(LDFLAGS)

main.o: main.c
	$(CC) -c main.c -o main.o $(CFLAGS)

calculatrice.o: calculatrice.c
	$(CC) -c calculatrice.c -o calculatrice.o $(CFLAGS)


#compilation doc
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

#création archive
archive:
	tar -zcvf 

#supp fichiers objets + executable
clean:
	rm -f *.o $(EXEC)

