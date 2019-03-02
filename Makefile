CC ?= gcc

.PHONY: all clean

all: stack linked_list

clean:
	make -C stack clean
	make -C linked_list clean

stack:
	make -C stack all

linked_list:
	make -C linked_list all

