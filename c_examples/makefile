CC      := gcc
BIN     := ./bin
OBJ     := ./obj
INCLUDE := ./inc
SRC     := ./src
APP  := ./run
SRCS    := $(wildcard $(SRC)/*.c)
APPS    := $(wildcard $(APP)/*.c)
TESTS   := $(wildcard ./tests/*.c)
OBJS    := $(patsubst $(SRC)/%.c,$(OBJ)/%.o,$(SRCS))
PROGS   := $(patsubst $(APP)/%.c,$(BIN)/%,$(APPS))
CFLAGS  := -I $(INCLUDE)
LDLIBS  :=

.PHONY: all run clean build

build: $(PROGS)

$(OBJ)/%.o: $(SRC)/%.c | $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN)/%: $(APP)/%.c $(OBJS) | $(BIN)
	$(CC) $^ -o $@ $(LDLIBS)

$(BIN):
	mkdir $@

$(OBJ):
	mkdir $@

clean:
	rm -rf $(OBJ) $(BIN)

lspconfig:
	bear -- make 2> /dev/null
