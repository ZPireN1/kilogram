BDIR = bin
IDIR = include
ODIR = obj
SDIR = src

CC = gcc
CFLAGS = -Wall -I$(IDIR) -U _DEBUG_0 -U _DEBUG_1 -U _DEBUG_2 -U _DEBUG_3 -c
LDFLAGS = -lm

PROG = $(BDIR)/kilogram

_DEPS = elmlist.h list.h person.h friendship.h io.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = elmlist.o list.o person.o friendship.o io.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

.PHONY : run dirs clean delete

run : $(PROG)
	./$(PROG) ./data/person.dta ./data/friendship.dta
# ./$(PROG) $(P) $(F)

dirs :
	@mkdir -p bin
	@mkdir -p obj

$(PROG): dirs $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $(OBJ)

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(ODIR) $(SDIR)/*.*~ core $(IDIR)/*.*~

delete: clean
	rm -rf $(BDIR)