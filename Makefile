CFLAGS=
STRIP=strip
RMDIR=rmdir
SRC=$(wildcard ./src/*.c)
BIN=$(patsubst ./src/%.c,./bin/%,$(SRC))
all:$(BIN)
	
./bin/%:./src/%.c
	$(CC) -o $@ $< $(CFLAGS)
	$(STRIP) $@
clean:
	$(RM) ./bin/*
.PHONY:all clean
