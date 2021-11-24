MKDIR   := mkdir
RMDIR   := rm -rf
CC      := gcc
BIN     := ./bin
OBJ     := ./obj
INCLUDE := ./include
SRC     := ./src
SRCS    := $(wildcard $(SRC)/*.c)
TESTS    := $(wildcard ./tests/*.c)
OBJS    := $(patsubst $(SRC)/%.c,$(OBJ)/%.o,$(SRCS))
EXEC    := $(BIN)/a.out
TEST    := $(BIN)/b.out
CFLAGS  := -I $(INCLUDE)
LDLIBS  := -lpthread

.PHONY: all run clean

build: $(EXEC)

$(EXEC): $(OBJS) | $(BIN)
	$(CC) $^ -o $@ $(LDLIBS)

$(OBJ)/%.o: $(SRC)/%.c | $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN):
	$(MKDIR) $@

$(OBJ):
	$(MKDIR) $@

run: $(EXEC)
	$<

clean:
	$(RMDIR) $(OBJ) $(BIN)

edit:
	nvim ./src/main.c

lspconfig:
	bear -- make 2> /dev/null

$(TEST): $(OBJS) | $(BIN)
	rm -rf $(OBJ)/main.o
	$(CC) $^ -o $@ $(LDLIBS)

