MKDIR   := mkdir
RMDIR   := rm -rf
CC      := g++
BIN     := ./bin
OBJ     := ./obj
INCLUDE := ./inc
SRC     := ./src
APP     := ./run
SRCS    := $(wildcard $(SRC)/*.cpp)
APPS    := $(wildcard $(APP)/*.cpp)
TESTS   := $(wildcard ./tests/*.cpp)
OBJS    := $(patsubst $(SRC)/%.cpp,$(OBJ)/%.o,$(SRCS))
PROGS   := $(patsubst $(APP)/%.cpp,$(BIN)/%,$(APPS))
CFLAGS  := -I $(INCLUDE)
LDLIBS  :=

.PHONY: all run clean build

build: $(PROGS)

$(OBJ)/%.o: $(SRC)/%.cpp | $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN)/%: $(APP)/%.cpp $(OBJS) | $(BIN)
	$(CC) $^ -o $@ $(LDLIBS)

$(BIN):
	$(MKDIR) $@

$(OBJ):
	$(MKDIR) $@

clean:
	$(RMDIR) $(OBJ) $(BIN)

lspconfig:
	bear -- make 2> /dev/null
