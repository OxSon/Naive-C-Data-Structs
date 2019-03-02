CC ?= gcc

.PHONY: all clean

ODIR = src/obj
OBJ = $(ODIR)/deque.o
OUT = out

EXECS = src/main.c

all: out/main

run:
	./out/main

clean:
	rm -rf $(OUT)/*
	rm -f *.o *.c *.h *.s
	rm -rf $(ODIR)/*

src/obj/deque.o: src/deque.c
	$(CC) -c -o $@ $<

out/main: $(OBJ) src/main.c
	$(CC) $^ -o $@
