SRCDIR=$(CURDIR)/src
INCDIR=$(CURDIR)/include
OBJDIR=$(CURDIR)/obj
BINDIR=$(CURDIR)/bin
SRC=$(wildcard $(SRCDIR)/*.c)
BIN=$(patsubst $(SRCDIR)/%.c,$(BINDIR)/%,$(SRC))
OBJ=$(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRC))

all:$(BIN)

$(MAKECMDGOALS):

.PHONY:all $(TARGET) clean
