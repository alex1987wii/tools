CFLAGS=
BINDIR=./bin
STRIP=strip
RMDIR=rmdir
SRC=$(wildcard ./src/*.c)
BIN=$(patsubst ./src/%.c,./bin/%,$(SRC))
all:$(BINDIR) $(BIN)

$(BINDIR):
	[ -d "./bin" ] || mkdir ./bin
	
./bin/%:./src/%.c
	$(CC) -o $@ $< $(CFLAGS)
	$(STRIP) $@
clean:
	$(RM) ./bin/*
.PHONY:all clean
