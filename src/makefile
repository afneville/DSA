CC=gcc
CFLAGS=
LIBS=

IDIR=../includes
ODIR=./obj
_HEADS = linked_list.h map.h tree.h queue.h
_OBJ = main.o linked_list.o map.o tree.o queue.o

HEADS = $(patsubst %,$(IDIR)/%,$(_HEADS))
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

# *.o depends on the .c file of the same name
# '@' is the left of the colon, '<' is the first arg right of ':'
# '^' is the right side of the ':'

$(ODIR)/%.o: %.c $(IDIR)
	$(CC) -c -o $@ $<

a.out: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean
clean:
	rm -rf $(ODIR)/*.o
