CC=gcc
CFLAGS=-W -Wall -pedantic -g
LDFLAGS=
OUTDIR=build
EXEC=$(OUTDIR)/test
SRC= $(wildcard *.c) 						# => poly.c parser.c main.c
OBJ= $(patsubst %.c,$(OUTDIR)/%.o,$(SRC))	# => build/poly.o build/parser.o build/main.o

all: $(EXEC)

$(EXEC): $(OBJ) #build/poly.o build/parser.o build/main.o
	$(CC) -o $@ $^ $(LDFLAGS)

$(OUTDIR)/%.o: %.c
	@mkdir -p build
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf $(OUTDIR)/*.o

mrproper: clean
	rm -rf $(EXEC)
