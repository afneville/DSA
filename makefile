MKDIR   := mkdir
RMDIR   := rm -rf
CC      := gcc
BIN     := ./bin
OBJ     := ./obj
INCLUDE := ./include
SRC     := ./src
SRCS    := $(wildcard $(SRC)/*.c)
OBJS    := $(patsubst $(SRC)/%.c,$(OBJ)/%.o,$(SRCS))
EXEC    := $(BIN)/a.out
CFLAGS  := -I $(INCLUDE)
LDLIBS  := -lpthread

.PHONY: all run clean

all: $(EXEC)

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
