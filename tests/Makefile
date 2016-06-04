IDIR =../src
CC=gcc
CFLAGS=-I$(IDIR) -Wall -g3

ODIR=../src
LDIR =../src

LIBS=-lm

_DEPS = minunit.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = btree.o ../tests/main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -Wall -g3 -c -o $@ $< $(CFLAGS)

btree_tests: $(OBJ)
	gcc -Wall -g3 -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(LDIR)/*~

