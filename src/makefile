CC=gcc
CFLAGS=
LIBS= -lpthread

IDIR=./includes
ODIR=./obj
_HEADS = object.h llist.h dict.h logger.h primes.h
_OBJ = logger.o main.o object.o llist.o dict.o primes.o

HEADS = $(patsubst %,$(IDIR)/%,$(_HEADS))
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

# *.o depends on the .c file of the same name
# '@' is the left of the colon, '<' is the first arg right of ':'
# '^' is the right side of the ':'

$(ODIR)/%.o: %.c $(IDIR)
	mkdir -p obj
	$(CC) -c -o $@ $<

a.out: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean
clean:
	rm -rf $(ODIR)/*.o a.out
