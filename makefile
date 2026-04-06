all:part0 part1

CFLAGS= -m32 -g -Wall  # -DDEBUG FLAGS

part0: count-words.c
	gcc $(CFLAGS) count-words.c -o part0

part1: addresses.c
	gcc $(CFLAGS) addresses.c -o part1
clean:
	rm -f part0, part1




	