all:part0

CFLAGS= -m32 -g -Wall  # -DDEBUG FLAGS

part0: count-words.c
	gcc $(CFLAGS) count-words.c -o part0

clean:
	rm -f part0